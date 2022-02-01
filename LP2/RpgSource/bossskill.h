#ifndef BOSSSKILL_H
#define BOSSSKILL_H
#include <QGraphicsPixmapItem>
#include <QObject>

class BossSkill: public QObject,public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	BossSkill(QGraphicsItem * parent=0);
public slots:
	void move();
};

#endif // BOSSSKILL_H
