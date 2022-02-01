#ifndef SKILL2_H
#define SKILL2_H
#include <QGraphicsPixmapItem>
#include <QObject>


class Skill2: public QObject,public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Skill2(QGraphicsItem * parent=0);
public slots:
	void move();
private:
};


#endif // SKILL2_H
