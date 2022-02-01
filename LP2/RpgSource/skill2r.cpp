#include "skill2r.h"
#include <QFont>

Skill2R::Skill2R(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
	cd = 0;
	setPlainText(QString("W ") + QString::number(cd));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times",16));
}
void Skill2R::Cooldown()
{
	if(cd > 0)
	{
	cd--;
	setPlainText(QString("W ") + QString::number(cd));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times",16));
	}
}
int Skill2R::getCD()
{
	return cd;
}

void Skill2R::setCD(int newcd)
{
	cd = newcd;
}

void Skill2R::reset()
{
	setPlainText(QString("W ") + QString::number(cd));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times",16));
}
