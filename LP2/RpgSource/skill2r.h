#ifndef SKILL2R_H
#define SKILL2R_H
#include <QGraphicsTextItem>

class Skill2R: public QGraphicsTextItem
{
	public:
	Skill2R(QGraphicsItem *parent = 0);
		int getCD();
		void setCD(int newcd);
		void Cooldown();
		void reset();

	public slots:
		//void decrementar();

	private:
		int cd;

};

#endif // SKILL2R_H
