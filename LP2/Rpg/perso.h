#ifndef PERSO_H
#define PERSO_H

#include <QDialog>
#include "listadesave.h"

namespace Ui {
	class Perso;
}

void SaveDatabase(Char C, size_t id);

class Perso : public QDialog
{
	Q_OBJECT

public:
	explicit Perso(QWidget *parent = nullptr);
	~Perso();

	string cabelo = "";
	string cordocabelo = "";
	string nick = "";
	string cordapele = "";
	string genero = "";
	float altura = 0;
	size_t idclasse = 0;


private slots:
	void on_pushButton_clicked();

	void on_radioButton_7_clicked();

	void on_radioButton_8_clicked();

	void on_radioButton_9_clicked();

	void on_radioButton_12_clicked();

	void on_radioButton_clicked();

	void on_radioButton_3_clicked();

	void on_radioButton_2_clicked();

	void on_radioButton_4_clicked();

	void on_radioButton_5_clicked();

	void on_radioButton_6_clicked();

	void on_radioButton_10_clicked();

	void on_radioButton_11_clicked();

	void on_radioButton_13_clicked();

	void on_radioButton_14_clicked();

	void on_radioButton_15_clicked();

private:
	Ui::Perso *ui;

	//classes
	Classe *guerreiro = new Classe(75, 100, 50, 1.075, 1.1, 1.05);
	Classe *mago = new Classe(100, 75, 50, 1.1, 1.075, 1.05);
	Classe *arqueiro = new Classe(50, 75, 100, 1.05, 1.075, 1.1);
	Classe *assassino = new Classe(100, 50, 75, 1.1, 1.05, 1.075);
};

#endif // PERSO_H
