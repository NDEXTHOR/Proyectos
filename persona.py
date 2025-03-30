class Persona:

    # Constructora
    def __init__(self, nombre, apellidos, edad, direccion, celular):
        self.nombre = nombre
        self.apellidos = apellidos
        self.edad = edad
        self.direccion = direccion
        self.celular = celular

    # Funciones set
    def set_nombre(self, nombre):
        self.nombre = nombre

    def set_apellidos(self, apellidos):
        self.apellidos = apellidos

    def set_edad(self, edad):
        self.edad = edad

    def set_direccion(self, direccion):
        self.direccion = direccion

    def set_celular(self, celular):
        self.celular = celular

    # Funciones get
    def get_nombre(self):
        return self.nombre

    def get_apellidos(self):
        return self.apellidos

    def get_edad(self):
        return self.edad

    def get_direccion(self):
        return self.direccion

    def get_celular(self):
        return self.celular

    # Funciones
    def detalles(self):
        return (f"Nombre: {self.get_nombre()} \n"
                f"Apellidos: {self.get_apellidos()} \n"
                f"Edad: {self.get_edad()} \n"
                f"Direccion: {self.get_direccion()} \n"
                f"Celular: {self.get_celular()}")