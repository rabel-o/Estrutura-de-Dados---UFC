#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string txt;
    string ver;
    string guarda;
    getline(cin, txt);

    stringstream ss;
    ss << txt;
    ss >> guarda;

    while(ss >> ver){
        if(guarda < ver){
            guarda = ver;
        } else {
            cout << "nao";
            
            return 0;
        }
    }

    cout << "sim";
    
}
