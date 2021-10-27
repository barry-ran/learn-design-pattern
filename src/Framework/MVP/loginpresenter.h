#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QObject>

class ILoginView;
class LoginModel;
class LoginPresenter : public QObject
{
    Q_OBJECT
public:
    explicit LoginPresenter(ILoginView* view);
    ~LoginPresenter();

    void OnLoginBtnClick();
    void SetStateText(const QString& state);

private:
    ILoginView* m_view{nullptr};
    LoginModel* m_model{nullptr};
};

#endif // LOGINCONTROLLER_H
