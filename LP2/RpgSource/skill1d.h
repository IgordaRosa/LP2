#ifndef SKILL1D_H
#define SKILL1D_H


#include <QGraphicsPixmapItem>
#include <QObject>


class Skill1D: public QObject,public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Skill1D(QGraphicsItem * parent=0);
public slots:
	void move();
};


#endif // SKILL1D_H
