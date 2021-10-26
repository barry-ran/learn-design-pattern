#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QObject>

class LoginView;
class LoginModel;
class LoginController : public QObject
{
    Q_OBJECT
public:
    explicit LoginController(LoginView* view);
    ~LoginController();

    void OnLoginBtnClick();

private:
    LoginView* m_view{nullptr};
    LoginModel* m_model{nullptr};
};

#endif // LOGINCONTROLLER_H
