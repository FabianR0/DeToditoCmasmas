#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;
};

Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = new Nodo{valor, nullptr, nullptr};
    return nuevoNodo;
}

void agregarNodo(Nodo*& raiz, int valor) {
    if (raiz == nullptr) {
        raiz = crearNodo(valor);
    } else if (valor < raiz->valor) {
        agregarNodo(raiz->izquierda, valor);
    } else {
        agregarNodo(raiz->derecha, valor);
    }
}

void mostrarArbol(Nodo* raiz, int nivel = 0) {
    if (raiz == nullptr) return;
    mostrarArbol(raiz->derecha, nivel + 1);
    cout << string(nivel * 4, ' ') << raiz->valor << endl;
    mostrarArbol(raiz->izquierda, nivel + 1);
}

Nodo* buscarNodo(Nodo* raiz, int valor) {
    if (raiz == nullptr || raiz->valor == valor) {
        return raiz;
    }
    return buscarNodo(valor < raiz->valor ? raiz->izquierda : raiz->derecha, valor);
}

void recorridoPreorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->valor << " ";
    recorridoPreorden(raiz->izquierda);
    recorridoPreorden(raiz->derecha);
}

void recorridoInorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    recorridoInorden(raiz->izquierda);
    cout << raiz->valor << " ";
    recorridoInorden(raiz->derecha);
}

void recorridoPostorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    recorridoPostorden(raiz->izquierda);
    recorridoPostorden(raiz->derecha);
    cout << raiz->valor << " ";
}

Nodo* encontrarSucesor(Nodo* nodo) {
    Nodo* actual = nodo->derecha;
    while (actual && actual->izquierda) {
        actual = actual->izquierda;
    }
    return actual;
}

void eliminarNodo(Nodo*& raiz, int valor) {
    if (raiz == nullptr) return;
    if (valor < raiz->valor) {
        eliminarNodo(raiz->izquierda, valor);
    } else if (valor > raiz->valor) {
        eliminarNodo(raiz->derecha, valor);
    } else {
        if (raiz->izquierda == nullptr) {
            Nodo* temporal = raiz->derecha;
            delete raiz;
            raiz = temporal;
        } else if (raiz->derecha == nullptr) {
            Nodo* temporal = raiz->izquierda;
            delete raiz;
            raiz = temporal;
        } else {
            Nodo* sucesor = encontrarSucesor(raiz);
            raiz->valor = sucesor->valor;
            eliminarNodo(raiz->derecha, sucesor->valor);
        }
    }
}

void Eliminar(Nodo *&arbol, int n) {
    // Si el árbol está vacío, no hay nada que eliminar
    if (arbol == NULL) {
        return;
    }
    // Si el valor es menor, buscar por la izquierda
    else if (n < arbol->dato) {
        Eliminar(arbol->izquierda, n);
    }
    // Si el valor es mayor, buscar por la derecha
    else if (n > arbol->dato) {
        Eliminar(arbol->derecha, n);
    }
    // Si ya encontró el valor del nodo
    else {
        // Si el nodo tiene dos hijos
        if (arbol->izquierda != NULL && arbol->derecha != NULL) {
            // Encontrar el nodo más pequeño en el subárbol derecho
            Nodo *menor = arbol->derecha;
            while (menor->izquierda != NULL) {
                menor = menor->izquierda;
            }
            // Reemplazar el valor del nodo actual con el valor del nodo más pequeño
            arbol->dato = menor->dato;
            // Eliminar el nodo más pequeño
            Eliminar(arbol->derecha, menor->dato);
        }
        // Si el nodo tiene un hijo o ninguno
        else {
            // Guardar el nodo actual en una variable temporal
            Nodo *temp = arbol;
            // Reemplazar el nodo actual con su hijo (si tiene uno) o con NULL (si no tiene hijos)
            if (arbol->izquierda == NULL) {
                arbol = arbol->derecha;
            }
            else if (arbol->derecha == NULL) {
                arbol = arbol->izquierda;
            }
            else {
                arbol = NULL;
            }
            // Liberar la memoria del nodo eliminado
            delete temp;
        }
    }
}
int main() {
    Nodo* raiz = nullptr;
    int opcion;
    do {
        cout << "Ingrese una opción:\n";
        cout << "1. Agregar nodo\n";
        cout << "2. Mostrar árbol\n";
        cout << "3. Buscar nodo\n";
        cout << "4. Recorrido preorden\n";
        cout << "5. Recorrido inorden\n";
        cout << "6. Recorrido postorden\n";
        cout << "7. Eliminar nodo\n";
        cout << "8. Salir\n";
        cin >> opcion;
        switch(opcion) {
            case 1: {
                int valor;
                cout << "Ingrese el valor del nodo: ";
                cin >> valor;
                agregarNodo(raiz, valor);
                break;
            }
            case 2: {
                mostrarArbol(raiz);
                break;
            }
            case 3: {
                int valor;
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                Nodo* nodo = buscarNodo(raiz, valor);
                cout << (nodo == nullptr ? "No se encontró el nodo\n" : "Se encontró el nodo\n");
                break;
            }
            case 4: {
                recorridoPreorden(raiz);
                cout << endl;
                break;
            }
            case 5: {
                recorridoInorden(raiz);
                cout << endl;
                break;
            }
            case 6: {
                recorridoPostorden(raiz);
                cout << endl;
                break;
            }
            case 7: {
                int valor;
                cout << "Ingrese el valor del nodo a eliminar: ";
                cin >> valor;
                eliminarNodo(raiz, valor);
                break;
            }
            case 8: {
                cout << "Saliendo...\n";
                break;
            }
            default: {
                cout << "Opción inválida\n";
                break;
            }
        }
    } while (opcion != 8);
    return 0;
}
//----------------------------------------------------------------------------------------------
//--------------------------------
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
};

