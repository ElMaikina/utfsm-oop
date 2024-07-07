from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6.QtSql import *
from PyQt6.QtWidgets import *
import Estado
import random
import sys

class Mascota(QLabel):
    def __init__(self, parent, nombre, salud, energia, felicidad):
        super().__init__(parent)
        # Atributos graficos
        self.setPixmap(QPixmap('baby_pou.png'))
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.move_randomly)
        self.timer.start(random.randint(200, 1000))
        self.move_randomly()
        # Atributos logicos
        self.nombre = nombre
        self.salud = salud
        self.energia = energia
        self.felicidad = felicidad
        self.edad = 0
        self.estado = Estado.NEUTRO
        self.actualizar_estado()
    
    def move_randomly(self):
        window_width = self.parent().width()
        window_height = self.parent().height()
        pet_width = self.width()
        pet_height = self.height()
        new_x = random.randint(0, window_width - pet_width)
        new_y = random.randint(0, window_height - pet_height)
        self.move(new_x, new_y)

        
    def penalizar(self):
        if self.edad <= 5 and self.salud <= 10:
            self.felicidad -= 20
        elif 5 < self.edad <= 10 and self.salud <= 50:
            self.felicidad -= 20
            self.energia -= 10
        elif self.edad > 10 and self.salud <= 50:
            self.felicidad -= 30
            self.energia -= 20

        if self.salud < 0:
            self.salud = 0
        if self.energia < 0:
            self.energia = 0
        if self.felicidad < 0:
            self.felicidad = 0

    def pasar_tiempo(self):
        if self.salud > 100:
            self.salud = 100
        self.salud -= 5
        if self.salud < 0:
            self.salud = 0

        if self.energia > 100:
            self.energia = 100
        self.energia -= 5
        if self.energia < 0:
            self.energia = 0

        if self.felicidad > 100:
            self.felicidad = 100
        self.felicidad -= 5
        if self.felicidad < 0:
            self.felicidad = 0

        self.edad += 0.5

    def actualizar_estado(self):
        if self.edad == 15 or self.salud == 0 or self.energia == 0:
            self.estado = Estado.MUERTO
        elif self.energia <= 15:
            self.estado = Estado.CANSADO
        elif self.edad >= 5 and self.salud <= 30 and self.energia <= 30:
            self.estado = Estado.ENOJADO
        elif (self.edad <= 5 and self.salud <= 20) or (5 < self.edad < 10 and self.salud <= 50):
            self.estado = Estado.HAMBRIENTO
        elif self.felicidad <= 20:
            self.estado = Estado.TRISTE
        elif self.felicidad >= 60:
            self.estado = Estado.FELIZ
        else:
            self.estado = Estado.NEUTRO

    def get_estado(self):
        return self.estado

    def mostrar_mascota(self):
        print(f"Nombre: {self.nombre}")
        print(f"Edad: {self.edad}")
        print(f"Salud: {self.salud}")
        print(f"Energía: {self.energia}")
        print(f"Felicidad: {self.felicidad}")
        print(f"Estado: {self.get_estado()}")
        print()
