#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node;
        newNode->data = data;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else {
            Node* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void printForward() {  // mostrar 
        if (head == nullptr) {
            cout << "La lista esta vacia." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    void printBackward() {
        if (head == nullptr) {
            cout << "La lista esta vacia." << endl;
            return;
        }

        Node* current = head->prev;
        do {
            cout << current->data << " ";
            current = current->prev;
        } while (current != head->prev);
        cout << endl;
    }
    
    Node* searchForward(int data) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* current = head;
        do {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        } while (current != head);

        return nullptr;
    }

    Node* searchBackward(int data) { // buscar
        if (head == nullptr) {
            return nullptr;
        }

        Node* current = head->prev;
        do {
            if (current->data == data) {
                return current;
            }
            current = current->prev;
        } while (current != head->prev);

        return nullptr;
    }
    
    bool modifyForward(int oldData, int newData) { //modificar 
        if (head == nullptr) {
            return false;
        }

        Node* current = head;
        do {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
        current = current->next;
        } while (current != head);

        return false;
    }

    bool modifyBackward(int oldData, int newData) {
        if (head == nullptr) {
            return false;
        }

        Node* current = head->prev;
        do {
        	if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->prev;
        } while (current != head->prev);

        return false;
    }
    
    bool deleteForward(int data) { // eliminar
        if (head == nullptr) {
            return false;
        }

        Node* current = head;
        while (current->data != data && current->next != head) {
            current = current->next;
        }

        if (current->data == data) {
            if (current == head) {
                head = head->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return true;
        }

        return false;
    }

    bool deleteBackward(int data) {
        if (head == nullptr) {
            return false;
        }

        Node* current = head->prev;
        while (current->data != data && current->prev != head->prev) {
            current = current->prev;
        }

        if (current->data == data) {
            if (current == head) {
                head = head->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return true;
        }

        return false;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(10);
	
	//mostrar
    cout << "Lista en orden directo: ";
    list.printForward();

    cout << "Lista en orden inverso: ";
    list.printBackward();
	
	// buscar
	 Node* node1 = list.searchForward(10);
    if (node1 != nullptr) {
        cout << "El elemento 3 esta en la lista." << endl;
    }
    else {
        cout << "El elemento 3 no esta en la lista." << endl;
    }

    Node* node2 = list.searchBackward(1);
    if (node2 != nullptr) {
        cout << "El elemento 3 esta en la lista." << endl;
    }
    else {
        cout << "El elemento 3 no esta en la lista." << endl;
    }
	//modificar
	bool modified1 = list.modifyForward(3, 6);
    if (modified1) {
        cout << "Se modifico el elemento 3 en la lista a 6." << endl;
    }
    else {
        cout << "No se encontro el elemento 3 en la lista." << endl;
    }

    bool modified2 = list.modifyBackward(6, 7);
    if (modified2) {
        cout << "Se modifico el elemento 6 en la lista a 7." << endl;
    }
    else {
        cout << "No se encontro el elemento 6 en la lista." << endl;
    }
	
	//eliminar
	bool deleted1 = list.deleteForward(2);
    if (deleted1) {
        cout << "Se elimino el elemento 2 en la lista." << endl;
    }
    else {
        cout << "No se encontro el elemento 2 en la lista." << endl;
    }

    bool deleted2 = list.deleteBackward(5);
    if (deleted2) {
        cout << "Se elimino el elemento 5 en la lista." << endl;
    }
    else {
        cout << "No se encontro el elemento 5 en la lista." << endl;
    }
    
    cout << "Lista en orden directo: ";
    list.printForward();
    cout << "Lista en orden inverso: ";
    list.printBackward();
    
    return 0;
}
