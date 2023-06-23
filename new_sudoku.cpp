#include <iostream> 
#include <vector>
#include <iomanip> //libreria de setw
using namespace std;

int main() {
    cout << "Hola mundo" << endl;
    int n=9;
    int m=9;
    vector<vector<int>> vec(n,vector <int> (m)) ;
            
  
    
}

bool FiltrarCelda(int vc[][9], int i, int s){//verificar
	
}

bool FiltrarSudoku(int Vc[][9] ){ //sudoku s
	bool cambio= false;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			bool a=FiltrarCelda(Vc, i ,j);
			cambio = a || cambio;
		}
	}
	return cambio;
}

bool Filtrar(int sudoku ){
	
	bool cambio=false;
	while (!cambio){
	//	FiltrarSudoku(sudoku);
	}
}
