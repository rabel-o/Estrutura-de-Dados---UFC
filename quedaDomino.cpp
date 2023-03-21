#include <iostream>

using namespace std;

int main(){
    int qtdDominos;
    cin >> qtdDominos;
    int dom[qtdDominos];
   
    int count{0};
    
   for(int i = 0; i < qtdDominos; i++){
       cin >> dom[i];
  }

   for(int i = 1; i < qtdDominos; i++){
        if(dom[i] >= dom[i - 1]){
            count++;
        }
  }

  int f = qtdDominos - 1;

   if(count == f){
     cout << "ok" << endl;
   }else{
     cout << "precisa de ajuste" << endl;
   }

   return 0;
}
