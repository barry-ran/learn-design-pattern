#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginView; }
QT_END_NAMESPACE

class LoginController;
class LoginView : public QWidget
{
    Q_OBJECT

public:
    LoginView(QWidget *parent = nullptr);
    ~LoginView();

    QString GetAccount();
    QString GetPassword();
    QString GetPhone();
    QString GetVerificationCode();
    bool IsAccountLogin();
    void SetStateText(const QString& state);

private slots:
    void on_loginBtn_clicked();

private:
    Ui::LoginView *ui;
    LoginController* m_controller;
};
#endif // LOGINVIEW_H
