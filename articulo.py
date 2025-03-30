class Articulo:

    # Constructora
    def __init__(self, articuloId, nomArticulo, marca, precio, categoria):
        self.articuloId = articuloId
        self.nomArticulo = nomArticulo
        self.marca = marca
        self.precio = precio
        self.categoria = categoria

    # Funciones set
    def set_articuloId(self, articuloId):
        self.articuloId = articuloId

    def set_nomArticulo(self, nomArticulo):
        self.nomArticulo = nomArticulo

    def set_marca(self, marca):
        self.marca = marca

    def set_precio(self, precio):
        self.precio = precio

    def set_categoria(self, categoria):
        self.categoria = categoria

    # Funciones get
    def get_articuloId(self):
        return self.articuloId

    def get_nomArticulo(self):
        return self.nomArticulo

    def get_marca(self):
        return self.marca

    def get_precio(self):
        return self.precio

    def get_categoria(self):
        return self.categoria

    # Funciones
    def detalles(self):
        return (f"ID del artículo: {self.get_articuloId()} \n"
                f"Nombre del artículo: {self.get_nomArticulo()} \n"
                f"Marca: {self.get_marca()} \n"
                f"Precio: {self.get_precio()} \n"
                f"Categoría: {self.get_categoria()}")