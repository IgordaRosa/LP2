#include "timerfase.h"
#include <QFont>
#include "game.h"


extern Game * game;

TimerFase::TimerFase(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
	score = 50;
	setPlainText(QString("Timer: ") + QString::number(score));
	setDefaultTextColor(Qt::gray);
	setFont(QFont("times",25));

}
void TimerFase::segundo()
{
	if(score > 0)
	{
	score--;

	setPlainText(QString("Timer: ") + QString::number(score));
	setDefaultTextColor(Qt::gray);
	setFont(QFont("times",25));
	}
	else
	{
		game->timer->stop();
		if(game->getFase() == 3 && game->getDefeatBoss() == 0)
		{
			game->GameOver();
		}
	}
	if(score <= 0 && game->getFase() == 3 && game->getDefeatBoss() != 0)
	{
		game->gameover->YouWin();
		game->GameOver();
	}

}

void TimerFase::setScore(int newscore)
{
	score = newscore;
}

int TimerFase::getScore()
{
	return score;
}

void TimerFase::decrementar()
{
	this->segundo();
}
