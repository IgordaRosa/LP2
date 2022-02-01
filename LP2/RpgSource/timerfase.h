#ifndef TIMERFASE_H
#define TIMERFASE_H


#include <QGraphicsTextItem>

class TimerFase: public QGraphicsTextItem
{
public:
	TimerFase(QGraphicsItem *parent = 0);
	int getScore();
	void setScore(int newscore);
	void segundo();

public slots:
	void decrementar();

private:
	int score;
	int protecao;


};
#endif // TIMERFASE_H
