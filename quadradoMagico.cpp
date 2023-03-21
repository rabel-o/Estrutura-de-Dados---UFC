#include <iostream>

using namespace std;

void LeMatriz(int m[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> m[i][j];
        }
    }
}

void VerificaMatriz(int m[3][3]){
   
    int k = m[0][0] + m[1][0] + m[2][0];
        
        if(k == m[0][1] + m[1][1] + m[2][1]){
            if(k == m[0][2] + m[1][2] + m[2][2]){
                if(k == m[0][0] + m[0][1] + m[0][2]){
                    if(k == m[1][0] + m[1][1] + m[1][2]){
                        if(k == m[2][0] + m[2][1] + m[2][2]){
                            if(k == m[0][0] + m[1][1] + m[2][2]){
                                if(k == m[0][2] + m[1][1] + m[2][0]){
                                    cout << "sim" << endl;
                                } else {
                                    cout << "nao" << endl;
                                }
                            } else {
                                cout << "nao" << endl;
                            }
                        } else {
                            cout << "nao" << endl;
                        }
                    } else {
                        cout << "nao" << endl;
                    }
                } else {
                    cout << "nao" << endl;
                }
            } else {
                cout << "nao" << endl;
            }
        } else {
            cout << "nao" << endl;
        }
}

int main(){
    
    int m[3][3];

    LeMatriz(m);
    VerificaMatriz(m);
    
    return 0;
}
