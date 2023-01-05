#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->hSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
    disconnect(ui->hSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnClick_clicked()
{
    QApplication::quit();
}

