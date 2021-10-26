#ifndef LOGINMODEL_H
#define LOGINMODEL_H

#include <QObject>

class LoginModel : public QObject
{
    Q_OBJECT
public:
    explicit LoginModel(QObject *parent = nullptr);

    void AccountLogin(const QString& account, const QString& password);
    void PhoneLogin(const QString& phone, const QString& verificationCode);

signals:
    void LoginState(const QString& state);
};

#endif // LOGINMODEL_H
