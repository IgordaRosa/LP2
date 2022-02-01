#ifndef SKILL2D_H
#define SKILL2D_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Skill2D: public QObject,public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Skill2D(QGraphicsItem * parent=0);
public slots:
	void move();
private:
};

#endif // SKILL2D_H
