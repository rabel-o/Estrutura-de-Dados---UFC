#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string confere(string frasePassada){
    bool temString = false, temPonto = false;
    
    for(int i = 0; i < frasePassada.length(); i++)
    {
        if(frasePassada[i] >= 97 && frasePassada[i] <= 122){
            temString = true;
        }
        if(frasePassada[i] == '.'){
            temPonto = true;
        }
    }
    if(temString)return "str";
    else if(temPonto)return "float";
    else return "int";
}


int main(){
    string txt, ver;
    getline(cin, txt);
    
    stringstream ss;
    ss << txt;
    
     int letra{0}, ponto{0};
    
    for(int i = 0; i < txt.length(); i++){
        string aux;
        if(i == 0){
            ss >> aux;
            cout << confere(aux);
        }
        else if(txt[i] == ' '){
            ss >> aux;
            cout << " " << confere(aux);
        }
    }
}
