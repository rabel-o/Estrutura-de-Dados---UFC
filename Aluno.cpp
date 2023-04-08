#include <iostream>
#include <string>

using namespace std;

struct Aluno{
    string nome;
    int mat;
    string disciplina;
    double nota;

    void lerAluno(){
        getline(cin, nome);
        cin >> mat;
        cin.ignore();
        getline(cin, disciplina);
        cin >> nota;
        cin.ignore();
    }

    void VerificaAprovacao(){
        if(nota >= 7){
            cout << nome << " aprovado(a) em " << disciplina;
        } else {
            cout << nome << " reprovado(a) em " << disciplina;
        }
    }
};

int main(){
    Aluno aluno1;
    aluno1.lerAluno();

    aluno1.VerificaAprovacao();

}
