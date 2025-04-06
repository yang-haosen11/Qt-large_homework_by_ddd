#include "login.h"
#include "ui_login.h"
#include "menu.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("账本系统 - 登录");

}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "登录失败", "用户名或密码不能为空");
        return;
    }

    if (verifyUser(username, password)) {
        QMessageBox::information(this, "登录成功", "欢迎回来，" + username);
        // 登录成功后进入主界面的代码
        // 登录成功，隐藏登录界面，显示菜单界面
        this->hide();
        Menu *menuWindow = new Menu(this, username);
        menuWindow->show();

        // 连接退出登录信号到登录界面的显示槽
        connect(menuWindow, &Menu::logoutRequested, [=]() {
            menuWindow->close();
            this->show();
            ui->usernameLineEdit->clear();
            ui->passwordLineEdit->clear();
        });
    } else {
        QMessageBox::warning(this, "登录失败", "用户名或密码错误");
    }
}

void Login::on_registerButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "注册失败", "用户名或密码不能为空");
        return;
    }

    if (registerUser(username, password)) {
        QMessageBox::information(this, "注册成功", "用户 " + username + " 注册成功，请登录");
    } else {
        QMessageBox::warning(this, "注册失败", "用户名已存在");
    }
}

bool Login::verifyUser(const QString &username, const QString &password)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(":");
        if (parts.size() == 2 && parts[0] == username && parts[1] == hashPassword(password)) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool Login::registerUser(const QString &username, const QString &password)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(":");
        if (parts.size() == 2 && parts[0] == username) {
            file.close();
            return false;
        }
    }
    file.close();

    if (!file.open(QIODevice::Append | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << username << ":" << hashPassword(password) << "\n";
    file.close();

    return true;
}

QString Login::hashPassword(const QString &password)
{
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex();
}
