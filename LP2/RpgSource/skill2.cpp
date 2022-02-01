#include "skill2.h"

#include <QGraphicsScene>
#include <QTimer>
//#include <QDebug>
#include "game.h"
#include <QList>
#include "inimigo1.h"
#include "inimigo1d.h"
#include "bossf3.h"

// declaração da variavel do tipo extern
// indica que essa variavel já foi declarada em algum outro arquivo do projeto
	extern Game * game;

Skill2::Skill2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
	 setPixmap(QPixmap(":/Recursos/Skills/skill2.png"));
 // conectar o timer com o movimento
	QTimer * timer = new QTimer();
	connect(timer,SIGNAL(timeout()),this,SLOT(move()));
 // inicializar o timer
	timer->start(500);
}

void Skill2::move()
{
	QList<QGraphicsItem *> colliding_item = collidingItems();
	for(int i = 0, n = colliding_item.size(); i < n; i++)
		{
	if(typeid(*(colliding_item[i]))== typeid(Inimigo1))
	{
		game->Din->increase();
		scene()->removeItem(colliding_item[i]);
		//scene()->removeItem(this);
		delete colliding_item[i];
		//delete this;

	}
	if(typeid(*(colliding_item[i]))== typeid(Inimigo1D))
	{
		game->Din->increase();
		scene()->removeItem(colliding_item[i]);
		//scene()->removeItem(this);
		delete colliding_item[i];
		//delete this;

	}
	if(typeid(*(colliding_item[i]))== typeid(Bossf3))
	{
		if(game->bosshp->getHealth() - 10 > 0)
		{
			game->boss->bossDMG();
			//scene()->removeItem(this);
			//delete this;
			for(size_t i = 0; i < 10; i++)
			{
				game->bosshp->decrease();
			}
		}
		else{
			game->defeatedBoss();
			scene()->removeItem(game->bosshp);
			delete game->bosshp;
			scene()->removeItem(colliding_item[i]);
			delete colliding_item[i];
			//scene()->removeItem(this);
			//delete this;

		}
	}
	}
 // movimentação do tiro
	//setPos(x()+25,y()+3);
		scene()->removeItem(this);
		delete this;
		//qDebug()<<"Bullet removed";
}


