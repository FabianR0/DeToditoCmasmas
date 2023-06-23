#include <iostream>
using namespace std;
class Nodo
{
	public:
		int id;
		Nodo *sig;
		Nodo *ant;
};

void agregar(int);
void presen_I();
void presen_F();
void llenar();
void buscar(int);
void modificar(int);

Nodo *I,*F,*T;
int op,n;

int main(){
	do{
		cout<<"Menu"<<endl;
		cout<<"1) Llenar"<<endl;
		cout<<"2) Presentar Inicio"<<endl;
		cout<<"3) Presentar Final"<<endl;
		cout<<"4) Buscar"<<endl;
		cout<<"0) Salir"<<endl;
		cin>>op;
		
		switch(op){
			case 1:
				llenar();
				break;
			case 2:
				presen_I();
				break;
			case 3:
				presen_F();
				break;
			case 4:
				cout<<"Ingrese el ID a buscar"<<endl;
				cin>>n;
				buscar(n);
				break;
			case 0:
				break;
			default:
				cout<<"Opcion no Valida"<<endl;
		}	
	}while(op!=0);
	/*for(int i=1;i<10;i++){
		agregar(i*10);
	}
	cout<<"Presentar por el Inicio"<<endl;
	presen_I();
	cout<<"Presentar por el Final"<<endl;
	presen_F();*/
	return 0;
}
void agregar(int x)
{
	T= new Nodo(); 
	T->id=x; 
	T->sig=NULL;
	T->ant=NULL;
	
	if(I==NULL){
		I=T;
	}
	else{
		F->sig=T;
		T->ant=F;
	}
	F=T;
}
void presen_I()
{
	T=I;
	while(T!=NULL){
		cout<<"ID: "<<T->id<<endl;
		T=T->sig;
	}
}
void presen_F()
{
	T=F;
		while(T!=NULL){
		cout<<"ID: "<<T->id<<endl;
		T=T->ant;
	}
}
void llenar(){
	for(int i=1;i<10;i++){
		agregar(i*10);
	}
}
void buscar(int x){
	bool encontre=false;
	if(x>F->id/2){
		T=F;
		while(T!=NULL && !encontre){
			cout<<T->id<<endl;//verificar por donde va
			if(T->id==x){
				encontre=true;
				cout<<"Registro Encontrado"<<endl;
			}
			else{
				T=T->ant;
			}
		}
	}
	else{
		T=I;
		while(T!=NULL && !encontre){
			cout<<T->id<<endl;//verificar por donde va
			if(T->id==x){
				encontre=true;
				cout<<"Registro Encontrado"<<endl;
			}
			else{
				T=T->sig;
			}
		}
	}
	if(!encontre){
		cout<<"Registro no existe"<<endl;
	}		
}
void modificar(int x){
	
}	
