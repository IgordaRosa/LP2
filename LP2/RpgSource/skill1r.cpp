#include "skill1r.h"
#include <QFont>

Skill1R::Skill1R(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
	cd = 0;
	setPlainText(QString("Q ") + QString::number(cd));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times",16));
}
void Skill1R::Cooldown()
{
	if(cd > 0)
	{
	cd--;
	setPlainText(QString("Q ") + QString::number(cd));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times",16));
	}
}
int Skill1R::getCD()
{
	return cd;
}

void Skill1R::setCD(int newcd)
{
	cd = newcd;
}

void Skill1R::reset()
{
	setPlainText(QString("Q ") + QString::number(cd));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times",16));
}
