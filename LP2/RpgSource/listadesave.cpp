#include "listadesave.h"
#include "ui_listadesave.h"

#include <QMessageBox>

vector<string> CarregarLista()
{
	vector<string> dat;
	ifstream temp;
	temp.open("saves.dat");

	string str;
	while(getline(temp, str))
	{
		dat.push_back(str);
	}
	temp.close();

	return dat;
}

void SalvarLista(vector<string> dat)
{
	ofstream database("saves.dat");
	for(size_t i=0; i < dat.size(); i++)
	{
		database << dat.at(i) << endl;
	}
	database.close();
}


listadesave::listadesave(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::listadesave)
{
	ui->setupUi(this);

	vector<string> Lista = CarregarLista();

	for(size_t i = 1; i < Lista.size(); i++)
	 {
		string str = Lista.at(i);
		str.erase(str.end() - 4, str.end());
		ui->listWidget->addItem(QString::number(i) + " " + QString::fromStdString(str));
	 }

	if(Lista.size() <= 1)
	{
		QMessageBox::about(this, tr("Não há saves!!"), tr("Você precisa criar um personagem antes"));
		close();
	}
}

listadesave::~listadesave()
{
	delete ui;
}

void listadesave::on_pushButton_clicked()
{
	if(ui->listWidget->currentItem()){
		vector<string>Lista = CarregarLista();
		QString temp = ui->listWidget->currentItem()->text();
		string str = temp.toStdString();
		size_t na = str.find_first_of(" ");
		str.erase(str.begin() +na,str.end());
		Lista.at(0) = str;
		SalvarLista(Lista);

		QMessageBox::about(this, tr("Sucesso!!"), tr("Você logou com sucesso"));
		close();
	}
	else{
		QMessageBox::critical(this, tr("Escolha!!"), tr("Escolha um save"));
	}
}


void listadesave::on_removerperso_clicked()
{
	if(ui->listWidget->currentItem())
	{
	vector<string> Lista = CarregarLista();
	QString temp = ui->listWidget->currentItem()->text();
	string str = temp.toStdString();
	size_t na = str.find_first_of(" ") +1;
	str.erase(str.begin(),str.begin()+na);
	for(size_t i = 1; i < Lista.size(); i++)
	{
		string tempstr = Lista.at(i);
		const char *removerarq = tempstr.c_str();
		remove(removerarq);
		tempstr.erase(tempstr.end() - 4, tempstr.end());
		if(tempstr == str)
		{
			Lista.erase(Lista.begin()+i);
		}
	}
	SalvarLista(Lista);
	ui->listWidget->clear();
	for(size_t i = 1; i < Lista.size(); i++)
	 {
		string str = Lista.at(i);
		str.erase(str.end() - 4, str.end());
		ui->listWidget->addItem(QString::number(i) + " " + QString::fromStdString(str));
	 }
	}
	else
	{
		QMessageBox::critical(this, tr("Escolha!!"), tr("Escolha um save"));
	}
}

