#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    QString user_name;

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::Login *ui;
    bool verifyUser(const QString &username, const QString &password);
    bool registerUser(const QString &username, const QString &password);
    QString hashPassword(const QString &password);
};
#endif // LOGIN_H
