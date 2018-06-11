#ifndef MWINDOW_H
#define MWINDOW_H

#include <QMainWindow>

class MWindow : public QMainWindow{
    Q_OBJECT
public:
    MWindow(QWidget *parent = 0);
    ~MWindow();
};

#endif // MWINDOW_H
