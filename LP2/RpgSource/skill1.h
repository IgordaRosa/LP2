#ifndef SKILL1_H
#define SKILL1_H

#include <QGraphicsPixmapItem>
#include <QObject>


class Skill1: public QObject,public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Skill1(QGraphicsItem * parent=0);
public slots:
	void move();
};


#endif // SKILL1_H
