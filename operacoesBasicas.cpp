#include <sstream> //cabeçalho que contém o tipo de dado stringstream
#include <vector>  //cabeçalho que contém a estrutura de dados vector
#include <iostream>
#include <climits>
#include <string>

using namespace std;

vector<int> global;

void vet(vector<int> vetor, int tamanho, int inicio){
    if(inicio == tamanho){
        cout << vetor[inicio] << " ";
        return;
    } else {
        cout << vetor[inicio] << " ";
        return vet(vetor, tamanho, inicio + 1);
    }
}

void retorna_vet(vector<int> vetor, int tamanho, int inicio){
    cout << "vet : [ ";
    vet(vetor, tamanho - 1, inicio);
    cout << "]" << endl;
}

void rvet(vector<int> vetor, int tamanho){
    if(tamanho < 0){
        return;
    } else {
        cout << vetor[tamanho] << " ";
        return rvet(vetor, tamanho - 1);
    }
}

void retorna_rvet(vector<int> vetor, int tamanho){
    cout << "rvet: [ ";
    rvet(vetor, tamanho - 1);
    cout << "]" << endl;
}

int sum(vector<int> vetor, int tamanho, int inicio){
    if(tamanho < 0){
        return inicio;
    } else {
        inicio += vetor[tamanho];
        return sum(vetor, tamanho - 1, inicio);
    }
}

void retorna_soma(vector<int> vetor, int tamanho, int inicio){
    cout << "sum : ";
    cout << sum(vetor, tamanho - 1, inicio);
    cout << endl;
}

int mult(vector<int> vetor, int tamanho, int inicio){
    if(tamanho < 0){
        return inicio;
    } else {
        inicio *= vetor[tamanho];
        return mult(vetor, tamanho - 1, inicio);
    }
}

void retorna_mult(vector<int> vetor, int tamanho, int inicio){
    cout << "mult: " << mult(vetor, tamanho - 1, inicio) << endl;
}

int min(vector<int> vetor, int tamanho, int inicio){ 
    if (tamanho < 0){
        return inicio;
    } else {
        if (inicio > vetor[tamanho]){
            inicio = vetor[tamanho];
        }
        return min(vetor, tamanho - 1, inicio);
    }
}

void retorna_min(vector<int> vetor, int tamanho, int inicio){
    cout << "min : " << min(vetor, tamanho - 1, inicio) << endl;
}

void inverte(vector<int> vetor, int tamanho, int inicio){
    if(inicio == tamanho){
        global.push_back(vetor[inicio]);
        return;
    } else {
        global.push_back(vetor[inicio]);
        return inverte(vetor, tamanho, inicio + 1);
    }
}

void recebe_inverte(vector<int> vetor, int tamanho){
    if(tamanho < 0){
        return;
    } else {
        cout << vetor[tamanho] << " ";
        return recebe_inverte(vetor, tamanho - 1);
    }
}

void imprime_inverte(vector<int> vetor, int tamanho){
    cout << "inv : [ ";
    recebe_inverte(vetor, tamanho - 1);
    cout << "]" << endl;
}

int main(){
    string str;
    getline(cin, str);
    stringstream ss;
    ss << str;

    vector<int> vetor;
    int i = 0, num = 0;

    while(ss >> num){
        vetor.push_back(num);
        i++;
    }
    retorna_vet(vetor, vetor.size(), 0);
    retorna_rvet(vetor, vetor.size());
    retorna_soma(vetor, vetor.size(), 0);
    retorna_mult(vetor, vetor.size(), 1);
    retorna_min(vetor, vetor.size(), INT_MAX);
    inverte(vetor, vetor.size() - 1, 0);
    imprime_inverte(global, vetor.size());
}
