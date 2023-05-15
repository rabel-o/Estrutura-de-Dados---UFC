#include <iostream>
#include <string>
#include <vector>

using namespace std;

int comparaString(vector<string> v, string s){
    int contador = 0;
    for(int j = 0; j < v.size(); j++){
        if(v[j] == s){
            contador++;
        }
    }
    return contador;
}

int *matchingStrings(vector<string> p, vector<string> c){
    int *temp = new int[c.size()];
    for(int i = 0; i < c.size(); i++){
        temp[i] = comparaString(p, c[i]);
    }
    return temp;
}

int main(){
    int cons, busc;
    cin >> cons;
    vector<string> consultas(cons);

    for(int i = 0; i < cons; i++){
        cin >> consultas[i];
    }

    cin >> busc;
    vector<string> buscas(busc);
    for(int i = 0; i < busc; i++){
        cin >> buscas[i];
    }

    int *v = matchingStrings(consultas, buscas);

    for(int i = 0; i < busc; i++){
        if(i == busc - 1){
            cout << v[i];
            break;
        }
        cout << v[i] << " ";
    }
    cout << endl;

    delete[] v;  
    
    return 0;
}

