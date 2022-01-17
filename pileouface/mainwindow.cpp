#include "mainwindow.h"
#include "ui_mainwindow.h"
int r=2;
int piece=2;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    lancer_piece();
    r=0;
    verif();
}

void MainWindow::on_pushButton_2_clicked()
{
    lancer_piece();
    r=1;
    verif();
}

void MainWindow::lancer_piece()
{
    piece=qrand()%2;

    if(piece==1)
    {
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/image/1_euro_France.png);");
    }
    else if(piece==0)
    {
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/image/1_euro_face_commune_2.png);");
    }
}

void MainWindow::verif()
{
    if(r == piece)
        ui->label->setText("Gagné PD !");
    else
        ui->label->setText("Perdu enculé ! XD");
}
