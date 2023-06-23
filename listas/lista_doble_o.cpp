#include <iostream>
using namespace std;
template<typename T>
class List {
private:
    class Node {
    private:
        
        Node* next ,*prev; //los dos punteros     

    public:
   	T* x;
    };
    Node* head;
    Node* tail;
public:
	Node dummy;
	int n;
	
	DLList() {
	dummy.next = &dummy;
	dummy.prev = &dummy;
	n = 0;
	}
    List() {
        head = nullptr;
        tail = nullptr;
        //cout << "Hola desde el constructor de lista" << endl;
    }
    bool empty() {
        return head == nullptr && tail == nullptr;
    }
    void push_back(T elem) {
        Node *n = new Node(elem);
        if(empty()) {
            head = n;
            tail = n;
        } else {
            tail->setNext(n);
            tail = n;
        }
    }
//------------------------implementacion----------------------------
Node* getNode(int i) { //obtener nodo
Node* p;
if (i < n / 2) {
	p = dummy.next;
	for (int j = 0; j < i; j++)
	p = p->next;
} else {
	p = &dummy;
	for (int j = n; j > i; j--)
	p = p->prev;
}
return (p);		
}
T get(int i) { //obtener
	return getNode(i)->x;
}
T set(int i, T x) { //ajuste
	Node* u = getNode(i);
	T y = u->x;
	u->x = x;
	return y;
}
Node* addBefore(Node *w, T x) { // agregar antes
	Node *u = new Node;
	u->x = x;
	u->prev = w->prev;
	u->next = w;
	u->next->prev = u;
	u->prev->next = u;
	n++;
	return u;
}
void remove(Node *w) {
	w->prev->next = w->next;
	w->next->prev = w->prev;
	delete w;
	n--;
}
	T remove(int i) {
		Node *w = getNode(i);
		T x = w->x;
		remove(w);
		return x;
	}
};
int main(){
	
	return 0;
}
//------------------------------------------------------------------------
/*


}*/
