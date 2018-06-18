#ifndef MRECT_H
#define MRECT_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class MRect : public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    explicit MRect(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = Q_NULLPTR):QGraphicsRectItem(x, y, width, height, parent){}
signals:
    void nextReq();
    void textReq(QString);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event){
        emit nextReq();
        QGraphicsRectItem::mouseMoveEvent(event);
    }
};


#endif // RECT_H
