#ifndef MVIEW_H
#define MVIEW_H

#include <QMessageBox>
#include <QList>
#include <QMenuBar>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QString>

class MView : public QGraphicsView{
public:
    explicit MView(QGraphicsScene *scene, QWidget *parent = nullptr):QGraphicsView(scene,parent){
        setStyleSheet("background: transparent");
        this->viewport()->setAutoFillBackground(false);
        this->loadImage(720,480,":/720x480.png");
        //this->loadImage(720,480,":/1528643601001.png");//1050x720
    }
    QImage image;
    QPixmap pixmap;
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem();
    void loadImage(int scaleX,int scaleY,QString path){
        if(!image.load(path)){
            QMessageBox::warning(0,"Warning","not found image");
            return;
        }
        pixmap.convertFromImage(image);
        if(scaleX!=0||scaleY!=0){
            pixmap = pixmap.scaled(scaleX,scaleY,Qt::KeepAspectRatio,Qt::FastTransformation);
        }
        pixmapItem->setPixmap(pixmap);
        resize(pixmap.width(),pixmap.height());
        this->update();
    }
public slots:
    void updateText(QString text){
        this->text=text;
    }
private:
    QString text="BMProject";
protected:
    void paintEvent(QPaintEvent *event){
        QGraphicsView::paintEvent(event);
        QPainter painter(viewport());
        painter.drawPixmap(0,0,pixmap);

        QFont font;
        font.setBold(true);
        font.setPixelSize(30);
        painter.setFont(font);
        painter.setPen(QPen(Qt::white));
        painter.drawText(painter.window(), Qt::AlignCenter, text);
    }
};

#endif // MVIEW_H
