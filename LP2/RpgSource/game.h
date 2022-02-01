#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "inimigo1.h"
#include "timerfase.h"
#include "score.h"
#include <QTimer>
#include "hp.h"
#include "mana.h"
#include "skill1r.h"
#include "skill2r.h"
#include "gameover.h"
#include "bossf3.h"


class Game : public QGraphicsView
{
public:
	Game(QWidget * parent=0);
	QGraphicsScene * scene;
	Player * player;
	//Inimigo1 * inim1;
	TimerFase * timerf;
	Score * Din;
	QTimer * timer;
	QTimer * timerC;
	HP * hp;
	Mana *mana;
	Skill1R * cooldown;
	Skill2R * cooldown2;
	Gameover * gameover;
	Bossf3 * boss;
	HP * bosshp;
	QMediaPlaylist * playlist;
	QMediaPlayer * music;

	void NextPhase();
	void GameOver();
	int getFase();
	void setFase(int newfase);
	int getDefeatBoss();
	void defeatedBoss();
	void easterEGG();

private:
	int fase;
	int defeatboss = 0;
	int easteregg=0;

public slots:
	void SpawnInimigos();
};

#endif // GAME_H
