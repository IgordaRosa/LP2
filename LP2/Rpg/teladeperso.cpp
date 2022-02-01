#include "teladeperso.h"
#include "ui_teladeperso.h"
#include "opt.h"

#include <QMessageBox>

Char CarregarChar()
{
	string arquivo;
	vector<string> dat;
	ifstream temp;
	temp.open("saves.dat");

	string str;
	while(getline(temp, str))
	{
		dat.push_back(str);
	}
	temp.close();
	size_t j=0;
	j = stoi(dat.at(0));
	arquivo = dat.at(j);

	ifstream arqCHAR;
	arqCHAR.open(arquivo);
	vector<string> dadosCHAR;
	while(getline(arqCHAR, str))
	{
		dadosCHAR.push_back(str);
	}

	string nick = dadosCHAR.at(0);
	float altura = stof(dadosCHAR.at(1));
	string cordapele = dadosCHAR.at(2);
	string cabelo = dadosCHAR.at(3);
	string cordocabelo = dadosCHAR.at(4);
	string genero = dadosCHAR.at(5);
	size_t level = stoi(dadosCHAR.at(6));
	float dinheiro = stof(dadosCHAR.at(7));

	Personagem *personagem = new Personagem(nick, altura, cordapele, cabelo, cordocabelo, genero);

	//Classe selecionada(id)
	if(dadosCHAR.at(8) == "1")
	{
		Classe *guerreiro = new Classe(75, 100, 50, 1.075, 1.1, 1.05);
		Char CHAR(personagem, guerreiro, 1 ,level, dinheiro);
		delete guerreiro;
		delete personagem;
		return CHAR;
	}
	if(dadosCHAR.at(8) == "2")
	{
		Classe *mago = new Classe(100, 75, 50, 1.1, 1.075, 1.05);
		Char CHAR(personagem, mago, 2 ,level, dinheiro);
		delete mago;
		delete personagem;
		return CHAR;
	}
	if(dadosCHAR.at(8) == "3")
	{
		Classe *arqueiro = new Classe(50, 75, 100, 1.05, 1.075, 1.1);
		Char CHAR(personagem, arqueiro, 3 ,level, dinheiro);
		delete arqueiro;
		delete personagem;
		return CHAR;
	}
	if(dadosCHAR.at(8) == "4")
	{
		Classe *assassino = new Classe(100, 50, 75, 1.1, 1.05, 1.075);
		Char CHAR(personagem, assassino, 4 , level, dinheiro);
		delete assassino;
		delete personagem;
		return CHAR;
	}
	Classe *null = new Classe(0, 0, 0, 0, 0, 0);
	Char CHAR(personagem, null, 0 , level, dinheiro);
	delete null;
	delete personagem;
	return CHAR;
}

void AlterarChar(Char C)
{
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
	Chardat << C.GetCharID() << endl;
	Chardat.close();
}

TelaDePerso::TelaDePerso(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TelaDePerso)
{
	ui->setupUi(this);

	Char CHAR = CarregarChar();
	ui->Nick->setText(QString::fromStdString(CHAR.GetCharName()));
	ui->Altura->setText(QString::number(CHAR.GetCharAltura()));
	ui->Cordapele->setText(QString::fromStdString(CHAR.GetCharCpele()));
	ui->Cabelo->setText(QString::fromStdString(CHAR.GetCharCabelo()));
	ui->Cordecabelo->setText(QString::fromStdString(CHAR.GetCharCcabelo()));
	ui->Genero->setText(QString::fromStdString(CHAR.GetCharGenero()));
	ui->atk->setText(QString::number(CHAR.GetCharATK()));
	ui->def->setText(QString::number(CHAR.GetCharDEF()));
	ui->vel->setText(QString::number(CHAR.GetCharVEL()));
	ui->Level->setText(QString::number(CHAR.GetCharLevel()));
	ui->Dinheiro->setText("$ "+QString::number(CHAR.GetCharDin()));

	QPixmap pix(":/elementos/TelaDePersonagem.png");
	 int w = ui->backgroundPerso->width();
	 int h = ui->backgroundPerso->height();
	 //ui->label_picture->setPixmap(pix);
	 ui->backgroundPerso->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

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

	   if(CHAR.GetCharID() == 1){
		   QPixmap pix(":/icons/guerreiro.png");
			int w = ui->perso->width();
			int h = ui->perso->height();
			//ui->label_picture->setPixmap(pix);
			ui->perso->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
	   }

	   if(CHAR.GetCharID() == 2){
		   QPixmap pix(":/icons/mago.png");
			int w = ui->perso->width();
			int h = ui->perso->height();
			//ui->label_picture->setPixmap(pix);
			ui->perso->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
	   }

	   if(CHAR.GetCharID() == 3){
		   QPixmap pix(":/icons/arqueiro.png");
			int w = ui->perso->width();
			int h = ui->perso->height();
			//ui->label_picture->setPixmap(pix);
			ui->perso->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
	   }

	   if(CHAR.GetCharID() == 4){
		   QPixmap pix(":/icons/assassino.png");
			int w = ui->perso->width();
			int h = ui->perso->height();
			//ui->label_picture->setPixmap(pix);
			ui->perso->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
	   }
}

TelaDePerso::~TelaDePerso()
{
	delete ui;
}


void TelaDePerso::on_opt_clicked()
{
	OPT mDialog;
	mDialog.setModal(true);
	mDialog.exec();
}


void TelaDePerso::on_givexp_clicked()
{
	static size_t xp;
	xp+=27;
	size_t temp;
	if(xp >= 100)
	{
		Char CHAR = CarregarChar();
		temp = xp - 100;
		xp = temp;
		CHAR.LevelUP();
		AlterarChar(CHAR);
		CHAR = CarregarChar();
		ui->Level->setText(QString::number(CHAR.GetCharLevel()));
		ui->atk->setText(QString::number(CHAR.GetCharATK()));
		ui->def->setText(QString::number(CHAR.GetCharDEF()));
		ui->vel->setText(QString::number(CHAR.GetCharVEL()));
	}
	ui->progressBar->setValue(xp);
}


void TelaDePerso::on_givelevel_clicked()
{
	Char CHAR = CarregarChar();
	CHAR.LevelUP();
	AlterarChar(CHAR);
	CHAR = CarregarChar();
	ui->Level->setText(QString::number(CHAR.GetCharLevel()));
	ui->atk->setText(QString::number(CHAR.GetCharATK()));
	ui->def->setText(QString::number(CHAR.GetCharDEF()));
	ui->vel->setText(QString::number(CHAR.GetCharVEL()));
}


void TelaDePerso::on_givemoney_clicked()
{
	Char CHAR = CarregarChar();
	CHAR += 7;
	ui->Dinheiro->setText("$ "+QString::number(CHAR.GetCharDin()));
	AlterarChar(CHAR);
}


void TelaDePerso::on_pushButton_clicked()
{
	QMessageBox::about(this, tr(""), tr("O jogo ainda não está pronto!\nAguarde o lançamento!!"));
}

