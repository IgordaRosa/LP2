#ifndef HP_H
#define HP_H


#include <QGraphicsTextItem>
class HP: public QGraphicsTextItem
{
public:
	HP(QGraphicsItem *parent = 0);
	void decrease();
	int getHealth();
	void setHP(int hp);
private:
	int health;
};

#endif // HP_H
