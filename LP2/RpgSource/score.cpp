#include "score.h"

#include <QFont>
Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
	score = 0;
	setPlainText(QString("Dinheiro: ") + QString::number(score));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times",25));
}
void Score::increase()
{
	score+= 7;
	setPlainText(QString("Dinheiro: ") + QString::number(score));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times",25));
}
int Score::getScore()
{
	return score;
}
