#include "opt.h"
#include "ui_opt.h"

OPT::OPT(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::OPT)
{
	ui->setupUi(this);
}

OPT::~OPT()
{
	delete ui;
}


void OPT::on_sair_clicked()
{
	close();
}


void OPT::on_sair_2_clicked()
{
	qApp->closeAllWindows();
}


void OPT::on_radioButton_clicked()
{
}


void OPT::on_radioButton_2_clicked()
{
}


void OPT::on_radioButton_3_clicked()
{
}


void OPT::on_radioButton_4_clicked()
{
}


void OPT::on_radioButton_5_clicked()
{
}


void OPT::on_radioButton_6_clicked()
{
}

