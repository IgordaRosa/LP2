#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "opt.h"
#include "char.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

bool Estalogado();

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_continuar_clicked();

	void on_novojogo_clicked();

	void on_carregarjogo_clicked();

	void on_opt_clicked();

	void on_sair_clicked();

	void on_about_clicked();

private:
	Ui::MainWindow *ui;
	OPT *opt;
};
#endif // MAINWINDOW_H
