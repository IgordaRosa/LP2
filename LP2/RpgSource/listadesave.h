#ifndef LISTADESAVE_H
#define LISTADESAVE_H

#include <QDialog>
#include "char.hpp"

namespace Ui {
	class listadesave;
}

vector<string> CarregarLista();
void SalvaLista(vector<string> dat);

class listadesave : public QDialog
{
	Q_OBJECT

public:
	explicit listadesave(QWidget *parent = nullptr);
	~listadesave();


private slots:
	void on_pushButton_clicked();

	void on_removerperso_clicked();

private:
	Ui::listadesave *ui;
};

#endif // LISTADESAVE_H
