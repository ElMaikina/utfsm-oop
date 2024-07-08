from abc import ABC, abstractmethod

class Item(ABC):
    def __init__(self, id, tipo, nombre, cantidad=-1):
        self._id = id
        self._tipo = tipo
        self._nombre = nombre
        self._cantidad = cantidad

    def __del__(self):
        pass  # Destructor

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
