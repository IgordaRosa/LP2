#ifndef INIMIGO2_H
#define INIMIGO2_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Inimigo2: public QObject, public QGraphicsPixmapItem
{
 Q_OBJECT
public:
 Inimigo2();
public slots:
 void move();
};

#endif // INIMIGO2_H
