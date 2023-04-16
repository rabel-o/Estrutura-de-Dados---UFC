#include <iostream>
#include <string>
using namespace std;

int a{0};

int contaCaracteres(string str, int n, char c){
    if(n == 0){ // caso for o ultimo caractere da frase
        if(str[0] == c) // se ele for igual, eu incremento o contador
            a++;
        return a; // retorno a resposta
    }else{ // caso nõa for o ultimo caractere da frase
        if(str[n] == c){ // se ele for igual, eu incremento o contador
            a++;
        }
        return contaCaracteres(str, n-1, c);
    }
}

int main(){
    string str;
    getline(cin, str); // lendo a frase
    
    char c;
    cin >> c; // lendo caractere

    cout << contaCaracteres(str, str.length(), c); // printando a qantidade de caractere n estão presentes na frase
}
