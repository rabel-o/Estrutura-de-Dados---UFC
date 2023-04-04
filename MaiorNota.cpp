#include <string>
#include <iomanip>

using namespace std;

struct Aluno{
    string nome;
    string disciplina;
    int mat;
    double nota;

    void LerAluno(){
        getline(cin, nome);
        cin >> mat;
        cin.ignore();
        getline(cin, disciplina);
        cin >> nota;
        cin.ignore();
    }
};

int main(){
    Aluno aluno1;
    Aluno aluno2;
    aluno1.LerAluno();
    aluno2.LerAluno();

    if(aluno1.nota > aluno2.nota){
        cout << aluno1.nome << " , " << fixed << setprecision(1) << aluno1.nota;
    } else if(aluno2.nota > aluno1.nota){
        cout << aluno2.nome << " , " << fixed << setprecision(1) << aluno2.nota;
    } else if(aluno1.nota == aluno2.nota){
        cout << aluno1.nome << " e " << aluno2.nome << " , " << fixed << setprecision(1) << aluno1.nota;
    }
    
}
