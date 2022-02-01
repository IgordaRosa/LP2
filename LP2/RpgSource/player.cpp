#include "player.h"
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
//#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include "player.h"
#include "skill1.h"
#include "skill1d.h"
#include "game.h"
#include <QMultimedia>
#include "inimigo1.h"
#include "inimigo1d.h"
#include "inimigo2.h"
#include "inimigo2d.h"
#include "skill2.h"
#include "skill2d.h"

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
	setPixmap(QPixmap(":/Recursos/icons/mago2.png"));

	dmg = new QTimer();
}

void Player::keyPressEvent(QKeyEvent *event)
{
	//static size_t lado = 0;
	//mensagem informando que ocorreu uso do teclado
	if(event->key() == Qt::Key_Left && temp == 0)
	 {
	 // limite para não sair da tela
	 if(pos().x() > 0)
	 setPos(x()-10,y());
	 //movimento
	 setPixmap(QPixmap(":/Recursos/icons/mago.png"));
	 lado = 1;
	 }

	 if(event->key() == Qt::Key_Right && temp == 0)
	 {
	 // limite para não sair da tela

		 if(pos().x() + 100 < 1280 )
	 {
	 setPos(x()+10,y());
	 }

	 else if (game->timerf->getScore() <= 0)
	 {
		 game->setFase(1);
		 game->NextPhase();
	 }
	 //movimento
	 setPixmap(QPixmap(":/Recursos/icons/mago2.png"));
	 lado = 0;
	 }

	 if(event->key() == Qt::Key_Up && fasej == 0 && pos().x() >= 60 && pos().x() <= 1080)
	 {
		 jumptimer = new QTimer();
		 if(lado == 0)
		 {
		 connect(jumptimer, SIGNAL(timeout()), this, SLOT(JumpR()));
		 fasej = 1;
		 }
		 if(lado == 1)
		 {
		 connect(jumptimer, SIGNAL(timeout()), this, SLOT(JumpL()));
		 fasej++;
		 }
		 jumptimer->start(50);

	 }
	 /*if(event->key() == Qt::Key_Down)
	 {
	 setPos(x(),y()+10);
	 }*/
	 if(event->key() == Qt::Key_Q && lado == 0 && game->mana->getMana() >= 10 && game->cooldown->getCD() == 0)
	 {
		 //qDebug()<<"Bullet created";
		 Skill1 * bullet = new Skill1();
		 bullet->setPos(x() + 70,y());
		 scene()->addItem(bullet);
		 game->mana->attMana(10);
		 game->mana->reset();
		 game->cooldown->setCD(2);
		 game->cooldown->reset();
	 }
	 else if(event->key() == Qt::Key_Q && lado == 1 && game->mana->getMana() >= 10 && game->cooldown->getCD() == 0)
	 {
		 //qDebug()<<"Bullet created";
		 Skill1D * bullet2 = new Skill1D();
		 bullet2->setPos(x(),y());
		 scene()->addItem(bullet2);
		 game->mana->attMana(10);
		 game->mana->reset();
		 game->cooldown->setCD(2);
		 game->cooldown->reset();
	 }

	 if(event->key() == Qt::Key_W && lado == 0 && game->mana->getMana() >= 20 && game->cooldown2->getCD() == 0)
	 {
		 //qDebug()<<"Bullet created";
		 Skill2 * bullet3 = new Skill2();
		 bullet3 ->setPos(x() + 120,y()-55);
		 scene()->addItem(bullet3);
		 game->mana->attMana(20);
		 game->mana->reset();
		 game->cooldown2->setCD(5);
		 game->cooldown2->reset();
	 }
	 else if(event->key() == Qt::Key_W && lado == 1 && game->mana->getMana() >= 20 && game->cooldown2->getCD() == 0)
	 {
		 //qDebug()<<"Bullet created";
		 Skill2D * bullet4 = new Skill2D();
		 bullet4->setPos(x()-720,y()-55);
		 scene()->addItem(bullet4);
		 game->mana->attMana(20);
		 game->mana->reset();
		 game->cooldown2->setCD(5);
		 game->cooldown2->reset();
	 }

	 if(event->key() == Qt::Key_N && pos().x() < 635 && pos().x() > 615 && game->getFase() == 2)
	 {
			setPixmap(QPixmap(":/Recursos/icons/easteregg.png"));
			game->easterEGG();
	 }

}

