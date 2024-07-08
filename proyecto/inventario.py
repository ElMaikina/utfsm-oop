from Item import Item
from Mascota import Mascota
from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6.QtSql import *
from PyQt6.QtWidgets import *

class inventario(QLabel):
    def __init__(self, mascota):
         self.items = []
         self.mascota = mascota
    def agregar_item(self, item):
        self.items.append(item)
        

    def buscar_por_id(self, id):
        for item in self.items:
            if item.id == id:
                return item
        return None

    def usar_item(self, id, mascota):
        item = self.buscar_por_id(id)
        if item:
            item.usar(mascota)
            self.items.remove(item)

    def get_items(self):
        return self.items

    def mostrar_inventario(self):
        if not self.items:
            print("El inventario está vacío.")
        else:
            for item in self.items:
                print(item)