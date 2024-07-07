from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6.QtSql import *
from PyQt6.QtWidgets import *

from Mascota import Mascota
import Personalidad as person
import Nombres as name
import random
import sys

class MovingPetsWindow(QWidget):
    def __init__(self, width, height):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.setWindowTitle('Granja de Pou')
        self.setGeometry(100, 100, width, height)
        # Lista para mantener las mascotas
        self.pets = []
        
        # Cargar personalidades desde el archivo CSV
        personalities_df = person.load_personalities('personalidad.csv')

        # Añadir mascotas
        for _ in range(5):  # Cambia este valor para tener más o menos mascotas
            personality = person.get_random_personality(personalities_df)
            pet = Mascota(self, name.generate_name(), 100, 100, 100, personality)  # Reemplaza 'pet.png' con la ruta a tu imagen
            self.pets.append(pet)
        
        self.show()

if __name__ == '__main__':
    width, height = 1280, 720
    app = QApplication(sys.argv)
    window = MovingPetsWindow(width, height)
    sys.exit(app.exec())