from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6.QtSql import *
from PyQt6.QtWidgets import *
from abc import ABC, abstractmethod
import random

class Item(QLabel):
    def __init__(self, parent, id, tipo, nombre, cantidad=-1):
        super().__init__(parent)
        self._id = id
        self._tipo = tipo
        self._nombre = nombre
        self._cantidad = cantidad
        self.setPixmap(QPixmap('juguete.png'))
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.move_randomly)
        self.timer.start(random.randint(500, 1000))
        self.move_randomly()

    @abstractmethod
    def usar(self, mascota):
        pass

    def mostrar_item(self):
        print(f"ID: {self._id}, Tipo: {self._tipo}, Nombre: {self._nombre}, Cantidad: {self._cantidad}")

    def get_id(self):
        return self._id

    def get_nombre(self):
        return self._nombre

    def get_tipo(self):
        return self._tipo

    def get_cantidad(self):
        return self._cantidad

    def set_cantidad(self, nueva_cantidad):
        self._cantidad = nueva_cantidad
    
    def move_randomly(self):
        window_width = self.parent().width()
        window_height = self.parent().height()
        new_x = random.randint(0, window_width)
        new_y = random.randint(0, window_height)
        self.move(new_x, new_y)

    
