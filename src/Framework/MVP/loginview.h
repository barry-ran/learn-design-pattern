#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include "ILoginView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginView; }
QT_END_NAMESPACE

class LoginPresenter;
class LoginView : public QWidget, public ILoginView
{
    Q_OBJECT

public:
    LoginView(QWidget *parent = nullptr);
    ~LoginView();

    QString GetAccount() override;
    QString GetPassword() override;
    QString GetPhone() override;
    QString GetVerificationCode() override;
    bool IsAccountLogin() override;
    void SetStateText(const QString& state) override;

private slots:
    void on_loginBtn_clicked();

private:
    Ui::LoginView *ui;
    LoginPresenter* m_presenter;
};
#endif // LOGINVIEW_H
