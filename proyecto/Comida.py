class Comida(Item):

    def __init__(self, id, nombre, cantidad):
        super().__init__(id, "Comida", nombre, cantidad)

    def usar(self, mascota):
        if self._cantidad > 0:
            self._cantidad -= 1
        else:
            print(f"No hay más {self._nombre} disponibles.")
