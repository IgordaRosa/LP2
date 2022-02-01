#include "skill1d.h"

#include <QGraphicsScene>
#include <QTimer>
//#include <QDebug>
#include <QList>
#include "game.h"
#include "inimigo1.h"
#include "inimigo1d.h"
#include "bossf3.h"

// declaração da variavel do tipo extern
// indica que essa variavel já foi declarada em algum outro arquivo do projeto
	extern Game * game;

Skill1D::Skill1D(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
 // desenhar o tiro
	//setRect(0,0,10,50);
	 setPixmap(QPixmap(":/Recursos/Skills/skill1_2.png"));
 // conectar o timer com o movimento
	QTimer * timer = new QTimer();
	connect(timer,SIGNAL(timeout()),this,SLOT(move()));
 // inicializar o timer
	timer->start(50);
}

void Skill1D::move()
{
	// verificação de colisão:
	// se tiro atingiu o nimigo
	QList<QGraphicsItem *> colliding_item = collidingItems();
	for(int i = 0, n = colliding_item.size(); i < n; i++)
		{
	if(typeid(*(colliding_item[i]))== typeid(Inimigo1))
	{
		game->Din->increase();
		scene()->removeItem(colliding_item[i]);
		scene()->removeItem(this);
		delete colliding_item[i];
		delete this;
		return;
	}
	if(typeid(*(colliding_item[i]))== typeid(Inimigo1D))
	{
		game->Din->increase();
		scene()->removeItem(colliding_item[i]);
		scene()->removeItem(this);
		delete colliding_item[i];
		delete this;
		return;
	}
	if(typeid(*(colliding_item[i]))== typeid(Bossf3))
	{
		if(game->bosshp->getHealth() - 5 > 0)
		{
			game->boss->bossDMG();
			scene()->removeItem(this);
			delete this;
			game->bosshp->decrease();
			game->bosshp->decrease();
			game->bosshp->decrease();
			game->bosshp->decrease();
			game->bosshp->decrease();
			return;
		}
		else{
			game->defeatedBoss();
			scene()->removeItem(game->bosshp);
			delete game->bosshp;
			scene()->removeItem(colliding_item[i]);
			delete colliding_item[i];
			scene()->removeItem(this);
			delete this;

			return;
		}
	}
	}

 // movimentação do tiro
	setPos(x()-25,y()+3);
 if(pos().x() < -20 || pos().y() < -10)
	{
		scene()->removeItem(this);
		delete this;
		//qDebug()<<"Bullet removed";
	}
}
