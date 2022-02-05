#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void lancer_piece();
    void verif();
    void set_scoreboard();
    void set_connexion();
    void set_jeu();
    void parametre_visuel(int varBase, int varInverse);
    void coinAnimation(int time);
    void delay(int time);


private slots:
    void on_pile_button_clicked();
    void on_face_button_clicked();
    void on_option_clicked();
    void on_connexion_button_clicked();
    void on_restart_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
