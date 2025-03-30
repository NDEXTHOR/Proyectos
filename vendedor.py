from persona import Persona

class Vendedor(Persona):

    # Constructora
    def __init__(self, nombre, apellidos, edad, direccion, celular, vendedorId, numeroVendedor):
        super().__init__(nombre, apellidos, edad, direccion, celular)
        self.vendedorId = vendedorId 
        self.numeroVendedor = numeroVendedor

    # Funciones set
    def set_vendedorId(self, vendedorId):
        self.vendedorId = vendedorId

    def set_numeroVendedor(self, numeroVendedor):
        self.numeroVendedor = numeroVendedor

    # Funciones get
    def get_vendedorId(self):
        return self.vendedorId

    def get_numeroVendedor(self):
        return self.numeroVendedor

    # Funciones
    def detalles(self):
        detalles_persona = super().detalles()  # Llama al método detalles de Persona
        return (f"{detalles_persona} \n"
                f"ID del vendedor: {self.get_vendedorId()} \n"
                f"Numero de vendedor: {self.get_numeroVendedor()}")