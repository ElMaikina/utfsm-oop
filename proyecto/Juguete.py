class Juguete(Item):

    def __init__(self, id, nombre):
        super().__init__(id, "Juguete", nombre)

    def usar(self, mascota):
        if self._cantidad > 0:
            self._cantidad -= 1
        else:
            print(f"No hay más {self._nombre} disponibles.")
