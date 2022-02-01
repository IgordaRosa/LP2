#include "inimigo1d.h"

#include <QList>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
//#include <QDebug>
#include "game.h"

extern Game * game;
Inimigo1D::Inimigo1D()
{
	if(game->timerf->getScore() > 0)
	{
 // posição
	setPos(10,330);
	setPixmap(QPixmap(":/Recursos/icons/inimigo1D.png"));
 //movimentação
	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(35);
	}
}

void Inimigo1D::move()
{
	QList<QGraphicsItem *> colliding_item = collidingItems();
	for(int i = 0, n = colliding_item.size(); i < n; i++)
		{
	if(typeid(*(colliding_item[i]))== typeid(Player))
	{
		if(game->hp->getHealth() -2 > 0)
		{
			game->hp->decrease();
			game->hp->decrease();
			game->player->GetDamage();
		}
		else{
			game->GameOver();
		}
		//scene()->removeItem(colliding_item[i]);
		scene()->removeItem(this);
		//delete colliding_item[i];
		delete this;
		return;
	}
	}
setPos(x()+10,y());
if(pos().x() <= 10)
	{
	scene()->removeItem(this);
	delete this;
	//qDebug()<<"Enemy removed";
	}
}
