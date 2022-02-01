#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Player(QGraphicsItem * parent=0);
	void keyPressEvent(QKeyEvent * event);

	QTimer * jumptimer;
	QTimer * dmg;

	int getLado();
	void GetDamage();

public slots:
	void Spawn();
	void Tempo();
	void JumpR();
	void JumpL();
	void DMG();

private:
 //QMediaPlayer * bulletsound;
	int fasej = 0;
	int lado = 0;
	int temp = 0;
};


#endif // PLAYER_H
