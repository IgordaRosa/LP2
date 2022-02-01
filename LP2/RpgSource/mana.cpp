#include "mana.h"
#include <QFont>

Mana::Mana(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
	mana = 100;
	setPlainText(QString("Mana: ") + QString::number(mana));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times",16));
}

void Mana::recarga()
{
	mana+=6;
	setPlainText(QString("Mana: ") + QString::number(mana));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times",16));
}

int Mana::getMana()
{
	return mana;
}

void Mana::attMana(int redu)
{
	mana -= redu;
}

void Mana::setMana(int set)
{
	mana = set;
	setPlainText(QString("Mana: ") + QString::number(mana));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times",16));
}

void Mana::reset()
{
	setPlainText(QString("Mana: ") + QString::number(mana));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times",16));
}
