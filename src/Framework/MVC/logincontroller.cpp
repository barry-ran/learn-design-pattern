#include "logincontroller.h"
#include "loginview.h"
#include "loginmodel.h"

LoginController::LoginController(LoginView* view)
    : QObject(nullptr)
    , m_view(view)
    , m_model(new LoginModel(this))
{
    // 关联model和view，这里也可以用观察者实现
    connect(m_model, &LoginModel::LoginState, m_view, &LoginView::SetStateText);
}

LoginController::~LoginController()
{
    delete m_model;
    m_model = nullptr;
}

void LoginController::OnLoginBtnClick() {
    if (m_view->IsAccountLogin()) {
        m_model->AccountLogin(m_view->GetAccount(), m_view->GetPassword());
    } else {
        m_model->PhoneLogin(m_view->GetPhone(), m_view->GetVerificationCode());
    }
}
