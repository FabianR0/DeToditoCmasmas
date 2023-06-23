#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ValuesString {
    private:
        string msg;
        
    public:
        ValuesString(){
            msg = "";
        }
        
        string printMsg(int boolValue) {
            string msgBool;
            if (boolValue == 1) {
                msgBool = "true";
            } else {
                msgBool = "false";
            }
            msg = "¿El Soduko esta resuelto correctamente?: " + msgBool;
            return msg;
        }

};

class Soduko {
    
    private:
    
        ValuesString msg;
        vector<vector<int>> sSoduko;
        vector<int> numbersInSoduko;
        
        bool validSokudo;
        bool validQuadrant;
        
        int maxColumn = 0;
        int maxRow = 0;
        
    
        int currentQuadrant = 0;
        int currentRow = 0;
        int currentColumn = 0;
        int countSaveElement = 0;
        int minRow = 0;
        int minColumn = 0;
        
        void validateUniqueNumber(int value) {
            numbersInSoduko[value-1]++;
        }
        
        bool validateNumbers() {
            for (int i = 0; i < 9; i++) {
                if (numbersInSoduko[i] != 1) {
                    existProblem = true;
                } 
                //cout << "existProblem -> " << existProblem << endl;
            }
            numbersInSoduko = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            return existProblem;
        }
        
        void getSection(int currentSection) {
            if (currentSection == 0) {
                currentRow = 0;
                maxRow = 3;
                minRow = 0;
                currentQuadrant = 0;
            } 
            if(currentSection == 1) {
                currentRow = 3;
                maxRow = 6;
                minRow = 3;
                currentQuadrant = 0;
            }
            if (currentSection == 2){ 
                currentRow = 6;
                maxRow = 9;
                minRow = 6;
                currentQuadrant = 0;
            }
            validateQuadrant();
        }
        
        void validateQuadrant() {
            if (currentQuadrant == 0) {
                currentColumn = 0;
                maxColumn = 3;
                minColumn = 0;
            } 
            if (currentQuadrant == 1) {
                currentColumn = 3;
                maxColumn = 6;
                minColumn = 3;
            }
            if (currentQuadrant == 2) {
                currentColumn = 6;
                maxColumn = 9;
                minColumn = 6;
            }
            if (currentQuadrant < 3) {
                validateQuadrantRowsAndColumn();
            } 
        }
        
        void validateQuadrantRowsAndColumn () {
            // cout << "Here -> Quadrant = " << currentQuadrant << endl;
            for (currentRow; currentRow < maxRow; currentRow++) {
                // cout << "Here -> Row = " << currentRow<< endl;
                if (existProblem == false) {
                    for (currentColumn; currentColumn < maxColumn; currentColumn++) {
                        // cout << "Here -> Column = " << currentColumn << endl;
                        int posNumber = sSoduko[currentRow][currentColumn];
                        validateUniqueNumber(posNumber);
                    }
                    currentColumn = minColumn;
                }
            }
            if (validateNumbers() == false) {
                currentRow = minRow;
                numbersInSoduko = {0, 0, 0, 0, 0, 0, 0, 0, 0};
                currentQuadrant+=1;
                validateQuadrant();
                // cout << msg.printMsg(1) << endl;
            } 
        }
        
        	
    public:
    
        bool existProblem;
        
        Soduko(){
            validSokudo = true;
            existProblem = false;
            sSoduko = {
                {8, 4, 5, 6, 9, 1, 3, 2, 7},
                {7, 3, 1, 8, 4, 2, 9, 6, 5},
                {2, 9, 6, 7, 5, 3, 8, 4, 1},
                {1, 2, 3, 4, 6, 5, 7, 8, 9},
                {4, 5, 7, 1, 8, 9, 2, 3, 6},
                {6, 8, 9, 2, 3, 7, 1, 5, 4},
                {3, 1, 2, 5, 7, 4, 6, 9, 8},
                {5, 7, 8, 9, 2, 6, 4, 1, 3},
                {9, 6, 4, 3, 1, 8, 5, 7, 2},
            };
            numbersInSoduko = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        }
        
        void printSoduko() {
            for (int row = 0; row < 9; row++) {
        	   for (int column = 0; column < 9; column++) {
        	        cout << sSoduko[row][column] << " ";
        	   }
        	   cout << endl;
        	}
        }
        
        bool validRowAllSoduko() {
            // cout << "Here -> AllRows" << endl;
            for (int i = 0; i < 9; i++) {
                // cout << "Row -> " <<  i << endl;
                for (int c = 0; c < 9; c++) {
                    // cout << "column -> " <<  c << endl;
                    validateUniqueNumber(sSoduko[i][c]);
                }
                validateNumbers();
            }
            return existProblem;
        }
        
        void validColumnsAllSoduko() {
            for (int c = 0; c < 9; c++) {
                for (int i = 0; i < 9; i++) {
                    validateUniqueNumber(sSoduko[i][c]);
                }
                validateNumbers();
            }
        }
        
        void validateSoduko(int currentSection) {
            getSection(currentSection);
        }
    
};

int main() {
    
    Soduko s;
    ValuesString msg;
    
    s.printSoduko();
    cout << "--- // --- // --- " << endl << endl;
    
    s.validateSoduko(0);
    if (s.existProblem == false) {
        s.validateSoduko(1);
        if (s.existProblem == false) {
            s.validateSoduko(2);
            if (s.existProblem == false) {
                s.validRowAllSoduko();
                if (s.existProblem == false) {
                    s.validColumnsAllSoduko();
                    if(s.existProblem == false) {
                        cout << msg.printMsg(1) << endl;
                    } else {
                        cout << msg.printMsg(0) << endl;
                    }
                } else {
                    cout << msg.printMsg(0) << endl;
                }
            } else {
                cout << msg.printMsg(0) << endl;
            }
        } else {
            cout << msg.printMsg(0) << endl;
        }
    } else {
        cout << msg.printMsg(0) << endl;
    }
    
	return 0;
	
}
