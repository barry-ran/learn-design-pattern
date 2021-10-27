#include "loginview.h"
#include "./ui_loginview.h"
#include "loginpresenter.h"

LoginView::LoginView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginView)
{
    ui->setupUi(this);
    m_presenter = new LoginPresenter(this);
}

LoginView::~LoginView()
{
    delete m_presenter;
    m_presenter = nullptr;
    delete ui;
}

QString LoginView::GetAccount() {
    return ui->accountEdt->text();
}

QString LoginView::GetPassword() {
    return ui->passwordEdt->text();
}

QString LoginView::GetPhone() {
    return ui->phoneEdt->text();
}

QString LoginView::GetVerificationCode() {
    return ui->VerificationCodeEdt->text();
}

bool LoginView::IsAccountLogin() {
    return ui->contentTabWidget->currentIndex() == 0;
}

void LoginView::SetStateText(const QString& state) {
    ui->stateLab->setText(state);
}

void LoginView::on_loginBtn_clicked()
{
    m_presenter->OnLoginBtnClick();
}
