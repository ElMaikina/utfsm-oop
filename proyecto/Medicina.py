from Item import Item

class Medicina(Item):

    def __init__(self, id, nombre, cantidad,imagen_path=None):
        super().__init__(id, "Medicina", nombre, cantidad)

    def usar(self, mascota):
        if self._cantidad > 0:
            self._cantidad -= 1
        else:
            print(f"No hay más {self._nombre} disponibles.")
