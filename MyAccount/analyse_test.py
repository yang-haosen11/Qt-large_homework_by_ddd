import requests
import json
import time

API_URL = "https://api.coze.cn/v3/chat"
API_TOKEN = "api_token"#需要自己注册
BOT_ID = "7493171804693889051"#我自己创建的agent



def get_coze_response(user_message, timeout=30, poll_interval=1):
    """
    获取单次对话的完整回复
    :param api_token: API令牌
    :param bot_id: 机器人ID
    :param user_message: 用户消息
    :param timeout: 超时时间（秒）
    :param poll_interval: 轮询间隔（秒）
    :return: 智能体回复内容（字符串）
    """
    headers = {
        "Authorization": f"Bearer {API_TOKEN}",
        "Content-Type": "application/json"
    }

    try:
        # 1. 发起对话
        chat_response = requests.post(
            "https://api.coze.cn/v3/chat",
            headers=headers,
            json={
                "bot_id": BOT_ID,
                "user_id": "default_user",
                "additional_messages": [{
                    "role": "user",
                    "content": user_message,
                    "content_type": "text"
                }],
                "stream": False,
                "auto_save_history": True
            }
        )
        chat_response.raise_for_status()
        chat_data = chat_response.json()

        # 检查业务错误
        if chat_data.get("code") != 0:
            raise ValueError(f"API错误: {chat_data.get('msg', '未知错误')}")

        # 提取会话信息
        data = chat_data.get("data", {})
        chat_id = data.get("id")
        conversation_id = data.get("conversation_id")
        if not all([chat_id, conversation_id]):
            raise KeyError("响应缺少必要字段")

        # 2. 轮询对话状态
        start_time = time.time()
        while time.time() - start_time < timeout:
            # 查询对话状态
            status_response = requests.get(
                "https://api.coze.cn/v3/chat/retrieve",
                headers=headers,
                params={
                    "conversation_id": conversation_id,
                    "chat_id": chat_id
                }
            )
            status_data = status_response.json()

            if status_data.get("code") != 0:
                raise ValueError(f"状态查询失败: {status_data.get('msg')}")

            status = status_data.get("data", {}).get("status")

            if status == "completed":
                break
            elif status in ["failed", "canceled"]:
                raise Exception(f"对话异常终止: {status}")

            time.sleep(poll_interval)
        else:
            raise TimeoutError("对话处理超时")

        # 3. 获取最终回复
        msg_response = requests.get(
            "https://api.coze.cn/v3/chat/message/list",
            headers=headers,
            params={
                "conversation_id": conversation_id,
                "chat_id": chat_id
            }
        )
        msg_data = msg_response.json()

        if msg_data.get("code") != 0:
            raise ValueError(f"消息获取失败: {msg_data.get('msg')}")

        # 提取所有助手回复
        replies = [
            msg.get("content") for msg in msg_data.get("data", [])
            if msg.get("role") == "assistant" and msg.get("type") == "answer"
        ]

        return "\n".join(replies) if replies else "未收到有效回复"

    except requests.exceptions.RequestException as e:
        raise Exception(f"网络请求异常: {str(e)}") from e
    except Exception as e:
        raise Exception(f"处理失败: {str(e)}") from e


# 使用示例，用以debug
if __name__ == "__main__":
    try:
        response = get_coze_response(
            user_message="今天的天气如何？"
        )
        print("智能体回复：", response)
    except Exception as e:
        print("错误：", str(e))
