#include <iostream> 
#include <vector>
#include <iomanip> //libreria de setw
using namespace std;

int main() {
    //cout << "Hola mundo" << endl;
    int n=9;
    int m=9;
   
    vector<vector<int>> vec(n,vector <int> (m)) ;
            for(int i = 0; i < n; i++) // cuadro latino
    {
        for(int j = 0; j < m; j++)
        {
            vec[i][j] = j + i + 1;
        }
    }
    for(int i = 0; i < n; i++)//imprimir
    {
        for(int j = 0; j < m; j++)
        {
            cout <<setw(3)<< vec[i][j] << " ";//setw para organizar
        }
        cout << endl;
    }
    
}

