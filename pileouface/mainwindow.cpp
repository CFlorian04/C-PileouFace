#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QMovie"
#include <QMessageBox>
#include <QTime>
#include <QtSql>@

//Variables de jeu
int r= -1, piece= -1, vie = 3, score = 0;
QString pseudo="";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->restart_button->setVisible(false);

    //Connexion à la base de données SQLITE (présent dans le dossier du jeu)
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Florian/Documents/GitHub/pileouface/pileouface/pileouface.sqlite"); //ATTENTION à REMPLACER avec le chemin du FICHIER : pileouface.sqlite dans les dossiers du jeu
    db.setUserName("root");
    db.setPassword("");

    //Vérification de connexion à la BDD
    if (!db.open()) qDebug() << "Failed to connect to MYSQL Database";
    else qDebug() << "Connect to MYSQL Database";

    //Applique les paramêtres et affichages du début de jeu
    set_connexion();
    set_scoreboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Fonction de clique sur le bouton option
void MainWindow::on_option_clicked()
{
    QMessageBox::information(this,"Règles",
                             "Vous devez choisir entre pile et face. Une fois votre choix fait, si vous avez eu juste vous gagnez un point, dans le cas contraire vous perdez une vie. Le jeu s'arrête une fois les 3 vies perdues."
                             "\n\nConnecter-vous avec un nom déja existant ou alors avec créer votre utilisateur en entrant un nouveau nom.");
}

//Fonction de clique sur le bouton connexion
void MainWindow::on_connexion_button_clicked()
{

    if (ui->connexion_pseudo->text()=="")
        //Si aucun pseudo présent -> afficher une boîte de dialogue
        QMessageBox::information(this,"Erreur","Aucun pseudo n'a été rentré");
    else
    {
        //Stock le pseudo entré dans une variable
        pseudo = ui->connexion_pseudo->text();

        // Vérifie si le joueur a déja un nom dans la base de donnée. Si non -> création du joueur dans la BDD
        //requete SQL pour récupérer l'ensemble des pseudos de la table 'score' de la BDD
        QSqlQuery query;
        query.exec("SELECT pseudo FROM score");

        bool verifpseudo = false;
        while(query.next())
        {
            if(pseudo == query.value(0).toString())
            {
                qDebug() << "Connexion avec le pseudo : " << pseudo ;
                verifpseudo = true;
            }
        }

        //Si le pseudo n'est pas présent dans la BDD -> création du joueur dans la BDD
        if(verifpseudo == false)
        {
            qDebug() << "Création avec le pseudo : " << pseudo ;
            QSqlQuery query;
            query.prepare("INSERT INTO score (pseudo,score)"
                          "VALUES (?,0) ");
            query.addBindValue(pseudo);
            query.exec();
        }

        //Affiche les éléments du jeu
        set_jeu();
    }
}


//Fonction de clique sur le bouton Pile
void MainWindow::on_pile_button_clicked()
{
    if(vie>0)
    {
        lancer_piece();
        r=0;
    }
}

//Fonction de clique sur le bouton Face
void MainWindow::on_face_button_clicked()
{
    if(vie>0)
    {
        lancer_piece();
        r=1;
    }
}

//Fonction de l'aléatoire sur un lancer de pièce
void MainWindow::lancer_piece()
{

    coinAnimation(1000);
    std::srand(time(NULL));
    piece=rand()%2;

    //Applique l'image correspondante au résultat de l'aléatoire
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

//Fonction de comparaison du choix et du résultat aléatoire
void MainWindow::verif()
{
    if(r == piece)  //Si le choix et le résultat sont les mêmes -> augmentation du score de 1
    {
        ui->piece_texte->setText("Bien Joué!");
        score++;
    }
    else            //Si le choix et le résultat sont différents -> reduction de la vie de 1
    {
        ui->piece_texte->setText("Dommage...");
        vie = vie-1;
    }

    //Affichage et mise à jour du score
    ui->label_score->setText("Score : " + QString::number(score));

    //Possibilités de vie et les actions correspondantes
    switch ( vie )
    {
    case 2:
        //Remplace l'image du coeur par une croix
        ui->coeur_3->setStyleSheet("background-image: url(:/image/croix.png);");
        break;

    case 1:
        //Remplace l'image du coeur par une croix
        ui->coeur_2->setStyleSheet("background-image: url(:/image/croix.png);");
        break;

    case 0:
        //Affichage du bouton restart
        ui->restart_button->setVisible(true);
        //Remplace l'image du coeur par une croix
        ui->coeur_1->setStyleSheet("background-image: url(:/image/croix.png);");
        ui->piece_texte->setText("Fini !");
        break;
    }

    // Récupérer la valeur du meilleur score de la BDD et la comparer -> si superieur remplacer la valeur
    //requete SQL pour récupérer l'ensemble des données de la table 'score' de la BDD
    QSqlQuery query;
    query.exec("SELECT * FROM score");
    while(query.next())
    {
        if(query.value(0).toString()== pseudo)
        {
            //Si le score effectué est supérieur à celui enregistré en BDD
            if(query.value(1).toInt() < score)
            {
                //requete SQL pour mettre à jour le score du joueur
                QSqlQuery query;
                query.prepare("UPDATE score SET score = ? WHERE pseudo = ?");
                query.addBindValue(score);
                query.addBindValue(pseudo);
                query.exec();
            }
        }
    }
}


//Fonction qui affiche les résultats des joueurs dans un scoreboard
void MainWindow::set_scoreboard(){

    //Reset du scoreboard
    ui->scoreboard_table->setRowCount(0);
    ui->scoreboard_table->insertRow (ui->scoreboard_table->rowCount());
    int i =0;

    //requete SQL pour récupérer l'ensemble des données de la table 'score' de la BDD trier par le score en ordre décroissant
    QSqlQuery query;
    query.exec("SELECT * FROM score ORDER BY score DESC");

    //Mise en place des joueurs et de leur score dans le scoreboard
    while(query.next())
    {
        ui->scoreboard_table->insertRow(i);
        ui->scoreboard_table->setItem(i, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->scoreboard_table->setItem(i, 1, new QTableWidgetItem(query.value(1).toString()));
        i++;
    }
    ui->scoreboard_table->removeRow(ui->scoreboard_table->rowCount()-1);
}

//Fonction qui fait l'affichage des éléments en mode connexion
void MainWindow::set_connexion(){

    bool varBase= true;
    bool varInverse= false;
    parametre_visuel(varBase,varInverse);

}

//Fonction qui fait l'affichage des éléments en mode jeu et initialise les paramêtres de jeu
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

//Fonction qui regroupe l'ensemble des éléments visuels et permet de changer leur affichage
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

//Fonction de clique sur le bouton Restart
void MainWindow::on_restart_button_clicked()
{
    set_jeu();
}

//Fonction qui fait l'animation de la pièce (avec time en ms)
void MainWindow::coinAnimation(int time)
{
    //Remplace le fond par du vide
    ui->piece_image->setStyleSheet("background-image: url(:/image/vide.png);");

    //Applique un GIF à l'élément
    QMovie *movie=new QMovie(":/image/piece_animation.gif");
    ui->piece_image->setMovie(movie);

    //Lance l'animation pendant X sec et l'arrête
    movie->start();
    delay(time);
    movie->stop();
    ui->piece_image->clear();
}

//Fonction qui permet de créer un delai d'attente pour l'animation
void MainWindow::delay(int time)
{
    QTime dieTime = QTime::currentTime().addMSecs(time);
    while(QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

