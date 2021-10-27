#ifndef MOCKLOGINVIEW_H
#define MOCKLOGINVIEW_H
#include "ILoginView.h"

class LoginPresenter;
class MockLoginView : public ILoginView
{
public:
    MockLoginView();

    QString GetAccount() override;
    QString GetPassword() override;
    QString GetPhone() override;
    QString GetVerificationCode() override;
    bool IsAccountLogin() override;
    void SetStateText(const QString& state) override;

private:
    LoginPresenter* m_presenter;
};

#endif // MOCKLOGINVIEW_H
