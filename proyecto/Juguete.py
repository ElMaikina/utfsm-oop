from Item import Item
from PyQt6.QtWidgets import QLabel
from PyQt6.QtGui import QPixmap

class Juguete(Item):
    def __init__(self, id, nombre, cantidad=-1):
        super().__init__(id, "Juguete", nombre, cantidad)

    def usar(self, mascota):
        if self._cantidad > 0:
            self._cantidad -= 1
        else:
            print(f"No hay más {self._nombre} disponibles.")
