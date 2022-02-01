#include "inimigo2.h"

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
//#include <QDebug>
#include "game.h"
#include <QList>
#include "player.h"

extern Game * game;
Inimigo2::Inimigo2()
{
	if(game->timerf->getScore() > 0)
	{
 // posição
	setPos(1270,487);
	setPixmap(QPixmap(":/Recursos/icons/inimigo2.png"));
 //movimentação
	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(35);
	}
}

void Inimigo2::move()
{
	QList<QGraphicsItem *> colliding_item = collidingItems();
	for(int i = 0, n = colliding_item.size(); i < n; i++)
		{
	if(typeid(*(colliding_item[i]))== typeid(Player))
	{
		if(game->player->getLado() == 1)
		{
			game->GameOver();
		}
		else
		{
			if(game->hp->getHealth() -5 > 0)
			{
			game->hp->decrease();
			game->hp->decrease();
			game->hp->decrease();
			game->hp->decrease();
			game->hp->decrease();
			game->player->GetDamage();
			}
			else
			{
				game->GameOver();
			}
		}

		//scene()->removeItem(colliding_item[i]);
		scene()->removeItem(this);
		//delete colliding_item[i];
		delete this;
		return;
	}
	}
setPos(x()-20,y());
if(pos().x() <= 10)
	{
	scene()->removeItem(this);
	delete this;
	//qDebug()<<"Enemy removed";
	}
}
