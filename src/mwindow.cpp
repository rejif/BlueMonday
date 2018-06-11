#include "mwindow.h"

MWindow::MWindow(QWidget *parent):QMainWindow(parent){
    setWindowTitle(tr("BlueMonday"));
    setWindowIcon(QIcon(":/bm.png"));
    resize(720,480);
}
MWindow::~MWindow(){}
