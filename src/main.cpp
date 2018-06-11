#include "mwindow.h"
#include <QApplication>
#include <QDesktopWidget>
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QRect aa(QApplication::desktop()->availableGeometry());
    MWindow mw;
    mw.show();
    mw.move(aa.width()/2-mw.width()/2,aa.height()/2-mw.height()/2);
    return app.exec();
}
