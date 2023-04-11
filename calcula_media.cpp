#include <iostream> // std::cout, std::fixed
#include <iomanip> // std::setprecision

using namespace std;

struct aluno {
   float nota[3];
   float media;
};

// Recebe um aluno passado por referência, e preenche o campo 'media' com a
// média das 3 notas do aluno.
void calcula_media(aluno *a)
{
    float soma = 0;
   for(int i = 0; i < 3; i++){
      soma += a -> nota[i];

   }
   a -> media = soma / 3;
}

int main()
{
   aluno a;
   int i;
   for (i = 0; i < 3; i++)
      cin >> a.nota[i];
   
   // Chame a função 'calcula_media' passando o aluno 'a' por referência.

   calcula_media(&a);
   
   cout << fixed;
   cout << setprecision(1) << a.media;
   
   return 0;
}
