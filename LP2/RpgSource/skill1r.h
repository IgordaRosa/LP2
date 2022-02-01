#ifndef SKILL1R_H
#define SKILL1R_H
#include <QGraphicsTextItem>

class Skill1R: public QGraphicsTextItem
{
	public:
	Skill1R(QGraphicsItem *parent = 0);
		int getCD();
		void setCD(int newcd);
		void Cooldown();
		void reset();

	public slots:
		//void decrementar();

	private:
		int cd;

};
#endif // SKILL1R_H
