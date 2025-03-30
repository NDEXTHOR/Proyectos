from persona import Persona

class Cliente(Persona):

    # Constructora
    def __init__(self, nombre, apellidos, edad, direccion, celular, clienteId, numeroCliente, descuento):
        super().__init__(nombre, apellidos, edad, direccion, celular)
        self.clienteId = clienteId
        self.numeroCliente = numeroCliente
        self.descuento = descuento

    # Funciones set
    def set_clienteId(self, clienteId):
        self.clienteId = clienteId

    def set_numeroCliente(self, numeroCliente):
        self.numeroCliente = numeroCliente

    def set_descuento(self, descuento):
        self.descuento = descuento

    # Funciones get
    def get_clienteId(self):
        return self.clienteId

    def get_numeroCliente(self):
        return self.numeroCliente

    def get_descuento(self):
        return self.descuento

    # Funciones
    def detalles(self):
        detalles_persona = super().detalles()  # Llama al método detalles de Persona
        return (f"{detalles_persona} \n"
                f"ID del cliente: {self.get_clienteId()} \n"
                f"Numero de cliente: {self.get_numeroCliente()} \n"
                f"Descuento %: {self.get_descuento()}")