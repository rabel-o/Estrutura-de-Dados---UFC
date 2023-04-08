#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Aluno{
    int mat;
    string nome;
    double media;

    void ler(){
        cin >> mat;
        cin.ignore();
        getline(cin, nome);
        cin >> media;
    }
};

int main(){
    
    int qtdAlunos;
    int matricula;
    cin >> qtdAlunos;
    cin.ignore();

    Aluno *discente = new Aluno[qtdAlunos];

    for(int i = 0; i < qtdAlunos; i++){
        discente[i].ler();
    }

    cin >> matricula;

    for(int i = 0; i < qtdAlunos; i++){
        if(discente[i].mat == matricula){
            cout << discente[i].nome << endl;
            cout << fixed << setprecision(1) << discente[i].media << endl;
            return 0;
        }
    }

    cout << "NAO ENCONTRADA";
}
