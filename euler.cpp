#include <iostream>
#include <iomanip>

using namespace std;

double fatorial(double n){
    double b{1};
    while(n > 1){
        b *= n--;
    }
    return b;
}

double euler(int N){
    double e = 1;
    int i = N;
        while(i > 0){
            e = e + 1 / fatorial(i); 
            i--;               
        }
        return e;
    }


int main(){

    cout << fixed << setprecision(6);

    int N;
    cin >> N;

    cout << euler(N);

    return 0;
}