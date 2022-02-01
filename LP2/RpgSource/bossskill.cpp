#include "bossskill.h"

#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include "game.h"
#include <QList>
#include "player.h"

// declaração da variavel do tipo extern
// indica que essa variavel já foi declarada em algum outro arquivo do projeto
	extern Game * game;

BossSkill::BossSkill(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
 // desenhar o tiro
	//setRect(0,0,10,50);
	 setPixmap(QPixmap(":/Recursos/Skills/Bossskill.png"));
 // conectar o timer com o movimento
	QTimer * timer = new QTimer();
	connect(timer,SIGNAL(timeout()),this,SLOT(move()));
 // inicializar o timer
	timer->start(50);
}

void BossSkill::move()
{
	// verificação de colisão:
	// se tiro atingiu o nimigo
	QList<QGraphicsItem *> colliding_item = collidingItems();
	for(int i = 0, n = colliding_item.size(); i < n; i++)
		{
	if(typeid(*(colliding_item[i]))== typeid(Player))
	{
		if(game->hp->getHealth() - 2 > 0)
		{
			game->player->GetDamage();
			scene()->removeItem(this);
			delete this;
			game->hp->decrease();
			game->hp->decrease();
			return;
		}
		else{
			game->GameOver();
			scene()->removeItem(colliding_item[i]);
			delete colliding_item[i];
			scene()->removeItem(this);
			delete this;

			return;
		}
	}
	}

 // movimentação do tiro
	setPos(x(),y()+35);
 if(pos().y() < -10)
	{
		scene()->removeItem(this);
		delete this;
		qDebug()<<"Bullet removed";
	}
}


