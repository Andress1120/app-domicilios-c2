#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 6
#define MAX_CARRITO 20

// Estructura de producto
typedef struct {
    int id;
    char nombre[50];
    float precio;
} Producto;

// Estructura de item en carrito
typedef struct {
    Producto producto;
    int cantidad;
} ItemCarrito;

Producto catalogo[MAX_PRODUCTOS] = {
    {1, "Pizza", 10.0},
    {2, "Hamburguesa", 8.5},
    {3, "Hot Dog", 5.0},
    {4, "Papas Fritas", 3.5},
    {5, "Refresco", 2.0},
    {6, "Helado", 4.0}
};

ItemCarrito carrito[MAX_CARRITO];
int totalItems = 0;

// Función para mostrar productos
void mostrarMenu() {
    printf("\n--- MENU DE PRODUCTOS ---\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        printf("%d. %s - $%.2f\n", catalogo[i].id, catalogo[i].nombre, catalogo[i].precio);
    }
}

// Buscar producto por ID
int buscarProducto(int id) {
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (catalogo[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Agregar al carrito
void agregarAlCarrito() {
    int id, cantidad;
    printf("Ingrese ID del producto: ");
    scanf("%d", &id);

    int index = buscarProducto(id);

    if (index == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Ingrese cantidad: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0) {
        printf("Cantidad invalida.\n");
        return;
    }

    carrito[totalItems].producto = catalogo[index];
    carrito[totalItems].cantidad = cantidad;
    totalItems++;

    printf("Producto agregado al carrito.\n");
}

// Ver carrito
void verCarrito() {
    float subtotal = 0;

    if (totalItems == 0) {
        printf("El carrito esta vacio.\n");
        return;
    }

    printf("\n--- CARRITO ---\n");

    for (int i = 0; i < totalItems; i++) {
        float total = carrito[i].producto.precio * carrito[i].cantidad;
        printf("%s x%d - $%.2f\n",
               carrito[i].producto.nombre,
               carrito[i].cantidad,
               total);
        subtotal += total;
    }

    float impuesto = subtotal * 0.10;
    float totalFinal = subtotal + impuesto;

    printf("Subtotal: $%.2f\n", subtotal);
    printf("Impuesto (10%%): $%.2f\n", impuesto);
    printf("Total: $%.2f\n", totalFinal);
}

// Confirmar pedido
void confirmarPedido() {
    if (totalItems == 0) {
        printf("No hay productos en el carrito.\n");
        return;
    }

    printf("Pedido confirmado. Gracias por su compra!\n");
    totalItems = 0; // Vaciar carrito
}

// Menú principal
int main() {
    int opcion;

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Ver menu de productos\n");
        printf("2. Agregar producto al carrito\n");
        printf("3. Ver carrito y total\n");
        printf("4. Confirmar pedido\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarMenu();
                break;
            case 2:
                agregarAlCarrito();
                break;
            case 3:
                verCarrito();
                break;
            case 4:
                confirmarPedido();
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 5);

    return 0;
}