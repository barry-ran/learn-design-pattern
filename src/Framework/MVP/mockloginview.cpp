#include <QDebug>

#include "mockloginview.h"
#include "loginpresenter.h"

MockLoginView::MockLoginView()
{
    m_presenter = new LoginPresenter(this);
    m_presenter->OnLoginBtnClick();
}

QString MockLoginView::GetAccount() {
    return "123";
}

QString MockLoginView::GetPassword() {
    return "123";
}

QString MockLoginView::GetPhone() {
    return "12345678901";
}

QString MockLoginView::GetVerificationCode() {
    return "123";
}

bool MockLoginView::IsAccountLogin() {
    return true;
}

void MockLoginView::SetStateText(const QString& state) {
    qDebug() << "MockLoginView::SetStateText:" << state;
}
