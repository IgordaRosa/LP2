#include "game.h"
#include <QGraphicsTextItem>
#include <QImage>
#include <QBrush>
#include "score.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "resetgame.h"

Game::Game(QWidget *parent)
{
	// criar scene
	 scene = new QGraphicsScene();
	 scene->setSceneRect(0,0,1280,720);
	 scene->setBackgroundBrush(QBrush(QImage(":/Recursos/Fase1.jpg")));
	 scene->setFocusOnTouch(false);
	 // visualizar o objeto scene (cenario)
	 setScene(scene);
	 //desabilitar as barras de rolagem
	 setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	 setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	 // fixar o tamanho
	 setFixedSize(1280,720);

	 // criar o jogador
	 player = new Player();
	 player->setPos(500,330);
	 player->setFlag(QGraphicsItem::ItemIsFocusable);
	 scene->addItem(player);
	 player->setFocus();

	 //inimigo
	 timer = new QTimer();
	 QObject::connect(timer,SIGNAL(timeout()), player ,SLOT(Spawn()));
	 timer->start(2000);

	 //timer corrente
	 timerC = new QTimer();
	 QObject::connect(timerC,SIGNAL(timeout()), player ,SLOT(Tempo()));
	 timerC->start(1000);

	 //Dinheiro
	 Din = new Score();
	 scene->addItem(Din);
	 Din->setPos(Din->x()+1050, Din->y()+75);

	 //hp
	 hp = new HP();
	 hp->setPos(hp->x(), hp->y()+25);
	 hp->setHP(50);
	 scene->addItem(hp);

	 //mana
	 mana = new Mana();
	 mana->setPos(mana->x(), mana->y()+65);
	 scene->addItem(mana);
	 mana->setMana(100);

	//timer;
	 timerf = new TimerFase();
	 timerf->setScore(61);
	 timerf->decrementar();
	 scene->addItem(timerf);
	 timerf->setPos(timerf->x()+1050, timerf->y()+25);

	 //Cooldown skill1
	cooldown = new Skill1R();
	cooldown->setPos(cooldown->x(), cooldown->y()+105);
	scene->addItem(cooldown);

	//Cooldown skill2
	cooldown2 = new Skill2R();
	cooldown2->setPos(cooldown2->x(), cooldown2->y()+145);
	scene->addItem(cooldown2);

	//Gameover
	gameover = new Gameover();

	// fase
	fase = 1;

	//musicas free use obtidas através do YouTube
	 playlist = new QMediaPlaylist();
	 playlist->addMedia(QUrl("qrc:/Recursos/Sounds/fase1_2.mp3"));
	 playlist->setPlaybackMode(QMediaPlaylist::Loop);
	 music = new QMediaPlayer(this);
	 music->setPlaylist(playlist);
	 music->setVolume(5);
	 music->play();

	 show();
}

void Game::NextPhase()
{
	if(fase == 2)
	{
		player->setPos(0,330);
		scene->setBackgroundBrush(QBrush(QImage(":/Recursos/Fase2.jpg")));
		mana->setMana(100);
		timerf->setScore(61);
		timerf->decrementar();
		timer->start(1750);
	}

	else if(fase == 3){
		music->stop();
		if(easteregg == 0)
		{
			music->setMedia(QUrl("qrc:/Recursos/Sounds/fase3.mp3"));
			music->setVolume(5);
			music->play();
		}
		else
		{
			music->setMedia(QUrl("qrc:/Recursos/Sounds/easteregg.mp3"));
			music->setVolume(5);
			music->play();
		}
		scene->setBackgroundBrush(QBrush(QImage(":/Recursos/fase3easteregg.jpg")));
		music->play();
		timerf->setScore(231);
		timerf->decrementar();
		timer->start(2250);
		player->setPos(0,330);
		mana->setMana(100);
		boss = new Bossf3();
		scene->addItem(boss);
		bosshp= new HP();
		bosshp->setPos(boss->x() +175, boss->y()+0);
		bosshp->setHP(500);
		scene->addItem(bosshp);
	}

}

void Game::GameOver()
{
	scene->removeItem(player);
	delete player;
	gameover->setPos(215, 250);
	scene->addItem(gameover);
	ResetGame mDialog;
	mDialog.setModal(true);
	mDialog.exec();
}

int Game::getFase()
{
	return fase;
}

void Game::setFase(int newfase)
{
	fase += newfase;
}


int Game::getDefeatBoss()
{
	return defeatboss;
}

void Game::defeatedBoss()
{
	defeatboss ++;
}

void Game::easterEGG()
{
	easteregg ++ ;
}

