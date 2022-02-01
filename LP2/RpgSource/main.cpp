#include "mainwindow.h"

#include <QApplication>
#include "game.h"

Game * game; // variavel global, que pode ser acessada
MainWindow * Main;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//MainWindow w;
	//w.show();
	Main = new MainWindow();
	Main->show();
	return a.exec();
}
