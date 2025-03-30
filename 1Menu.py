from articulo import Articulo
from proveedor import Proveedor 
from vendedor import Vendedor
from cliente import Cliente
from venta import Venta
import os#Para limpiar y pausar la terminal
from datetime import date#Para obtener la fecha de hoy

menu = "1)Agregar un artículo\n" \
       "2) Agregar un vendedor\n" \
       "3) Agregar un provedor\n" \
       "4) Agregar un cliente\n" \
       "5) Agregar una venta\n" \
       "------------------------------------\n" \
       "6) Eliminar un artículo\n" \
       "7) Eliminar un vendedor\n" \
       "8) Eliminar un proveedor\n" \
       "9) Eliminar un cliente\n" \
       "10) Eliminar una venta\n" \
       "------------------------------------\n" \
       "11) Listar artículos\n" \
       "12) Listar vendedores\n" \
       "13) Listar provedores\n" \
       "14) Listar clientes\n" \
       "15) Listar ventas\n" \
       "------------------------------------\n" \
       "16) Salir\n"

# Arreglos para almacenar los objetos
articulosArr = []
vendedoresArr = []
clientesArr = []
provedorArr = []
ventasArr = []

# Agregar 5 artículos
articulosArr.append(Articulo("001", "Laptop", "Dell", 15000, "Electrónica"))
articulosArr.append(Articulo("002", "Celular", "Samsung", 10000, "Electrónica"))
articulosArr.append(Articulo("003", "Teclado", "Logitech", 800, "Accesorios"))
articulosArr.append(Articulo("004", "Mouse", "Razer", 1200, "Accesorios"))
articulosArr.append(Articulo("005", "Monitor", "LG", 5000, "Electrónica"))

# Agregar 5 vendedores
vendedoresArr.append(Vendedor("V001", "Carlos", "Hernandez", 30, "Calle 1", "1234567890", 101))
vendedoresArr.append(Vendedor("V002", "Ana", "Lopez", 25, "Calle 2", "0987654321", 102))
vendedoresArr.append(Vendedor("V003", "Luis", "Martinez", 35, "Calle 3", "1122334455", 103))
vendedoresArr.append(Vendedor("V004", "Maria", "Gomez", 28, "Calle 4", "5566778899", 104))
vendedoresArr.append(Vendedor("V005", "Pedro", "Ramirez", 40, "Calle 5", "6677889900", 105))

# Agregar 5 proveedores
provedorArr.append(Proveedor("P001", "Proveedor1", "Apellido1", 45, "Calle A", "1111111111", 201, "Empresa1"))
provedorArr.append(Proveedor("P002", "Proveedor2", "Apellido2", 50, "Calle B", "2222222222", 202, "Empresa2"))
provedorArr.append(Proveedor("P003", "Proveedor3", "Apellido3", 38, "Calle C", "3333333333", 203, "Empresa3"))
provedorArr.append(Proveedor("P004", "Proveedor4", "Apellido4", 42, "Calle D", "4444444444", 204, "Empresa4"))
provedorArr.append(Proveedor("P005", "Proveedor5", "Apellido5", 39, "Calle E", "5555555555", 205, "Empresa5"))

# Agregar 5 clientes
clientesArr.append(Cliente("C001", "Juan", "Perez", 30, "Calle X", "6666666666", 301, 10))
clientesArr.append(Cliente("C002", "Laura", "Garcia", 27, "Calle Y", "7777777777", 302, 15))
clientesArr.append(Cliente("C003", "Miguel", "Sanchez", 35, "Calle Z", "8888888888", 303, 20))
clientesArr.append(Cliente("C004", "Sofia", "Diaz", 29, "Calle W", "9999999999", 304, 5))
clientesArr.append(Cliente("C005", "Diego", "Fernandez", 33, "Calle V", "0000000000", 305, 25))

# Agregar 5 ventas
ventasArr.append(Venta("V001", "001", "Laptop", "Dell", 15000, "Electrónica",
                       "V001", "Carlos", "Hernandez", 30, "Calle 1", "1234567890", 101,
                       "C001", "Juan", "Perez", 30, "Calle X", "6666666666", 301, 10, str(date.today())))
ventasArr.append(Venta("V002", "002", "Celular", "Samsung", 10000, "Electrónica",
                       "V002", "Ana", "Lopez", 25, "Calle 2", "0987654321", 102,
                       "C002", "Laura", "Garcia", 27, "Calle Y", "7777777777", 302, 15, str(date.today())))
ventasArr.append(Venta("V003", "003", "Teclado", "Logitech", 800, "Accesorios",
                       "V003", "Luis", "Martinez", 35, "Calle 3", "1122334455", 103,
                       "C003", "Miguel", "Sanchez", 35, "Calle Z", "8888888888", 303, 20, str(date.today())))
