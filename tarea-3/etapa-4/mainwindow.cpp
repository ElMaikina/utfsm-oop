#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "game_headers/Comida.h"
#include "game_headers/Medicina.h"
#include "game_headers/Juguete.h"

#include <QFile>
#include <QTextStream>
#include <QString>

#include <sstream>
#include <string>
#include <vector>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , inventario(mascota)
{
    ui->setupUi(this);

    this->setWindowTitle("Perrito");
    this->setFixedSize(600,410);

    foodLabels[0] = ui->foodLabel1;
    foodLabels[1] = ui->foodLabel2;
    foodLabels[2] = ui->foodLabel3;

    medLabels[0] = ui->medLabel1;
    medLabels[1] = ui->medLabel2;
    medLabels[2] = ui->medLabel3;

    foodButtons[0] = ui->foodButton1;
    foodButtons[1] = ui->foodButton2;
    foodButtons[2] = ui->foodButton3;

    medButtons[0] = ui->medButton1;
    medButtons[1] = ui->medButton2;
    medButtons[2] = ui->medButton3;

    ui->healthBar->setMinimum(MIN_STATS);
    ui->healthBar->setMaximum(MAX_STATS);

    ui->energyBar->setMinimum(MIN_STATS);
    ui->energyBar->setMaximum(MAX_STATS);

    ui->joyBar->setMinimum(MIN_STATS);
    ui->joyBar->setMaximum(MAX_STATS);

    this->setGame(":/resource/config.csv");
    this->setIdPad();
    this->setFoodLabels(foodLabels);
    this->setMedLabels(medLabels);
    this->nameButtons(foodButtons, medButtons);
    this->setStats();

    for (int i=0; i <=2;i++) {
        if (idPad[0][i]==0) {
            break;
        }
        QObject::connect(foodButtons[i], &QPushButton::clicked, this, [this, i]() { this->comer(i); });
    }

    for (int j=0; j <=2;j++) {
        if (idPad[1][j]==0) {
            break;
        }
        QObject::connect(medButtons[j], &QPushButton::clicked, this, [this, j]() { this->sanar(j); });
    }

    QPixmap pix(":/resource/img/dog.jpg");
    QPixmap j1(":/resource/img/bone.jpg");
    QPixmap j2(":/resource/img/ball.jpg");

    QIcon HuesoBoton(j1);
    QIcon BolaBoton(j2);

    ui->Hueso->setIcon(HuesoBoton);
    ui->Bola->setIcon(BolaBoton);

    ui->Hueso->setIconSize(QSize(50,50));
    ui->Bola->setIconSize(QSize(50,50));

    QObject::connect(ui->Hueso, &QPushButton::clicked, this, [this]() {this->jugar();});
    QObject::connect(ui->Bola, &QPushButton::clicked, this, [this]() {this->jugar();});

    int w = ui->Mascota->width();
    int h = ui->Mascota->height();
    ui->Mascota->setPixmap(pix.scaled(w,h));

    ui->nameLabel->setText(QString::fromStdString(mascota.nombre));




    reloj = new QTimer(this);
    connect(reloj, &QTimer::timeout, this, &MainWindow::advance);
    reloj->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::advance()
{
    mascota.penalizar();
    mascota.actualizarEstado();

    this->setStats();

    mascota.pasarTiempo();

    mascota.mostrarMascota();

    if (mascota.getEstado()=="Muerto") {
        reloj->stop();
    }

}


void MainWindow::setIdPad() {
    int i=0;
    int j=0;

    for (Item *item : inventario.getItems()) {
        if (item->getTipo() == "Comida") {
            idPad[0][i] = item->getId();
            i++;
        }
        else if (item->getTipo() == "Medicina") {
            idPad[1][j] = item->getId();
            j++;
        }
    }
}


void MainWindow::setFoodLabels(QLabel *labels[]) {
    int i;
    for (i = 0; i <= 2; ++i) {
        if (idPad[0][i] != 0) {
            int cantidad = inventario.buscarPorID(idPad[0][i])->getCantidad();
            //QString text = QString::number(cantidad);
            labels[i]->setText(QString::number(cantidad));
        } else {
            labels[i]->setText("0");
        }
    }
}


void MainWindow::setMedLabels(QLabel *labels[]) {
    int j;
    for (j = 0; j <= 2; ++j) {
        if (idPad[1][j] != 0) {
            int cantidad = inventario.buscarPorID(idPad[1][j])->getCantidad();
            labels[j]->setText(QString::number(cantidad));
        } else {
            labels[j]->setText("0");
        }
    }
}


void MainWindow::nameButtons(QPushButton *foodButtons[], QPushButton *medButtons[]) {
    for(int i=0; i<=2; i++){
        if(idPad[0][i]!=0){
            std::string text = inventario.buscarPorID(idPad[0][i])->getNombre();
            foodButtons[i]->setText(QString::fromStdString(text));
        }
        else{
            foodButtons[i]->setText(QString::fromStdString("---"));
        }
    }
    for(int j=0; j<=2; j++){
        if(idPad[1][j]!=0){
            std::string text = inventario.buscarPorID(idPad[1][j])->getNombre();
            medButtons[j]->setText(QString::fromStdString(text));
        }
        else{
            medButtons[j]->setText(QString::fromStdString("---"));
        }
    }
}


void MainWindow::comer(int index) {
    if (inventario.buscarPorID(idPad[0][index])->getCantidad() == 1) {
        inventario.usarItem(idPad[0][index],mascota);
        idPad[0][index] = 0;
        foodButtons[index]->disconnect();
    } else {
        inventario.usarItem(idPad[0][index],mascota);
    }
    this->setFoodLabels(foodLabels);
    this->nameButtons(foodButtons, medButtons);
}

void MainWindow::sanar(int index) {
    if (inventario.buscarPorID(idPad[1][index])->getCantidad() == 1) {
        inventario.usarItem(idPad[1][index],mascota);
        idPad[1][index] = 0;
        medButtons[index]->disconnect();
    } else {
        inventario.usarItem(idPad[1][index],mascota);
    }
    this->setMedLabels(medLabels);
    this->nameButtons(foodButtons, medButtons);
}

void MainWindow::jugar() {
    mascota.felicidad += 30;
}



void MainWindow::setStats() {

    ui->healthBar->setValue(mascota.salud);
    ui->energyBar->setValue(mascota.energia);
    ui->joyBar->setValue(mascota.felicidad);

    // std::cout << mascota.salud << std::endl;

    ui->ageLabel->setText(QString::number(mascota.edad));
    ui->stateLabel->setText(QString::fromStdString(mascota.getEstado()));
}


void MainWindow::setGame(const QString& nombreArchivo) {

    QFile archivo(nombreArchivo);
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Error al abrir el archivo:" << nombreArchivo;
        exit(-1);
    }

    QTextStream in(&archivo);


    std::string linea;

    while (!in.atEnd()) {

        QString linea = in.readLine();
        std::stringstream ss(linea.toStdString());
        std::string campo;
        std::vector<std::string> campos;

        while (std::getline(ss, campo, ';')) {
            campos.push_back(campo);
        }

        if (campos.size() == 1) {
            // Crear y devolver una instancia de Mascota
            std::string nombre = campos[0];
            mascota.nombre = nombre;
            continue;
        }

        int id = std::stoi(campos[0]);
        char type = campos[1][0];
        std::string nombre = campos[2];
        int cantidad = std::stoi(campos[3]);

        Item * newItem;

        switch (type) {
        case 'M':
            newItem = new Medicina(id, nombre, cantidad);
            break;

        case 'C':
            newItem = new Comida(id, nombre, cantidad);
            break;

        case 'J':
            newItem = new Juguete(id, nombre);
            break;
        }

        newItem->mostrarItem();

        inventario.agregarItem(newItem);
    }
    archivo.close();
}


