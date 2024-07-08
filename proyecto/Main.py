# Librerias externas
from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6.QtSql import *
from PyQt6.QtWidgets import *
import sys

# Clases internas
from Mascota import Mascota
import Personalidad as person
import Nombres as name

class MovingPetsWindow(QWidget):
    def __init__(self, width, height):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.setWindowTitle('Granja de Pou')
        self.setGeometry(100, 100, width, height)

        # Establecer el layout para la ventana
        self.layout = QVBoxLayout()
        self.setLayout(self.layout)

        # Crear y configurar la etiqueta para la imagen de fondo
        self.background_label = QLabel(self)
        self.background_pixmap = QPixmap('background.jpg')  # Reemplaza 'background.jpg' con la ruta a tu imagen de fondo
        self.background_label.setPixmap(self.background_pixmap)
        self.background_label.setGeometry(0, 0, self.width(), self.height())
        self.background_label.lower()  # Enviar la etiqueta al fondo

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