#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string txt;

    getline(cin, txt);

    char mod;

    cin >> mod;
    
    if(mod == 'M'){
        for(int i = 0; i < txt.size(); i++){
            if(txt[i] >= 97 && txt[i] <= 122){
                txt[i] -= 32;
            }
        }
    } else if(mod == 'm'){
        for(int i = 0; i < txt.size(); i++){
            if(txt[i] >= 65 && txt[i] <= 90){
                txt[i] += 32;
            }
        }
    }else if(mod == 'i'){
        for(int i = 0; i < txt.size(); i++){
            if(txt[i] >= 97 && txt[i] <= 122){
                txt[i] -= 32;
            }
            else if(txt[i] >= 65 && txt[i] <= 90){
                txt[i] += 32;
            }
        }

    } else if(mod == 'p'){
        txt[0] += 32;
            for(int i = 1; txt[i]; i++){
                if(isblank(txt[i]) != 0 && isalpha(txt[i+1]) != 0 && isblank(txt[i+2]) == 0){
                    if(isupper(txt[i+1]) != 0){
                        i++;
                } else {
                    txt[i+1] -= 32;
                }
            }
        }
    }

    cout << txt;
}
