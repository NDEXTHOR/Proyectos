from articulo import Articulo
from vendedor import Vendedor
from cliente import Cliente

class Venta:

    # Constructora con herencia múltiple
    def __init__(self, ventaId, articuloId, nomArticulo, marca, precio, categoria, 
                 vendedorId, nombreVendedor, apellidosVendedor, edadVendedor, direccionVendedor, celularVendedor, numeroVendedor,
                 clienteId, nombreCliente, apellidosCliente, edadCliente, direccionCliente, celularCliente, numeroCliente, descuento,
                 fecha):
        # Inicializar atributos de Articulo
        self.articulo = Articulo(articuloId, nomArticulo, marca, precio, categoria)
        # Inicializar atributos de Vendedor
        self.vendedor = Vendedor(nombreVendedor, apellidosVendedor, edadVendedor, direccionVendedor, celularVendedor, vendedorId, numeroVendedor)
        # Inicializar atributos de Cliente
        self.cliente = Cliente(nombreCliente, apellidosCliente, edadCliente, direccionCliente, celularCliente, clienteId, numeroCliente, descuento)
        # Inicializar atributos propios de Venta
        self.ventaId = ventaId
        self.fecha = fecha

    # Funciones set
    def set_ventaId(self, ventaId):
        self.ventaId = ventaId

    def set_fecha(self, fecha):
        self.fecha = fecha

    # Funciones get
    def get_ventaId(self):
        return self.ventaId

    def get_fecha(self):
        return self.fecha

    # Funciones
    def detalles(self):
        detalles_articulo = self.articulo.detalles()
        detalles_vendedor = self.vendedor.detalles()
        detalles_cliente = self.cliente.detalles()
        return (
            f"ID de la venta: {self.get_ventaId()}\n"
            f"Fecha de la venta: {self.get_fecha()}\n"
            f"{detalles_articulo}\n"
            f"{detalles_vendedor}\n"
            f"{detalles_cliente}"
        )