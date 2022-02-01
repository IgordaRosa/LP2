#include "perso.h"
#include "ui_perso.h"

#include <QMessageBox>

void SaveDatabase(Char C, size_t id)
{
	vector<string> dat;
	ifstream temp;
	temp.open("saves.dat");

	size_t aux = 0;
	string str;
	while(getline(temp, str))
	{
		if(aux != 0){
			dat.push_back(str);
		}
		aux++;
	}
	temp.close();

	ofstream database("saves.dat");
	database << "0" << endl;
	for(size_t i=0; i < dat.size(); i++)
	{
		database << dat.at(i) << endl;
	}
	database << C.GetCharName() << ".dat" << endl;
	database.close();

	//Escrever no save do personagem
	ofstream Chardat;
	Chardat.open(C.GetCharName() + ".dat");

	Chardat << C.GetCharName() << endl;
	Chardat << C.GetCharAltura() << endl;
	Chardat << C.GetCharCpele() << endl;
	Chardat << C.GetCharCabelo() << endl;
	Chardat << C.GetCharCcabelo() << endl;
	Chardat << C.GetCharGenero() << endl;
	Chardat << C.GetCharLevel() << endl;
	Chardat << C.GetCharDin() << endl;
	Chardat << id << endl;
	Chardat.close();
}


Perso::Perso(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Perso)
{
	ui->setupUi(this);

	QPixmap pix(":/elementos/Perso.png");
	 int w = ui->fundoperso->width();
	 int h = ui->fundoperso->height();
	 //ui->label_picture->setPixmap(pix);
	 ui->fundoperso->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

	 QPixmap pixatk(":/icons/atk.png");
	  int atkw = ui->icoatk->width();
	  int atkh = ui->icoatk->height();
	  //ui->label_picture->setPixmap(pix);
	  ui->icoatk->setPixmap(pixatk.scaled(atkw,atkh,Qt::KeepAspectRatio));

	  QPixmap pixdef(":/icons/def.png");
	   int defw = ui->icodef->width();
	   int defh = ui->icodef->height();
	   //ui->label_picture->setPixmap(pix);
	   ui->icodef->setPixmap(pixdef.scaled(defw,defh,Qt::KeepAspectRatio));

	   QPixmap pixvel(":/icons/vel.png");
		int velw = ui->icovel->width();
		int velh = ui->icovel->height();
		//ui->label_picture->setPixmap(pix);
		ui->icovel->setPixmap(pixvel.scaled(velw,velh,Qt::KeepAspectRatio));
}

Perso::~Perso()
{
	delete ui;
	delete guerreiro;
	delete mago;
	delete arqueiro;
	delete assassino;
}

void Perso::on_pushButton_clicked()
{
	if(ui->lineEdit->text() != ""&& cabelo != "" && cordocabelo != "" && genero != "" && cordapele != "" && idclasse !=0){
		QString aux = ui->lineEdit->text();
		nick = aux.toStdString();
		altura = ui->Altura->value();
		Personagem *PER = new Personagem(nick, altura, cordapele, cabelo, cordocabelo, genero);

		//Classe selecionada(id)
		if(idclasse == 1)
		{
			Char CHAR(PER, guerreiro);
			SaveDatabase(CHAR, idclasse);
		}
		if(idclasse == 2)
		{
			Char CHAR(PER, mago);
			SaveDatabase(CHAR, idclasse);
		}
		if(idclasse == 3){
			Char CHAR(PER, arqueiro);
			SaveDatabase(CHAR, idclasse);
		}
		if(idclasse == 4)
		{
			Char CHAR(PER, assassino,4);
			SaveDatabase(CHAR, idclasse);
		}


		delete PER;
		close();
	}
	else
	{
		QMessageBox::critical(this, tr("Espere!"), tr("Você precisa escolher todos campos!"));
	}
}


void Perso::on_radioButton_7_clicked()
{
	ui->atk->setText("75");
	ui->def->setText("100");
	ui->vel->setText("50");
	idclasse = 1;
}


void Perso::on_radioButton_8_clicked()
{
	ui->atk->setText("100");
	ui->def->setText("75");
	ui->vel->setText("50");
	idclasse = 2;
}


void Perso::on_radioButton_9_clicked()
{
	ui->atk->setText("50");
	ui->def->setText("75");
	ui->vel->setText("100");
	idclasse = 3;
}


void Perso::on_radioButton_12_clicked()
{
	ui->atk->setText("100");
	ui->def->setText("50");
	ui->vel->setText("75");
	idclasse = 4;
}


void Perso::on_radioButton_clicked()
{
	cordocabelo = "Preto";
}


void Perso::on_radioButton_3_clicked()
{
	cordocabelo = "Loiro";
}


void Perso::on_radioButton_2_clicked()
{
	cordocabelo = "Ruivo";
}


void Perso::on_radioButton_4_clicked()
{
	cordapele = "Branca";
}


void Perso::on_radioButton_5_clicked()
{
	cordapele = "Mestiço";
}


void Perso::on_radioButton_6_clicked()
{
	cordapele = "Negro";
}


void Perso::on_radioButton_10_clicked()
{
	genero = "Masculino";
}


void Perso::on_radioButton_11_clicked()
{
	genero = "Feminino";
}


void Perso::on_radioButton_13_clicked()
{
	cabelo = "Curto";
}


void Perso::on_radioButton_14_clicked()
{
	cabelo = "Medio";
}


void Perso::on_radioButton_15_clicked()
{
	cabelo = "Longo";
}

