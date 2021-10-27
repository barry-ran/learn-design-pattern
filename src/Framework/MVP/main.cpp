#include <QApplication>

#include "loginview.h"
#include "mockloginview.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    LoginView view;
    view.show();

    // 用于单元测试Presenter
    MockLoginView mockLoginView;
    return a.exec();
}