// Función para crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = new Nodo{valor, nullptr, nullptr};
    return nuevoNodo;
}

// Función para insertar un nodo en el árbol
void inser(Nodo*& arbol, int valor, Nodo* padre) {
    if (arbol == nullptr) {
        arbol = crearNodo(valor);
    } else if (valor < arbol->dato) {
        inser(arbol->izq, valor, arbol);
    } else {
        inser(arbol->der, valor, arbol);
    }
}

// Función para mostrar el árbol
void mostrar(Nodo* arbol, int contador) {
    if (arbol == nullptr) return;
    mostrar(arbol->der, contador + 1);
    cout << string(contador * 4, ' ') << arbol->dato << endl;
    mostrar(arbol->izq, contador + 1);
}

// Función para buscar un nodo en el árbol
bool busqueda(Nodo* arbol, int valor, string flag) {
    if (arbol == nullptr) {
        return false;
    }
    if (arbol->dato == valor) {
        if (flag == "0") {
            // Eliminar el nodo
        }
        return true;
    }
    return busqueda(valor < arbol->dato ? arbol->izq : arbol->der, valor, flag);
}

// Función para recorrido en preorden
void preOrden(Nodo* arbol) {
    if (arbol == nullptr) return;
    cout << arbol->dato << " - ";
    preOrden(arbol->izq);
    preOrden(arbol->der);
}

// Función para recorrido en inorden
void inOrden(Nodo* arbol) {
    if (arbol == nullptr) return;
    inOrden(arbol->izq);
    cout << arbol->dato << " - ";
    inOrden(arbol->der);
}

// Función para recorrido en postorden
void postOrden(Nodo* arbol) {
    if (arbol == nullptr) return;
    postOrden(arbol->izq);
    postOrden(arbol->der);
    cout << arbol->dato << " - ";
}

// Función para mostrar el menú y ejecutar las opciones
void menu() {
    Nodo* arbol = nullptr;
    int data, opcion, contador = 0;
    string flag = "1"; // Para no borrar nodo
    do {
        cout << "\tMENU" << endl;
        cout << "\t1. Insertar nodo\n";
        cout << "\t2. Mostrar árbol\n";
        cout << "\t3. Buscar nodo\n";
        cout << "\t4. Recorrido en profundidad PreOrden\n";
        cout << "\t5. Recorrido en profundidad InOrden\n";
        cout << "\t6. Recorrido en profundidad PostOrden\n";
        cout << "\t7. Eliminar un nodo del árbol\n";
        cout << "\t8. Salir" << endl;
        cout << "\tOpción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "\n\tNo inserte datos iguales porque no se evaluaron los casos para eliminar nodos repetidos\n";
                for (int i = 0; i < tamano; i++) {
                    cout << "\tDato [" << i + 1 << "]: ";
                    cin >> data;
                    cout << endl;
                    inser(arbol, data, nullptr);
                }
                system("pause");
                cout << "\n";
                break;
            case 2:
                cout << "\tSe muestra el árbol:\n\n";
                mostrar(arbol, contador);
                cout << "\n";
                system("pause");
                break;
            case 3:
                cout << "\tBusqueda, digite un num: ";
                cin >> data;
                if (busqueda(arbol, data, flag)) {
                    cout << "\tSe encuentra el elemento " << data << endl;
                } else {
                    cout << "\tNo se encuentra\n";
                }
                system("pause");
                break;
            case 4:
                cout << "\tPreOrden:\n\n";
                mostrar(arbol, contador);
                cout << endl;
                preOrden(arbol);
                cout << endl;
                system("pause");
                break;
            case 5:
                cout << "\tInOrden:\n\n";
                mostrar(arbol, contador);
                cout << endl;
                inOrden(arbol);
                cout << endl;
                system("pause");
                break;
            case 6:
                cout << "\tPostOrden:\n\n";
                mostrar(arbol, contador);
                cout << endl;
                postOrden(arbol);
                cout << endl;
                system("pause");
                break;
            case 7:
                flag = "0";
                cout << "\n\tDigite el dato a eliminar: ";
                cin >> data;
                if (busqueda(arbol, data, flag)) {
                    cout << "\tSe encuentra el nodo y se elimina " << data << endl;
                } else {
                    cout << "\tNo se encuentra\n";
                }
                flag = "1";
                system("pause");
                break;
        }
        system("cls");
    } while (opcion != 8);
}

int main() {
    menu();
    return 0;
}

