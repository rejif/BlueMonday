#ifndef MWINDOW_H
#define MWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "glass.h"
#include "slib.h"
#include "mview.h"
#include "mrect.h"

class MWindow : public QMainWindow{
    Q_OBJECT
public:
    MWindow(QWidget *parent = 0);
    ~MWindow();
public slots:
    void next(){
        mview->updateText(QString("Request@%1").arg(Slib::now()));
        mview->update();
    }
private:
    MView *mview;
};

#endif // MWINDOW_H
