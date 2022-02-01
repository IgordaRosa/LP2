#ifndef RESETGAME_H
#define RESETGAME_H

#include <QDialog>
#include "game.h"
#include "mainwindow.h"

namespace Ui {
	class ResetGame;
}

class ResetGame : public QDialog
{
	Q_OBJECT

public:
	explicit ResetGame(QWidget *parent = nullptr);
	~ResetGame();

private slots:

	void on_pushButton_2_clicked();

private:
	Ui::ResetGame *ui;
};

#endif // RESETGAME_H
