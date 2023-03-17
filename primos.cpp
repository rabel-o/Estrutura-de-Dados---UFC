#include <iostream>

using namespace std;

bool primo(int n){
        int p {0};
        for(int aux = 2; aux <= n; aux++){
            if(n % aux  == 0){
                p++;
            }
         }

         if(p == 1){
            return true;
         } else {
            return false;
         }

}

int main(){

    int a, b;
    cin >> a >> b;

    for(int i = a; i <= b; i++){
        if(primo(i)){
            cout << i << endl;
        }
    }

    return 0;
}