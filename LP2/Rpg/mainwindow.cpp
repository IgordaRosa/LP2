#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opt.h"
#include "perso.h"
#include "listadesave.h"
#include "teladeperso.h"
#include "about.h"

bool Estalogado()
{
	string dat;
	ifstream temp;
	temp.open("saves.dat");

	getline(temp, dat);
	if(dat == "0")
		{
			return false;
		}
	getline(temp, dat);
	if(dat == "")
		{
			return false;
		}


	return true;
}

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QPixmap pix(":/elementos/TelaInicial.png");
	 int w = ui->fundo->width();
	 int h = ui->fundo->height();
	 //ui->label_picture->setPixmap(pix);
	 ui->fundo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
	delete ui;
	delete opt;
}


void MainWindow::on_continuar_clicked()
{
	if(!Estalogado())
	{
		QMessageBox::critical(this, tr("Espere!"), tr("Você precisa logar em um personagem!"));
	}
	else
	{
		qApp->closeAllWindows();
		TelaDePerso mDialog;
		mDialog.setModal(true);
		mDialog.exec();
	}
}


void MainWindow::on_novojogo_clicked()
{
	Perso mDialog;
	mDialog.setModal(true);
	mDialog.exec();
}


void MainWindow::on_carregarjogo_clicked()
{
	listadesave mDialog;
	mDialog.setModal(true);
	mDialog.exec();
}


void MainWindow::on_opt_clicked()
{
	 opt = new OPT(this);
	 opt->show();
}


void MainWindow::on_sair_clicked()
{
	qApp->quit();
}


void MainWindow::on_about_clicked()
{
	about mDialog;
	mDialog.setModal(true);
	mDialog.exec();
}