ventasArr.append(Venta("V004", "004", "Mouse", "Razer", 1200, "Accesorios",
                       "V004", "Maria", "Gomez", 28, "Calle 4", "5566778899", 104,
                       "C004", "Sofia", "Diaz", 29, "Calle W", "9999999999", 304, 5, str(date.today())))
ventasArr.append(Venta("V005", "005", "Monitor", "LG", 5000, "Electrónica",
                       "V005", "Pedro", "Ramirez", 40, "Calle 5", "6677889900", 105,
                       "C005", "Diego", "Fernandez", 33, "Calle V", "0000000000", 305, 25, str(date.today())))


while True:
    opcion = input(f"{menu} Seleccione una opción: ")

    # Agregar
    if opcion == "1":
        print("Agregar un artículo")
        IdArt = input("ID del artículo (ej. A001): ")
        NomArt = input("Nombre del artículo: ")
        Marca = input("Marca: ")
        # Validar que el precio sea mayor a 0
        while True:
            Precio = float(input("Precio: "))
            if Precio > 0:
                break
            else:
                print("El precio debe ser mayor a 0")
        # Aquí acaba la validación
        Categoria = input("Categoria: ")
        articulosArr.append(Articulo(IdArt, NomArt, Marca, Precio, Categoria))
        # Limpiar la terminal
        os.system('cls')
        print(f"---Artículo agregado--- \n{articulosArr[-1].detalles()}")
        # Pausar la terminal
        os.system('pause')
        # Limpiar la terminal
        os.system('cls')
    elif opcion == "2":
        print("Agregar un vendedor")
        IdVen = input("ID del vendedor (ej. V001): ")
        NomVen = input("Nombre del vendedor: ")
        ApelVen = input("Apellidos del vendedor: ")
        # Validar que la edad sea mayor a 0 y menor a 70
        while True:
            EdadVen = int(input("Edad del vendedor: "))
            if 0 < EdadVen < 70:
                break
            else:
                print("La edad debe ser mayor a 0 y menor a 70")
        # Aquí acaba la validación
        DirecVen = input("Dirección del vendedor: ")
        # Validar que el celular tenga 10 dígitos
        while True:
            CelVen = input("Celular del vendedor: ")
            if len(CelVen) == 10:
                break
            else:
                print("El número de vendedor debe tener 10 dígitos")
        # Aquí acaba la validación
        # Validar que el número de vendedor sea mayor a 0
        while True:
            NumVen = int(input("Número de vendedor: "))
            if NumVen > 0:
                break
            else:
                print("El número de vendedor debe ser mayor a 0")
        # Aquí acaba la validación
        vendedoresArr.append(Vendedor(IdVen, NomVen, ApelVen, EdadVen, DirecVen, CelVen, NumVen))
        # Limpiar la terminal
        os.system('cls')
        print(f"---Vendedor agregado--- \n{vendedoresArr[-1].detalles()}")
        # Pausar la terminal
        os.system('pause')
        # Limpiar la terminal
        os.system('cls')
    elif opcion == "3":
        print("Agregar un provedor")
        IdProv = input("ID del provedor (ej. P001): ")
        NomProv = input("Nombre del provedor: ")
        ApelProv = input("Apellidos del provedor: ")
        # Validar que la edad sea mayor a 0 y menor a 70
        while True:
            EdadProv = int(input("Edad del provedor: "))
            if 0 < EdadProv < 70:
                break
            else:
                print("La edad debe ser mayor a 0 y menor a 70")
        # Aquí acaba la validación
        DirecProv = input("Dirección del provedor: ")
        # Validar que el celular tenga 10 dígitos
        while True:
            CelProv = input("Celular del provedor: ")
            if len(CelProv) == 10:
                break
            else:
                print("El número de provedor debe tener 10 dígitos")
        # Aquí acaba la validación
        # Validar que el número de provedor sea mayor a 0
        while True:
            NumProv = int(input("Número de provedor: "))
            if NumProv > 0:
                break
            else:
                print("El número de provedor debe ser mayor a 0")
        # Aquí acaba la validación
        provedorArr.append(Proveedor(IdProv, NomProv, ApelProv, EdadProv, DirecProv, CelProv, NumProv, "Empresa"))
        # Limpiar la terminal
        os.system('cls')
        print(f"---Provedor agregado--- \n{provedorArr[-1].detalles()}")
        # Pausar la terminal
        os.system('pause')
        # Limpiar la terminal
        os.system('cls')
    elif opcion == "4":
        print("Agregar un cliente")
        IdCli = input("ID del cliente (ej. C001): ")
        NomCli = input("Nombre del cliente: ")
        ApelCli = input("Apellidos del cliente: ")
        # Validar que la edad sea mayor a 0 y menor a 70
        while True:
            EdadCli = int(input("Edad del cliente: "))
            if 0 < EdadCli < 70:
                break
            else:
                print("La edad debe ser mayor a 0 y menor a 70")
        # Aquí acaba la validación
        DirecCli = input("Dirección del cliente: ")
        # Validar que el celular tenga 10 dígitos
        while True:
            CelCli = input("Celular del cliente: ")
            if len(CelCli) == 10:
                break
            else:
                print("El número de cliente debe tener 10 dígitos")
        # Aquí acaba la validación
        # Validar que el número de cliente sea mayor a 0
        while True:
            NumCli = int(input("Número de cliente: "))
            if NumCli > 0:
                break
            else:
                print("El número de cliente debe ser mayor a 0")
        # Aquí acaba la validación
        # Validar que el descuento sea mayor o igual a 0 y menor a 100
        while True:
            Descuento = int(input("Descuento %: "))
            if 0 <= Descuento < 100:
                break
            else:
                print("El descuento debe ser mayor o igual a 0 y menor a 100")
        # Aquí acaba la validación
        clientesArr.append(Cliente(IdCli, NomCli, ApelCli, EdadCli, DirecCli, CelCli, NumCli, Descuento))
        # Limpiar la terminal
        os.system('cls')
        print(f"---Cliente agregado--- \n{clientesArr[-1].detalles()}")
        # Pausar la terminal
        os.system('pause')
        # Limpiar la terminal
        os.system('cls')
    elif opcion == "5":
        print("Agregar una venta")
        IdVen = input("ID de la venta (ej. Ven001): ")
        #Mostrasmos articulos, vendedores y clientes para seleccionar uno
        # Mostrar artículos
        print("Artículos disponibles:")
        for i, articulo in enumerate(articulosArr):
            print(f"{i + 1}) {articulo.nomArticulo}")
        # Seleccionar artículo
        articulo_seleccionado = int(input("Seleccione el número del artículo: ")) - 1
        # Validar que el artículo seleccionado sea válido
        while True:
            if 0 <= articulo_seleccionado < len(articulosArr):
                #Obtener los datos del artículo seleccionado
                articulo = articulosArr[articulo_seleccionado]
                articuloId = articulo.articuloId
                nomArticulo = articulo.nomArticulo
                marca = articulo.marca
                precio = articulo.precio
                categoria = articulo.categoria
                break
            else:
                print("Número de artículo no válido, intente de nuevo")
        # Aquí acaba la validación
        # Mostrar vendedores
        print("Vendedores disponibles:")
        for i, vendedor in enumerate(vendedoresArr):
            print(f"{i + 1}) {vendedor.nombre}")
        # Seleccionar vendedor
        vendedor_seleccionado = int(input("Seleccione el número del vendedor: ")) - 1
        # Validar que el vendedor seleccionado sea válido
        while True:
            if 0 <= vendedor_seleccionado < len(vendedoresArr):
                # Obtener los datos del vendedor seleccionado
                vendedor = vendedoresArr[vendedor_seleccionado]
                vendedorId = vendedor.vendedorId
                nombreVendedor = vendedor.nombre
                apellidosVendedor = vendedor.apellidos
                edadVendedor = vendedor.edad
                direccionVendedor = vendedor.direccion
                celularVendedor = vendedor.celular
                numeroVendedor = vendedor.numeroVendedor
                break
            else:
                print("Número de vendedor no válido, intente de nuevo")
        # Aquí acaba la validación
        # Mostrar clientes
        print("Clientes disponibles:")
        for i, cliente in enumerate(clientesArr):
            print(f"{i + 1}) {cliente.nombre}")
        # Seleccionar cliente
        cliente_seleccionado = int(input("Seleccione el número del cliente: ")) - 1
        # Validar que el cliente seleccionado sea válido
        while True:
            if 0 <= cliente_seleccionado < len(clientesArr):
                # Obtener los datos del cliente seleccionado
                cliente = clientesArr[cliente_seleccionado]
                clienteId = cliente.clienteId
                nombreCliente = cliente.nombre
                apellidosCliente = cliente.apellidos
                edadCliente = cliente.edad
                direccionCliente = cliente.direccion
                celularCliente = cliente.celular
                numeroCliente = cliente.numeroCliente
                descuento = cliente.descuento
                break
            else:
                print("Número de cliente no válido, intente de nuevo")
        # Aquí acaba la validación
        # Ontendra la fecha de el dia que se agrego la venta
        fecha = str(date.today())
        # Crear la venta
        ventasArr.append(Venta(IdVen, articuloId, nomArticulo, marca, precio, categoria,
                               vendedorId, nombreVendedor, apellidosVendedor, edadVendedor, direccionVendedor, celularVendedor, numeroVendedor,
                               clienteId, nombreCliente, apellidosCliente, edadCliente, direccionCliente, celularCliente, numeroCliente, descuento,
                               fecha))
        # Limpiar la terminal
        os.system('cls')
        print(f"---Venta agregada--- \n{ventasArr[-1].detalles()}")
        # Pausar la terminal
        os.system('pause')
        # Limpiar la terminal
        os.system('cls')

    # Eliminar
    elif opcion == "6":
        print("Eliminar un artículo")
        # Mostrar artículos
        for i, articulo in enumerate(articulosArr):
            print(f"{i + 1}) {articulo.nomArticulo} {articulo.articuloId} {articulo.marca}")
        # Seleccionar artículo a eliminar
        articulo_eliminar = int(input("Seleccione el número del artículo a eliminar: ")) - 1
        if 0 <= articulo_eliminar < len(articulosArr):
            articulosArr.pop(articulo_eliminar)
            print("Artículo eliminado")
    elif opcion == "7":
        print("Eliminar un vendedor")
        # Mostrar vendedores
        for i, vendedor in enumerate(vendedoresArr):
            print(f"{i + 1}) {vendedor.nombre} {vendedor.vendedorId} {vendedor.numeroVendedor}")
        # Seleccionar vendedor a eliminar
        vendedor_eliminar = int(input("Seleccione el número del vendedor a eliminar: ")) - 1
        if 0 <= vendedor_eliminar < len(vendedoresArr):
            vendedoresArr.pop(vendedor_eliminar)
            print("Vendedor eliminado")
    elif opcion == "8":
        print("Eliminar un provedor")
        # Mostrar provedores
        for i, provedor in enumerate(provedorArr):
            print(f"{i + 1}) {provedor.nombre} {provedor.proveedorId} {provedor.numeroProveedor}")
        # Seleccionar provedor a eliminar
        provedor_eliminar = int(input("Seleccione el número del provedor a eliminar: ")) - 1
        if 0 <= provedor_eliminar < len(provedorArr):
            provedorArr.pop(provedor_eliminar)
            print("Provedor eliminado")
    elif opcion == "9":
        print("Eliminar un cliente")
        # Mostrar clientes
        for i, cliente in enumerate(clientesArr):
            print(f"{i + 1}) {cliente.nombre}")
        # Seleccionar cliente a eliminar
        cliente_eliminar = int(input("Seleccione el número del cliente a eliminar: ")) - 1
        if 0 <= cliente_eliminar < len(clientesArr):
            clientesArr.pop(cliente_eliminar)
            print("Cliente eliminado")
    elif opcion == "10":
        print("Eliminar una venta")
        # Mostrar ventas
        for i, venta in enumerate(ventasArr):
            print(f"{i + 1}) {venta.fecha}")
        # Seleccionar venta a eliminar
        venta_eliminar = int(input("Seleccione el número de la venta a eliminar: ")) - 1
        if 0 <= venta_eliminar < len(ventasArr):
            ventasArr.pop(venta_eliminar)
            print("Venta eliminada")

    # Listar
    elif opcion == "11":
        #Limpiar la terminal
        os.system('cls')
        # Mostrar artículos
        print("Listar artículos")
        for articulo in articulosArr:
            print(articulo.detalles())
            #Para que haya separacion entre articulos
            print("-" * 20)
        # Pausar la terminal
        os.system('pause')
    elif opcion == "12":
        #Limpiar la terminal
        os.system('cls')
        print("Listar vendedores")
        for vendedor in vendedoresArr:
            print(vendedor.detalles())
        # Pausar la terminal
        os.system('pause')
    elif opcion == "13":
        #Limpiar la terminal
        os.system('cls')
        #Limpiar la terminal
        os.system('cls')
        # Mostrar provedores
        print("Listar provedores")
        for provedor in provedorArr:
            print(provedor.detalles())
        # Pausar la terminal
        os.system('pause')
    elif opcion == "14":
        #Limpiar la terminal
        os.system('cls')
        # Mostrar clientes
        print("Listar clientes")
        for cliente in clientesArr:
            print(cliente.detalles())
        # Pausar la terminal
        os.system('pause')
    elif opcion == "15":
        #Limpiar la terminal
        os.system('cls')
        # Mostrar ventas
        print("Listar ventas")
        for venta in ventasArr:
            print(venta.detalles())
        # Pausar la terminal
        os.system('pause')

    # Salir
    elif opcion == "16":
        print("Saliendo...")
        break

    # Opción no válida
    else:
        print("Opción no válida, intente de nuevo.")
        # Pausar la terminal
        os.system('pause')
        # Limpiar la terminal
        os.system('cls')
    
    #liimpiar la terminal
    os.system('cls')
    # Fin del ciclo while