void Player::Spawn()
{
	int random_number = rand() % 10;
	int random_number2 = rand() % 10;
	//if(game->getFase() == 1)
	//{
	//if(game->timerf->getScore() >= 0)
	if(random_number <=3)
	{
		Inimigo1 * enemy = new Inimigo1();
		scene()->addItem(enemy);
	}
	else if(random_number <= 6)
	{
		Inimigo1D * enemy = new Inimigo1D();
		scene()->addItem(enemy);
	}
	else if( game->getFase() == 3 && game->boss->getSkillCD() == 0)
	{
		game->boss->LancarSkill();
	}

	if(random_number2 <= 2)
	{
		Inimigo2 * enemy = new Inimigo2();
		scene()->addItem(enemy);
	}

	else if(random_number2 <= 4)
	{
		Inimigo2D * enemy = new Inimigo2D();
		scene()->addItem(enemy);
	}
	//}

}

void Player::Tempo()
{
	game->timerf->decrementar();
	game->cooldown->Cooldown();
	game->cooldown2->Cooldown();
	if(game->mana->getMana() +6 <= 100)
	{
		game->mana->recarga();
	}
	else if(game->mana->getMana() +5 == 100)
	{
		game->mana->setMana(100);
	}
	else if(game->mana->getMana() +4 == 100)
	{
		game->mana->setMana(100);
	}
	else if(game->mana->getMana() +3 == 100)
	{
		game->mana->setMana(100);
	}
	else if(game->mana->getMana() +2 == 100)
	{
		game->mana->setMana(100);
	}
	else if(game->mana->getMana() +1 == 100)
	{
		game->mana->setMana(100);
	}


}


void Player::JumpR()
{
	//setPos(x(),y()+10);
		if(fasej <= 4)
		{
			setPos(x()+10,y()-35);
			fasej++;
		}
		else if(fasej >= 5 && fasej <= 7)
		{
			fasej++;
		}
		else if(fasej >= 8 && fasej <= 11)
		{
			setPos(x()+10,y()+35);
			fasej++;
		}
		else
		{
			fasej = 0;
			jumptimer->stop();
		}

}

void Player::JumpL()
{
	//setPos(x(),y()+10);
		if(fasej <= 4)
		{
			setPos(x()-10,y()-35);
			fasej++;
		}
		else if(fasej >= 5 && fasej <= 7)
		{
			fasej++;
		}
		else if(fasej >= 8 && fasej <= 11)
		{
			setPos(x()-10,y()+35);
			fasej++;
		}
		else
		{
			fasej = 0;
			jumptimer->stop();
		}
}

int Player::getLado()
{
	return lado;
}

void Player::GetDamage()
{
	if(lado == 0)
	{
		setPixmap(QPixmap(":/Recursos/icons/mago2DMG.png"));
	}
	else if(lado == 1)
	{
		setPixmap(QPixmap(":/Recursos/icons/magoDMG.png"));
	}
	temp ++;
	connect(dmg, SIGNAL(timeout()), this, SLOT(DMG()));
	dmg->start(200);
}

void Player::DMG()
{
	if(lado == 0)
		{
			setPixmap(QPixmap(":/Recursos/icons/mago2.png"));
		}
	else if(lado == 1)
		{
			setPixmap(QPixmap(":/Recursos/icons/mago.png"));
		}
	temp = 0;
		dmg->stop();
}
