#include "hp.h"
#include <QFont>

HP::HP(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
	health = 1;
	setPlainText(QString("Health: ") + QString::number(health));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times",16));
}
void HP::decrease()
{
	health--;
	setPlainText(QString("Health: ") + QString::number(health));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times",16));
}
int HP::getHealth()
{
	return health;
}

void HP::setHP(int hp)
{
	health = hp;
	setPlainText(QString("Health: ") + QString::number(health));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times",16));
}
