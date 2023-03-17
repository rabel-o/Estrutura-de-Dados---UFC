#include <iostream>

using namespace std;

int main(){

   int valor, chute1, chute2;

   cin >> valor >> chute1 >> chute2;

   int dif = valor - chute1;
   int dif2 = valor - chute2;

   if(dif < 0){
        dif *= -1;
   }
   if(dif2 < 0){
        dif2 *= -1;
   }

   if(dif == dif2){
        cout << "empate";
   }
   else if(dif > dif2){
        cout << "segundo";
   }
   else{
        cout << "primeiro";
   }


}