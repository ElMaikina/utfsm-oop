from PyQt6.QtWidgets import QLabel
from PyQt6.QtGui import QPixmap

class JugueteWidget(QLabel):
    def __init__(self, parent, juguete, imagen_path='juguete.png'):
        super().__init__(parent)
        self.juguete = juguete
        self.setPixmap(QPixmap(imagen_path))
        self.adjustSize()
