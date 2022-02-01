#include "gameover.h"
#include <QFont>

Gameover::Gameover(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
	setPlainText(QString("GAME OVER!!!"));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times",100));
}

void Gameover::YouWin()
{
	setPlainText(QString("Você Ganhou!"));
	setDefaultTextColor(Qt::green);
	setFont(QFont("times",100));
}
