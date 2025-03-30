from persona import Persona

class Proveedor(Persona):

    # Constructora
    def __init__(self, nombre, apellidos, edad, direccion, celular, proveedorId, numeroProveedor, empresa):
        super().__init__(nombre, apellidos, edad, direccion, celular)
        self.proveedorId = proveedorId
        self.numeroProveedor = numeroProveedor
        self.empresa = empresa

    # Funciones set
    def set_proveedorId(self, proveedorId):
        self.proveedorId = proveedorId

    def set_numeroProveedor(self, numeroProveedor):
        self.numeroProveedor = numeroProveedor

    def set_empresa(self, empresa):
        self.empresa = empresa

    # Funciones get
    def get_proveedorId(self):
        return self.proveedorId

    def get_numeroProveedor(self):
        return self.numeroProveedor

    def get_empresa(self):
        return self.empresa

    # Funciones
    def detalles(self):
        detalles_persona = super().detalles()  # Llama al método detalles de Persona
        return (f"{detalles_persona} \n"
                f"ID del proveedor: {self.get_proveedorId()} \n"
                f"Numero de proveedor: {self.get_numeroProveedor()} \n"
                f"Empresa: {self.get_empresa()}")