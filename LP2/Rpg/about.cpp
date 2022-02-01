#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::about)
{
	ui->setupUi(this);

	QPixmap pixvel(":/elementos/FotoAbout.jpg");
	 int w = ui->fotinhadobrabo->width();
	 int h = ui->fotinhadobrabo->height();
	 //ui->label_picture->setPixmap(pix);
	 ui->fotinhadobrabo->setPixmap(pixvel.scaled(w,h,Qt::KeepAspectRatio));
}

about::~about()
{
	delete ui;
}
