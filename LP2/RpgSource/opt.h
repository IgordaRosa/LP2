#ifndef OPT_H
#define OPT_H

#include <QDialog>

namespace Ui {
	class OPT;
}

class OPT : public QDialog
{
	Q_OBJECT

public:
	explicit OPT(QWidget *parent = nullptr);
	~OPT();

private slots:
	void on_sair_clicked();

	void on_sair_2_clicked();

	void on_radioButton_clicked();

	void on_radioButton_2_clicked();

	void on_radioButton_3_clicked();

	void on_radioButton_4_clicked();

	void on_radioButton_5_clicked();

	void on_radioButton_6_clicked();

private:
	Ui::OPT *ui;
};

#endif // OPT_H
