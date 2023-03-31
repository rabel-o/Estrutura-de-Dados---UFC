#include <iostream>
#include <string>

using namespace std;

int main(){
    string txt;
    getline(cin, txt);

    for(int i = 0; i < txt.size(); i++){
        if(txt[i+1] == ' '){
            if(txt[i] != txt[i+2]){
                cout << txt[i];
            } else {
                cout << txt[i];
                i++;
                i++;
            }
        } else if(txt[i] == ' '){
            if(txt[i-1] != txt[i+1]){
                cout << txt[i];
            }
        } else if(txt[i-1] == ' '){
            if(txt[i] != txt[i-2]){
                cout << txt[i];
            }
        } else cout << txt[i];
    }
}
