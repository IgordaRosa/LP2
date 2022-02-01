#ifndef TELADEPERSO_H
#define TELADEPERSO_H

#include <QDialog>
#include "perso.h"

namespace Ui {
	class TelaDePerso;
}

Char CarregarChar();
void AlterarChar(Char C, size_t id);

class TelaDePerso : public QDialog
{
	Q_OBJECT

public:
	explicit TelaDePerso(QWidget *parent = nullptr);
	~TelaDePerso();

private slots:


	void on_opt_clicked();

	void on_givexp_clicked();

	void on_givelevel_clicked();

	void on_givemoney_clicked();

	void on_pushButton_clicked();


private:
	Ui::TelaDePerso *ui;
};

#endif // TELADEPERSO_H
