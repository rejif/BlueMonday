#ifndef SLIB_H
#define SLIB_H

#include <QObject>
#include <QDateTime>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Slib : public QObject{
    Q_OBJECT
public:
    static QString now(){
        return QDateTime::currentDateTime().toString("yyyy/MM/dd-hh:mm:ss.zzz");
    }
    static QVBoxLayout* createVBoxLayout(){
        QVBoxLayout *vl = new QVBoxLayout;
        vl->setSpacing(0);
        vl->setMargin(0);
        return vl;
    }
    static QHBoxLayout* createHBoxLayout(){
        QHBoxLayout *hl = new QHBoxLayout;
        hl->setSpacing(0);
        hl->setMargin(0);
        return hl;
    }

};

#endif // SLIB_H
