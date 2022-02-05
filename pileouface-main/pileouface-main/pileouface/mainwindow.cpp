#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QMovie"
#include <QMessageBox>

int r= -1, piece= -1, vie = 3, score = 0;
QString pseudo="";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->restart_button->setVisible(false);

    set_connexion();
    set_scoreboard();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_option_clicked()
{
    QMessageBox::information(this,"Règles","Vous devez choisir entre pile et face. Une fois votre choix fait, si vous avez eu juste vous gagnez un point, dans le cas contraire vous perdez une vie. Le jeu s'arrête une fois les 3 vies perdues.");
}

void MainWindow::on_connexion_button_clicked()
{

    if (ui->connexion_pseudo->text()=="")
        //Si aucun pseudo présent afficher une boîte de dialogue
        QMessageBox::information(this,"Erreur","Aucun pseudo n'a été rentré");
    else
    {

    // Vérifie si le joueur a déja un nom dans la base de donnée : si non création du joueur dans la BDD
        //requete BDD
        //if pseudo != pseudo(BDD) -> création du pseudo en BDD

        set_jeu();
    }




}


void MainWindow::on_pile_button_clicked()
{
    if(vie>0)
    {
      lancer_piece();
      r=0;
    }

}

void MainWindow::on_face_button_clicked()
{
    if(vie>0)
    {
      lancer_piece();
      r=1;
    }

}

void MainWindow::lancer_piece()
{


    //Intégrer l'animation de la pièce avant d'afficher le résultat du lancer

//    ui->piece_image->setStyleSheet("background-image: url(:/image/fond_transparent.png);");

//    QMovie *movie=new QMovie(":/image/piece_animation2.gif");
//    ui->piece_image->setMovie(movie);
//    movie->start();
//    movie->startTimer(1000);
//    movie->stop();

    std::srand(time(NULL));
    piece=rand()%2;

    if(piece==1)
    {
        ui->piece_image->setStyleSheet("background-image: url(:/image/piece_pile.png);");
    }
    else if(piece==0)
    {
        ui->piece_image->setStyleSheet("background-image: url(:/image/piece_face.png);");
    }

    verif();
}

void MainWindow::verif()
{
    if(r == piece)
    {
        ui->piece_texte->setText("Bien Joué!");
        score++;
    }
    else
    {
        ui->piece_texte->setText("Dommage...");
        vie = vie-1;
    }

    ui->label_score->setText("Score : " + QString::number(score));

    switch ( vie )
          {
             case 2:
                ui->coeur_3->setStyleSheet("background-image: url(:/image/croix.png);");
                break;

            case 1:
                ui->coeur_2->setStyleSheet("background-image: url(:/image/croix.png);");
                break;

            case 0:
                ui->restart_button->setVisible(true);
                ui->coeur_1->setStyleSheet("background-image: url(:/image/croix.png);");
                ui->piece_texte->setText("Vous avez Perdu !");
                // Récupérer la valeur du meilleur score de la BDD et la comparer si superieur remplacer la valeur
               break;
          }



}



void MainWindow::set_scoreboard(){

    ui->scoreboard_table->setRowCount(0);
    ui->scoreboard_table->insertRow ( ui->scoreboard_table->rowCount() );

    //Intégrer l'ensemble des joueurs de la BDD avec leurs score (while)
    //SELECT * FROM [base] ORDER BY score DESC
    ui->scoreboard_table->setItem   ( ui->scoreboard_table->rowCount()-1, 0, new QTableWidgetItem("Test"));
    ui->scoreboard_table->setItem   ( ui->scoreboard_table->rowCount()-1, 1, new QTableWidgetItem("0"));
}



void MainWindow::set_connexion(){

    bool varBase= true;
    bool varInverse= false;
    parametre_visuel(varBase,varInverse);

}

void MainWindow::set_jeu(){

    r= -1, piece= -1, vie = 3, score = 0;

    ui->piece_texte->setText("");
    ui->restart_button->setVisible(false);
    ui->coeur_3->setStyleSheet("background-image: url(:/image/coeur.png);");
    ui->coeur_2->setStyleSheet("background-image: url(:/image/coeur.png);");
    ui->coeur_1->setStyleSheet("background-image: url(:/image/coeur.png);");

    ui->label_score->setText("Score : " + QString::number(score));
    bool varBase= false;
    bool varInverse= true;
    parametre_visuel(varBase,varInverse);

    set_scoreboard();

}

void MainWindow::parametre_visuel(int varBase, int varInverse){

    ui->connexion_button->setVisible(varBase);
    ui->connexion_pseudo->setVisible(varBase);
    ui->piece_image->setHidden(varBase);

    ui->face_button->setVisible(varInverse);
    ui->pile_button->setVisible(varInverse);
    ui->piece_texte->setVisible(varInverse);
    ui->coeur_1->setVisible(varInverse);
    ui->coeur_2->setVisible(varInverse);
    ui->coeur_3->setVisible(varInverse);
    ui->label_score->setVisible(varInverse);

}

void MainWindow::on_restart_button_clicked()
{
    set_jeu();
}

