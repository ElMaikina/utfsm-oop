import Mascota
import Estado

# Ejemplo de uso
#mascota = Mascota.Mascota("Fido", 80, 70, 90)
#mascota.mostrar_mascota()
#mascota.pasar_tiempo()
#mascota.penalizar()
#mascota.actualizar_estado()
#mascota.mostrar_mascota()

import sys
import random

from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6.QtSql import *
from PyQt6.QtWidgets import *

class MovingPet(QWidget):
    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.setWindowTitle('Mascota Móvil')
        self.setGeometry(100, 100, 800, 600)

        # Configurar el layout y la etiqueta para la mascota
        self.layout = QVBoxLayout()
        self.pet_label = QLabel(self)
        self.pet_pixmap = QPixmap('baby_pou.png')  # Reemplaza 'pet.png' con la ruta a tu imagen
        self.pet_label.setPixmap(self.pet_pixmap)
        self.layout.addWidget(self.pet_label)
        self.setLayout(self.layout)

        # Configurar el temporizador para mover la mascota
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.move_pet)
        self.timer.start(10)  # Mover cada 500 ms

        self.show()

    def move_pet(self):
        # Obtener dimensiones de la ventana y la imagen
        window_width = self.width()
        window_height = self.height()
        pet_width = self.pet_label.width()
        pet_height = self.pet_label.height()

        # Generar nuevas posiciones aleatorias dentro de los límites de la ventana
        new_x = random.randint(0, window_width - pet_width)
        new_y = random.randint(0, window_height - pet_height)

        # Mover la mascota a la nueva posición
        self.pet_label.move(new_x, new_y)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MovingPet()
    sys.exit(app.exec())
