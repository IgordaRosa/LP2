#include "resetgame.h"
#include "ui_resetgame.h"
#include "opt.h"

extern Game * game;
extern MainWindow * Main;

ResetGame::ResetGame(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ResetGame)
{
	ui->setupUi(this);
}

ResetGame::~ResetGame()
{
	delete ui;
}

void ResetGame::on_pushButton_2_clicked()
{
	game->close();
	delete game;
	Main->show();
	close();
}

