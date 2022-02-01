#include "bossf3.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "game.h"
#include <QList>
#include "player.h"
#include "bossskill.h"

#include "player.h"

extern Game * game;
Bossf3::Bossf3()
{
 // posição
	setPos(900,160);
	setPixmap(QPixmap(":/Recursos/icons/boss00.png"));
 //movimentação
	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(300);
}

void Bossf3::move()
{
	QList<QGraphicsItem *> colliding_item = collidingItems();
	for(int i = 0, n = colliding_item.size(); i < n; i++)
		{
	if(typeid(*(colliding_item[i]))== typeid(Player))
	{
		if(game->hp->getHealth() - 1 > 0)
		{
			game->player->GetDamage();
			game->hp->decrease();
			return;
		}
		else{
			game->GameOver();
			scene()->removeItem(colliding_item[i]);
			delete colliding_item[i];
			return;
		}
	}
	}
	if(sprint == 0 && temp == 0)
	{
		setPixmap(QPixmap(":/Recursos/icons/boss02.png"));
		sprint++;
	}
	else if(temp == 0)
	{
		setPixmap(QPixmap(":/Recursos/icons/boss00.png"));
		sprint = 0;
	}
}

void Bossf3::bossDMG()
{
	if(temp == 0)
	{
	setPixmap(QPixmap(":/Recursos/icons/bossDMG.png"));
	temp ++;
	DMG = new QTimer();
	connect(DMG, SIGNAL(timeout()), this, SLOT(BossDMG()));
	DMG->start(200);
	}
}

void Bossf3::BossDMG()
{
	setPixmap(QPixmap(":/Recursos/icons/boss00.png"));
	temp = 0;
	DMG->stop();
}

void Bossf3::LancarSkill()
{
	setPixmap(QPixmap(":/Recursos/icons/bossATK.png"));
	temp ++;
	skillCD ++ ;
	setPos(game->boss->x(), game->boss->y() -150);
	skill = new QTimer();
	connect(skill, SIGNAL(timeout()), this, SLOT(BossS()));
	skill->start(1500);
}

void Bossf3::BossS()
{
	if(temps == 0 && temp == 1)
	{
		setPos(game->boss->x(), game->boss->y() +150);
		setPixmap(QPixmap(":/Recursos/icons/boss00.png"));
		temps ++;
		temp = 0;
	}
	else if(posS <= 1200 && temps <= 11)
	{
		posS = rand() % 1150;
		BossSkill * skillb = new BossSkill();
		skillb->setPos(skillb->x() + posS, skillb->y());
		scene()->addItem(skillb);
		temps ++;
	}
	else
	{
		temps = 0;
		posS =0;
		skillCD = 0;
		skill->stop();
	}
}


int Bossf3::getSkillCD()
{
	return skillCD;
}
