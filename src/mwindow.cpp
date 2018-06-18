#include "mwindow.h"

MWindow::MWindow(QWidget *parent):QMainWindow(parent){
    setWindowTitle(tr("BlueMonday"));
    setWindowIcon(QIcon(":/bm.png"));

    setMaximumWidth(800);
    setMaximumHeight(600);
    QSize viewSize(720,480);
    resize(this->maximumWidth(),this->maximumHeight());

    Glass *cw = new Glass();
    setCentralWidget(cw);
    QHBoxLayout *hl = Slib::createHBoxLayout();
    cw->setLayout(hl);
    QVBoxLayout *vl = Slib::createVBoxLayout();
    hl->addLayout(vl);


    QGraphicsScene *scene = new QGraphicsScene(QRect(0, 0,viewSize.width(),viewSize.height()));
    mview = new MView(scene);
    mview->setMinimumSize(viewSize);
    mview->setMaximumSize(viewSize);
    mview->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    mview->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    mview->show();

    MRect *mrect = new MRect(100,100,viewSize.width()-1-200,viewSize.height()-1-200);//-1=ForPen
    QObject::connect(mrect,SIGNAL(nextReq()),this,SLOT(next()));
    mrect->setPen(QPen(Qt::white));
    mrect->setBrush(Qt::gray);
    scene->addItem(mrect);

    vl->addWidget(mview);

    connect(this,&QWidget::destroyed,[=](){qApp->quit();});

}
MWindow::~MWindow(){}
