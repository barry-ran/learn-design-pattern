#include "loginpresenter.h"
#include "loginview.h"
#include "loginmodel.h"

LoginPresenter::LoginPresenter(ILoginView* view)
    : QObject(nullptr)
    , m_view(view)
    , m_model(new LoginModel(this))
{
    // model只和presenter通信
    connect(m_model, &LoginModel::LoginState, this, &LoginPresenter::SetStateText);
}

LoginPresenter::~LoginPresenter()
{
    delete m_model;
    m_model = nullptr;
}

void LoginPresenter::OnLoginBtnClick() {
    if (m_view->IsAccountLogin()) {
        m_model->AccountLogin(m_view->GetAccount(), m_view->GetPassword());
    } else {
        m_model->PhoneLogin(m_view->GetPhone(), m_view->GetVerificationCode());
    }
}

void LoginPresenter::SetStateText(const QString& state) {
    m_view->SetStateText(state);
}
