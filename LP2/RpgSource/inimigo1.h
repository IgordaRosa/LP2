#ifndef INIMIGO1_H
#define INIMIGO1_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Inimigo1: public QObject, public QGraphicsPixmapItem
{
 Q_OBJECT
public:
 Inimigo1();
public slots:
 void move();
};

#endif // INIMIGO1_H
