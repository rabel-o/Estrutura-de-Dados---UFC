#include <iostream>

using namespace std;

double fatorial(double n){
    double b{1};
    while(n > 1){
        b *= n--;
    }
    return b;
}

double euler(int N){
    int e = 1;
    for(int i = 0; i < 10; i++){
        int k = e + i / fatorial(N);
     }
    }


int main(){
      int N;
      cout << "Insira o numero a ser calculado: " << endl;
      cin >> N;
      
      cout << euler(N);

    return 0;
}