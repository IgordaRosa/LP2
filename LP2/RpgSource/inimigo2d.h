#ifndef INIMIGO2D_H
#define INIMIGO2D_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Inimigo2D: public QObject, public QGraphicsPixmapItem
{
 Q_OBJECT
public:
 Inimigo2D();
public slots:
 void move();
};

#endif // INIMIGO2D_H
