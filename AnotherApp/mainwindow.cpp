#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->addPermanentWidget(ui->lbGL);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnOK_clicked()
{
    QString prenom = ui->lePrenom->text();
    QString nom = ui->leNom->text();
    if ((!prenom.isEmpty()) || (!nom.isEmpty())  )
         ui->lbWelcome->setText("Welcome " + prenom + " " + nom);
}


void MainWindow::on_pushButton_clicked()
{
    ui->lePrenom->setText("");
    ui->leNom->setText("");
    ui->lbWelcome->setText("");
}


void MainWindow::on_btnAbout_clicked()
{
  // void about
   // QMessageBox::StandardButton
   //QMessageBox::aboutQt(this, "Titre");
    //QMessageBox::about(this, "Titre", "Message....");
   QMessageBox::information(this, "Titre", "Message....");
}


void MainWindow::on_btnQuitter_clicked()
{
  QMessageBox::StandardButton reply = QMessageBox::information(this, "Quitter", "Voulez vous quittez?", QMessageBox::Yes|QMessageBox::No );

  if (reply == QMessageBox::Yes)
      QApplication::quit();
  else
   // qDebug() << "No is clicked";
      ui->statusbar->showMessage("No is clicked", 5000);
}


void MainWindow::on_actionNew_triggered()
{
   // hide();
    secdialog = new SecDialog(this);
    secdialog->show();
}

