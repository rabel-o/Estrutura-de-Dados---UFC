#include <iostream>
#include <string>
#include <stdexcept>
#include "SparseMatrix.h"
#include <fstream>

using namespace std;

SparseMatrix* readSparseMatrix(const std::string& nomeArquivo) {
    std::ifstream file(nomeArquivo);
    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo.");
    }

    int linhas, colunas;
    file >> linhas >> colunas;

    SparseMatrix* matrix = new SparseMatrix(linhas, colunas);

    int l, c;
    double value;
    while (file >> l >> c >> value) {
        matrix->insert(l, c, value);
    }

    file.close();
    return matrix;
}

SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B) {
    // Verifica se as matrizes podem ser multiplicadas
    if (A->getColunas() != B->getLinhas()) {
        throw std::invalid_argument("Nao é possível multiplicar matrizes. Dimensões invalidas.");
    }

    int linhasA = A->getLinhas();
    int colsA = A->getColunas();
    int colsB = B->getColunas();

    // Cria uma nova matriz esparsa C com dimensões linhasA x colsB
    SparseMatrix* C = new SparseMatrix(linhasA, colsB);

    // Realiza a multiplicação de matrizes
    for (int i = 1; i <= linhasA; i++) {
        for (int j = 1; j <= colsB; j++) {
            double valor = 0;

            for (int k = 1; k <= colsA; k++) {
                valor += A->get(i, k) * B->get(k, j);
            }

            // Insere o valor calculado na matriz C
            C->insert(i, j, valor);
        }
    }

    return C;
}

SparseMatrix *sum(SparseMatrix *A, SparseMatrix *B){ //O(n²), isso ocorre porque o código possui dois loops aninhados que percorrem as linhas e colunas das matrizes A e B. No pior caso, todas as posições das matrizes são percorridas e a soma é realizada para cada elemento das matrizes.
    // Verifica se o número de linhas e colunas das matrizes A e B são iguais
    if (A->getLinhas() != B->getLinhas() || A->getColunas() != B->getColunas()) {
        // Lança uma exceção se as matrizes não puderem ser somadas
        throw std::runtime_error("Nao é possível somar as matrizes");
    }
    // Cria uma nova matriz para armazenar o resultado da soma
    SparseMatrix *C = new SparseMatrix(A->getLinhas(), A->getColunas());

    for (int i = 1; i <= A->getLinhas(); i++) {
        for (int j = 1; j <= A->getColunas(); j++) {
            // Calcula a soma dos elementos das matrizes A e B na posição (i, j)
            double aux = A->get(i, j) + B->get(i, j);
            // Insere o valor na posição (i, j) da matriz resultante
            C->insert(i, j, aux);
        }
    }
    return C;
}

int main() {
    SparseMatrix* matrix1 = nullptr;
    SparseMatrix* matrix2 = nullptr;

    while(true){

    string command;
    cout << "Digite o comando ('adicao','multiplicacao' ou 'sair'): ";
    cin >> command;

    if (command == "adicao") {
        try {
            string filename;
            cout << "Digite o nome do arquivo da primeira matriz: ";
            cin >> filename;
            matrix1 = readSparseMatrix(filename);
            cout << endl;
            matrix1->print();
            cout << endl;

            cout << "Digite o nome do arquivo da segunda matriz: ";
            cin >> filename;
            matrix2 = readSparseMatrix(filename);
            cout << endl;
            matrix2->print();
            cout << endl;

            SparseMatrix* sumResult = sum(matrix1, matrix2);
            cout << "Resultado da adicao:" << endl;
            sumResult->print();
            cout << endl;

            delete sumResult;
        } catch (const runtime_error& ex) {
            cout << "Erro ao executar a adicao: " << ex.what() << endl;
        }
    } else if (command == "multiplicacao") {
        try {
            string filename;
            cout << "Digite o nome do arquivo da primeira matriz: ";
            cin >> filename;
            matrix1 = readSparseMatrix(filename);
            cout << endl;
            matrix1->print();
            cout << endl;

            cout << "Digite o nome do arquivo da segunda matriz: ";
            cin >> filename;
            matrix2 = readSparseMatrix(filename);
            cout << endl;
            matrix2->print();
            cout << endl;

            SparseMatrix* multResult = multiply(matrix1, matrix2);
            cout << "Resultado da multiplicacao:" << endl;
            multResult->print();
            cout << endl;

            delete multResult;
        } catch (const runtime_error& ex) {
            cout << "Erro ao executar a multiplicacao: " << ex.what() << endl;
        }
    } else if(command == "sair"){
        break;
   
    } else {
        cout << "Comando invalido." << endl;
    }
    }
    

    delete matrix1;
    delete matrix2;

    return 0;
}