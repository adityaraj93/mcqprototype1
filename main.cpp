#include "loginwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
   // a.setQuitOnLastWindowClosed(false);
    return a.exec();
}
