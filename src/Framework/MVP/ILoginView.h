#ifndef ILOGINVIEW_H
#define ILOGINVIEW_H
#include <QObject>

class ILoginView {
    public:
    virtual QString GetAccount() = 0;
    virtual QString GetPassword() = 0;
    virtual QString GetPhone() = 0;
    virtual QString GetVerificationCode() = 0;
    virtual bool IsAccountLogin() = 0;
    virtual void SetStateText(const QString& state) = 0;
};
#endif // ILOGINVIEW_H
