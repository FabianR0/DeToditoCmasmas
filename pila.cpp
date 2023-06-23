//"push": para ingresar elementos a la pila.
//"pop": para eliminar el último elemento ingresado a la pila.
//"top": para mostrar el último elemento ingresado a la pila.
//"show": para mostrar todos los elementos de la pila en el orden en que fueron ingresados.
//"invertirPila": para mostrar todos los elementos de la pila en el orden inverso en que fueron ingresados.
//"contarPrimos": para contar cuántos números primos hay en la pila.
//"contarPares": para contar cuántos números pares hay en la pila.


#include <iostream>
#include <stack>
using namespace std;

class Pila {
private:
    stack<int> pila;
public:
    void push(int valor) {
        pila.push(valor);
    }
    void pop() {
        pila.pop();
    }
    int top() {
        return pila.top();
    }
    void show() {
        stack<int> pilaAux = pila;
        while (!pilaAux.empty()) {
            cout << pilaAux.top() << " ";
            pilaAux.pop();
        }
        cout << endl;
    }
    void invertirPila() {
        stack<int> pilaAux = pila;
        while (!pilaAux.empty()) {
            cout << pilaAux.top() << " ";
            pilaAux.pop();

	}

	}
};
bool esPrimo(int num) {
    if(num < 2) return false;
    for(int i=2; i*i<=num; i++) {
        if(num%i == 0) return false;
    }
    return true;
}

void contarPrimosYPares(stack<int> numeros) {
    int cantPrimos = 0, cantPares = 0;
    while(!numeros.empty()) {
        int num = numeros.top();
        numeros.pop();
        if(esPrimo(num)) cantPrimos++;
        if(num % 2 == 0) cantPares++;
    }
    cout << "Cantidad de numeros primos: " << cantPrimos << endl;
    cout << "Cantidad de numeros pares: " << cantPares << endl;
}
int main() {
    stack<int> numeros;
    numeros.push(5);
    numeros.push(7);
    numeros.push(8);
    numeros.push(11);
    numeros.push(12);

    contarPrimosYPares(numeros);

    return 0;
}

