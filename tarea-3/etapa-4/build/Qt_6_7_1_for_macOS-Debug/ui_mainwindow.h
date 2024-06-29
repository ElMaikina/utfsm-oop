/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *healthBar;
    QLabel *SALUD;
    QLabel *ENERGIA;
    QProgressBar *energyBar;
    QProgressBar *joyBar;
    QLabel *FELICIDAD;
    QLabel *ESTADO;
    QLabel *stateLabel;
    QPushButton *foodButton1;
    QPushButton *Hueso;
    QPushButton *Bola;
    QPushButton *foodButton3;
    QPushButton *foodButton2;
    QPushButton *medButton2;
    QPushButton *medButton1;
    QLabel *INVENTARIO;
    QLabel *Mascota;
    QLabel *NOMBRE;
    QLabel *EDAD;
    QLabel *ageLabel;
    QLabel *nameLabel;
    QLabel *JUGUETES;
    QLabel *foodLabel1;
    QLabel *foodLabel3;
    QLabel *medLabel2;
    QLabel *medLabel1;
    QLabel *foodLabel2;
    QPushButton *medButton3;
    QLabel *medLabel3;
    QLabel *label;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(615, 448);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        healthBar = new QProgressBar(centralwidget);
        healthBar->setObjectName("healthBar");
        healthBar->setGeometry(QRect(10, 100, 151, 23));
        healthBar->setValue(24);
        healthBar->setTextVisible(false);
        SALUD = new QLabel(centralwidget);
        SALUD->setObjectName("SALUD");
        SALUD->setGeometry(QRect(40, 80, 101, 16));
        ENERGIA = new QLabel(centralwidget);
        ENERGIA->setObjectName("ENERGIA");
        ENERGIA->setGeometry(QRect(40, 130, 111, 16));
        energyBar = new QProgressBar(centralwidget);
        energyBar->setObjectName("energyBar");
        energyBar->setGeometry(QRect(10, 150, 151, 23));
        energyBar->setValue(55);
        energyBar->setTextVisible(false);
        joyBar = new QProgressBar(centralwidget);
        joyBar->setObjectName("joyBar");
        joyBar->setGeometry(QRect(10, 200, 151, 23));
        joyBar->setValue(24);
        joyBar->setTextVisible(false);
        FELICIDAD = new QLabel(centralwidget);
        FELICIDAD->setObjectName("FELICIDAD");
        FELICIDAD->setGeometry(QRect(40, 180, 121, 16));
        ESTADO = new QLabel(centralwidget);
        ESTADO->setObjectName("ESTADO");
        ESTADO->setGeometry(QRect(20, 240, 49, 16));
        stateLabel = new QLabel(centralwidget);
        stateLabel->setObjectName("stateLabel");
        stateLabel->setGeometry(QRect(20, 240, 211, 61));
        QFont font;
        font.setPointSize(23);
        stateLabel->setFont(font);
        foodButton1 = new QPushButton(centralwidget);
        foodButton1->setObjectName("foodButton1");
        foodButton1->setGeometry(QRect(140, 300, 71, 31));
        Hueso = new QPushButton(centralwidget);
        Hueso->setObjectName("Hueso");
        Hueso->setGeometry(QRect(480, 330, 51, 41));
        Bola = new QPushButton(centralwidget);
        Bola->setObjectName("Bola");
        Bola->setGeometry(QRect(540, 320, 51, 51));
        foodButton3 = new QPushButton(centralwidget);
        foodButton3->setObjectName("foodButton3");
        foodButton3->setGeometry(QRect(360, 300, 71, 31));
        foodButton2 = new QPushButton(centralwidget);
        foodButton2->setObjectName("foodButton2");
        foodButton2->setGeometry(QRect(250, 300, 71, 31));
        medButton2 = new QPushButton(centralwidget);
        medButton2->setObjectName("medButton2");
        medButton2->setGeometry(QRect(250, 340, 71, 31));
        medButton1 = new QPushButton(centralwidget);
        medButton1->setObjectName("medButton1");
        medButton1->setGeometry(QRect(140, 340, 71, 31));
        INVENTARIO = new QLabel(centralwidget);
        INVENTARIO->setObjectName("INVENTARIO");
        INVENTARIO->setGeometry(QRect(50, 350, 81, 16));
        QFont font1;
        font1.setPointSize(13);
        INVENTARIO->setFont(font1);
        Mascota = new QLabel(centralwidget);
        Mascota->setObjectName("Mascota");
        Mascota->setGeometry(QRect(190, 30, 371, 211));
        NOMBRE = new QLabel(centralwidget);
        NOMBRE->setObjectName("NOMBRE");
        NOMBRE->setGeometry(QRect(10, 20, 61, 16));
        EDAD = new QLabel(centralwidget);
        EDAD->setObjectName("EDAD");
        EDAD->setGeometry(QRect(10, 50, 49, 16));
        ageLabel = new QLabel(centralwidget);
        ageLabel->setObjectName("ageLabel");
        ageLabel->setGeometry(QRect(80, 50, 81, 16));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(80, 20, 141, 16));
        JUGUETES = new QLabel(centralwidget);
        JUGUETES->setObjectName("JUGUETES");
        JUGUETES->setGeometry(QRect(500, 300, 81, 20));
        foodLabel1 = new QLabel(centralwidget);
        foodLabel1->setObjectName("foodLabel1");
        foodLabel1->setGeometry(QRect(220, 300, 31, 20));
        foodLabel3 = new QLabel(centralwidget);
        foodLabel3->setObjectName("foodLabel3");
        foodLabel3->setGeometry(QRect(440, 300, 31, 20));
        medLabel2 = new QLabel(centralwidget);
        medLabel2->setObjectName("medLabel2");
        medLabel2->setGeometry(QRect(330, 350, 31, 20));
        medLabel1 = new QLabel(centralwidget);
        medLabel1->setObjectName("medLabel1");
        medLabel1->setGeometry(QRect(220, 350, 31, 20));
        foodLabel2 = new QLabel(centralwidget);
        foodLabel2->setObjectName("foodLabel2");
        foodLabel2->setGeometry(QRect(330, 300, 31, 20));
        medButton3 = new QPushButton(centralwidget);
        medButton3->setObjectName("medButton3");
        medButton3->setGeometry(QRect(360, 340, 71, 31));
        medLabel3 = new QLabel(centralwidget);
        medLabel3->setObjectName("medLabel3");
        medLabel3->setGeometry(QRect(440, 350, 58, 16));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 300, 81, 20));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 615, 37));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SALUD->setText(QCoreApplication::translate("MainWindow", "Salud", nullptr));
        ENERGIA->setText(QCoreApplication::translate("MainWindow", "Energia", nullptr));
        FELICIDAD->setText(QCoreApplication::translate("MainWindow", "Felicidad", nullptr));
        ESTADO->setText(QCoreApplication::translate("MainWindow", "Estado", nullptr));
        stateLabel->setText(QCoreApplication::translate("MainWindow", "Neutro", nullptr));
        foodButton1->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
        foodButton3->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
        foodButton2->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
        medButton2->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
        medButton1->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
        INVENTARIO->setText(QCoreApplication::translate("MainWindow", "MEDICINA", nullptr));
        Mascota->setText(QString());
        NOMBRE->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        EDAD->setText(QCoreApplication::translate("MainWindow", "Edad:", nullptr));
        ageLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "NOMBRE", nullptr));
        JUGUETES->setText(QCoreApplication::translate("MainWindow", "Juguetes", nullptr));
        foodLabel1->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        foodLabel3->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        medLabel2->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        medLabel1->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        foodLabel2->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        medButton3->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
        medLabel3->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "COMIDA ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
