#include <iostream>
using namespace std;
class Vector2 {
private:
    int* storage; //arreglo para almacenar elementos del vector.
    int sz; //cuantos elementos tiene el vector actualmente.
    int capacity; //cuantos elementos puede almacenar el vector sin redimencionarse

public:
	int at(int pos) {
        return storage[pos];
    }
   
  Vector2(){
      capacity = 5;
      storage= new int[capacity];
      sz = 0;
  }
  int size(){
      return sz;
  }
 /* void push_bac(Vector2 v){
      resize(v.size());
      for( int i =0; i<v.size();i++){
          push_bac(v.at(i));
      }
  }*/
  void resize(int c){
      if(c>(capacity-sz)){
          int nc=sz+c;
          
      }
  }
};
class Vector {
private:
    int* storage; //arreglo para almacenar elementos del vector.
    int sz; //cuantos elementos tiene el vector actualmente.
    int capacity; //cuantos elementos puede almacenar el vector sin redimencionarse

public:
  Vector(){
      capacity = 5;
      storage= new int[capacity];
      sz = 0;
  }
  int size(){
      return sz;
  }
  /*-------------insertar Vector--------------------------
  void push_vector(Vector x){
      if (sz == capacity){
          resize();
      }
      storage[sz] = Vector2;
      sz = sz + 1;
    }
    ----------------------------------------*/

    int waste(){
        return capacity - sz;
    }
   
    int at(int pos) {
        return storage[pos];
    }
   
    
//-------------insertar--------------------------
    void  insertar(int elem, int pos){
     if (sz == capacity){
          resize();
      }
 
	  for(int i = sz; i > pos ; i--){
	  
			storage[i] = storage[i-1];	
	  }
 
      storage[pos] = elem;
      sz = sz + 1;
	}

private:
    void resize(){
        cout << "han hecho un resize" << endl;
        int newcapacity = capacity * 1.5;
        int* ns = new int[newcapacity];
        for(int i=0; i< sz; i++){
            ns[i] = storage[i];
        }
        delete [] storage;
        storage = ns;
        capacity = newcapacity;
    }
public:
    void printInfo() {
        cout << "Storage: " << storage << endl
             << "Size: "    << sz << endl
             << "Capacity: " << capacity << endl << endl;
    }
   
};

int main(){
    Vector a;
    Vector b;
    cout << a.size() << endl;
    for(int i=0; i<5; i++){
        a.push_back(i*10);
    }
   
    
    /*a.push_vector(b);
     for(int i = 0; i < a.size(); i++) {
        cout << "-" << a.at(i);
       
    }
    cout << endl;*/
    return 0;
}
