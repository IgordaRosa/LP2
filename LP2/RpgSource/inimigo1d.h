#ifndef INIMIGO1D_H
#define INIMIGO1D_H
#include <QGraphicsPixmapItem>
#include <QObject>


class Inimigo1D: public QObject, public QGraphicsPixmapItem
{
 Q_OBJECT
public:
 Inimigo1D();
public slots:
 void move();
};


#endif // INIMIGO1D_H
