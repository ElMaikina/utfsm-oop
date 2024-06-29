#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include "game_headers/Mascota.h"
#include "game_headers/Inventario.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Función que lee archivo csv e asigna nombre de mascota e
    // inicializa Items y los guarda en inventario asociado a mascota.
    // Ahora setGame (antes leerMascota) lee QFiles y no iostreams
    // porque archivo config.csv se debe manejar desde recursos.qrc.
    void setGame(const QString& nombreArchivo);

    void setIdPad();

    void setLabels();

    void setFoodLabels(QLabel *labels[]);

    void setMedLabels(QLabel *labels[]);

    void nameButtons(QPushButton *foodButtons[], QPushButton *medButtons[]);

    void setStats();

private:
    Ui::MainWindow *ui;
    QTimer *reloj;

    Mascota mascota;
    Inventario inventario;

    int idPad[2][3] = {{0,0,0},{0,0,0}};
    QLabel *foodLabels[3];
    QLabel *medLabels[3];
    QPushButton *foodButtons[3];
    QPushButton *medButtons[3];


private slots:
    void advance();
    void comer(int index);
    void sanar(int index);
    void jugar();
};
#endif // MAINWINDOW_H
