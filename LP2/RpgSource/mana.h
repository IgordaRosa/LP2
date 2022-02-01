#ifndef MANA_H
#define MANA_H
#include <QGraphicsTextItem>

class Mana: public QGraphicsTextItem
{
	public:
		Mana(QGraphicsItem *parent = 0);
		void recarga();
		int getMana();
		void attMana(int redu);
		void setMana(int set);
		void reset();
	private:
		int mana;
};

#endif // MANA_H
