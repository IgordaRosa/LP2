#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QGraphicsTextItem>

class Gameover: public QGraphicsTextItem
		{
		public:
			Gameover(QGraphicsItem *parent = 0);
			void YouWin();

		private:

		};

#endif // GAMEOVER_H
