#include <iostream>

using namespace std;

template <typename T>
class BlockList {
private:
    class Node {
    private:
        T* data;
        unsigned int sz;
        Node* next;
        Node* prev;
    public:
        Node() : sz(0), next(nullptr), prev(nullptr) {
            data = new T[3];
            cout << "se llamo" << endl;
        }
        unsigned int size() { return sz; }
        void push_back(T elem) {
            data[sz] = elem;
            sz++;
        }
        void pop_back() { sz--; }
        bool empty() { return sz == 0; }
        bool hasSpace() { return sz < 3; }
        void print() {
            cout << "-----" << endl;
            cout << "\tprev:" << prev << endl;
            for(unsigned int i = 0 ; i < 3; i++) {
                if (i < sz) {
                    cout << " " << data[i];
                } else {
                    cout << " XXX";
                }
            }
            cout << endl << "\tsize:" << sz << endl;
            cout << endl << "\tnext:" << next << endl;
            cout<< endl << "-----" << endl;
        }
        void setNext(Node* n) { next = n; }
        void setPrev(Node* n) { prev = n; }
        Node* getNext() { return next; }
        Node* getPrev() { return prev; }
    };

    Node* head;
    Node* tail;
public:
    BlockList() : head(nullptr), tail(nullptr) {}
    bool empty() { return head == nullptr && tail == nullptr; }
    void push_back(T elem) {
        if(empty()) {
            Node* a = new Node();
            a->push_back(elem);
            head = a;
            tail = a;
        } else {
            if(tail->hasSpace()) {
                tail->push_back(elem);
            } else {
                Node *a = new Node();
                a->push_back(elem);
                tail->setNext(a);
                a->setPrev(tail);
                tail = a;
            }
        }
    }
    void pop_back() {
        if(empty()) return;
        tail->pop_back();
        if(tail->empty()) {
            cout << "Por aqui" << endl;
            if(tail->getPrev() != nullptr) {
                tail->getPrev()->setNext(nullptr);
                Node* n = tail;
                tail = tail->getPrev();
                delete n;
            } else {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
        }
    }
    void print() {
        Node *t = head;
        while(head != nullptr) {
            t->print();
            t = t->getNext();
            cout << endl;
        }
    }
};

int main()
{
    BlockList<int> l;
    l.push_back(10);
    l.push_back(100);
    l.push_back(1000);
    l.push_back(20);
    l.push_back(200);
    l.push_back(2000);
   
   
    l.print();
    /*
   
   

   
    l.print();
    cout << l.empty() << endl;
    */
    return 0;
}

