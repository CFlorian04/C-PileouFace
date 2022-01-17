/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *titre;
    QWidget *layoutWidget;
    QVBoxLayout *connexion_layout;
    QLineEdit *connexion_pseudo;
    QPushButton *connexion_button;
    QWidget *layoutWidget1;
    QVBoxLayout *scoreboard_layout;
    QLabel *scoreboard_title;
    QTableWidget *scoreboard_table;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label_score;
    QHBoxLayout *horizontalLayout;
    QLabel *coeur_1;
    QLabel *coeur_2;
    QLabel *coeur_3;
    QVBoxLayout *jeu_piece;
    QLabel *piece_texte;
    QLabel *piece_image;
    QVBoxLayout *button_layout_vertical;
    QHBoxLayout *button_layout_horizontal;
    QPushButton *pile_button;
    QPushButton *face_button;
    QToolButton *option;
    QPushButton *restart_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 600);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        titre = new QLabel(centralWidget);
        titre->setObjectName(QString::fromUtf8("titre"));
        titre->setGeometry(QRect(100, 0, 400, 70));
        QFont font;
        font.setPointSize(50);
        titre->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(400, 90, 141, 56));
        connexion_layout = new QVBoxLayout(layoutWidget);
        connexion_layout->setSpacing(6);
        connexion_layout->setContentsMargins(11, 11, 11, 11);
        connexion_layout->setObjectName(QString::fromUtf8("connexion_layout"));
        connexion_layout->setContentsMargins(0, 0, 0, 0);
        connexion_pseudo = new QLineEdit(layoutWidget);
        connexion_pseudo->setObjectName(QString::fromUtf8("connexion_pseudo"));

        connexion_layout->addWidget(connexion_pseudo);

        connexion_button = new QPushButton(layoutWidget);
        connexion_button->setObjectName(QString::fromUtf8("connexion_button"));

        connexion_layout->addWidget(connexion_button);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(340, 150, 261, 451));
        scoreboard_layout = new QVBoxLayout(layoutWidget1);
        scoreboard_layout->setSpacing(6);
        scoreboard_layout->setContentsMargins(11, 11, 11, 11);
        scoreboard_layout->setObjectName(QString::fromUtf8("scoreboard_layout"));
        scoreboard_layout->setContentsMargins(0, 0, 0, 0);
        scoreboard_title = new QLabel(layoutWidget1);
        scoreboard_title->setObjectName(QString::fromUtf8("scoreboard_title"));
        QFont font1;
        font1.setPointSize(15);
        font1.setStyleStrategy(QFont::PreferDefault);
        scoreboard_title->setFont(font1);
        scoreboard_title->setMouseTracking(false);
        scoreboard_title->setAlignment(Qt::AlignCenter);

        scoreboard_layout->addWidget(scoreboard_title);

        scoreboard_table = new QTableWidget(layoutWidget1);
        if (scoreboard_table->columnCount() < 2)
            scoreboard_table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        scoreboard_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        scoreboard_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        scoreboard_table->setObjectName(QString::fromUtf8("scoreboard_table"));
        scoreboard_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        scoreboard_table->setShowGrid(true);
        scoreboard_table->setRowCount(0);
        scoreboard_table->horizontalHeader()->setDefaultSectionSize(119);

        scoreboard_layout->addWidget(scoreboard_table);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 140, 254, 433));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_score = new QLabel(layoutWidget2);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        QFont font2;
        font2.setPointSize(15);
        label_score->setFont(font2);
        label_score->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_score);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        coeur_1 = new QLabel(layoutWidget2);
        coeur_1->setObjectName(QString::fromUtf8("coeur_1"));
        coeur_1->setMinimumSize(QSize(70, 66));
        coeur_1->setMaximumSize(QSize(70, 66));
        coeur_1->setStyleSheet(QString::fromUtf8("background-image: url(:/image/coeur.png);"));

        horizontalLayout->addWidget(coeur_1);

        coeur_2 = new QLabel(layoutWidget2);
        coeur_2->setObjectName(QString::fromUtf8("coeur_2"));
        coeur_2->setMinimumSize(QSize(70, 66));
        coeur_2->setMaximumSize(QSize(70, 66));
        coeur_2->setStyleSheet(QString::fromUtf8("background-image: url(:/image/coeur.png);"));

        horizontalLayout->addWidget(coeur_2);

        coeur_3 = new QLabel(layoutWidget2);
        coeur_3->setObjectName(QString::fromUtf8("coeur_3"));
        coeur_3->setMinimumSize(QSize(70, 66));
        coeur_3->setMaximumSize(QSize(70, 66));
        coeur_3->setStyleSheet(QString::fromUtf8("background-image: url(:/image/coeur.png);"));

        horizontalLayout->addWidget(coeur_3);


        verticalLayout->addLayout(horizontalLayout);

        jeu_piece = new QVBoxLayout();
        jeu_piece->setSpacing(6);
        jeu_piece->setObjectName(QString::fromUtf8("jeu_piece"));
        piece_texte = new QLabel(layoutWidget2);
        piece_texte->setObjectName(QString::fromUtf8("piece_texte"));
        QFont font3;
        font3.setPointSize(25);
        piece_texte->setFont(font3);
        piece_texte->setAutoFillBackground(true);
        piece_texte->setAlignment(Qt::AlignCenter);

        jeu_piece->addWidget(piece_texte);

        piece_image = new QLabel(layoutWidget2);
        piece_image->setObjectName(QString::fromUtf8("piece_image"));
        piece_image->setEnabled(true);
        piece_image->setMinimumSize(QSize(250, 250));
        piece_image->setMaximumSize(QSize(250, 250));
        piece_image->setStyleSheet(QString::fromUtf8("background-image: url(:/image/piece_face.png);"));

        jeu_piece->addWidget(piece_image);

        button_layout_vertical = new QVBoxLayout();
        button_layout_vertical->setSpacing(6);
        button_layout_vertical->setObjectName(QString::fromUtf8("button_layout_vertical"));
        button_layout_horizontal = new QHBoxLayout();
        button_layout_horizontal->setSpacing(6);
        button_layout_horizontal->setObjectName(QString::fromUtf8("button_layout_horizontal"));
        pile_button = new QPushButton(layoutWidget2);
        pile_button->setObjectName(QString::fromUtf8("pile_button"));

        button_layout_horizontal->addWidget(pile_button);

        face_button = new QPushButton(layoutWidget2);
        face_button->setObjectName(QString::fromUtf8("face_button"));

        button_layout_horizontal->addWidget(face_button);


        button_layout_vertical->addLayout(button_layout_horizontal);


        jeu_piece->addLayout(button_layout_vertical);


        verticalLayout->addLayout(jeu_piece);

        option = new QToolButton(centralWidget);
        option->setObjectName(QString::fromUtf8("option"));
        option->setGeometry(QRect(10, 10, 61, 31));
        restart_button = new QPushButton(centralWidget);
        restart_button->setObjectName(QString::fromUtf8("restart_button"));
        restart_button->setGeometry(QRect(10, 40, 60, 61));
        restart_button->setAutoFillBackground(false);
        restart_button->setStyleSheet(QString::fromUtf8("background-image: url(:/image/restart.png);"));
        restart_button->setCheckable(false);
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(connexion_pseudo, connexion_button);
        QWidget::setTabOrder(connexion_button, pile_button);
        QWidget::setTabOrder(pile_button, face_button);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        titre->setText(QCoreApplication::translate("MainWindow", "PILE OU FACE", nullptr));
        connexion_button->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        scoreboard_title->setText(QCoreApplication::translate("MainWindow", "SCOREBOARD", nullptr));
        QTableWidgetItem *___qtablewidgetitem = scoreboard_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Pseudo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = scoreboard_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        label_score->setText(QCoreApplication::translate("MainWindow", "Score : 0", nullptr));
        coeur_1->setText(QString());
        coeur_2->setText(QString());
        coeur_3->setText(QString());
        piece_texte->setText(QString());
        piece_image->setText(QString());
        pile_button->setText(QCoreApplication::translate("MainWindow", "Pile", nullptr));
        face_button->setText(QCoreApplication::translate("MainWindow", "Face", nullptr));
        option->setText(QCoreApplication::translate("MainWindow", "R\303\250gles", nullptr));
        restart_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
