#include "loginmodel.h"

LoginModel::LoginModel(QObject *parent) : QObject(parent)
{

}

void LoginModel::AccountLogin(const QString& account, const QString& password) {
    if (account.isEmpty() || password.isEmpty()) {
        emit LoginState("account or password is empty");
        return;
    }

    if (account == "123" && password == "123") {
        emit LoginState("login success");
        return;
    }

    emit LoginState("login failed");
    return;
}

void LoginModel::PhoneLogin(const QString& phone, const QString& verificationCode) {
    if (phone.isEmpty() || verificationCode.isEmpty()) {
        emit LoginState("phone or verification code is empty");
        return;
    }

    if (phone.size() != 11) {
        emit LoginState("phone is wrong");
        return;
    }

    emit LoginState("login failed");
    return;
}
