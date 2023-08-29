/********************************************
 * LUIS GUSTAVO RABELO DE OLIVEIRA - 540974 *
 * KAUAN OLIVEIRA PERDIGÃO LOPES - 514867   *
*********************************************/

#ifndef SPARSEMATRIX
#define SPARSEMATRIX
#include "Node.h"

class SparseMatrix{
private:
    //atributos da classe Sparse Matrix
    Node* m_head{nullptr};
    int linhas{0};
    int colunas{0};
public:
    //métodos da classe Sparse Matrix
    SparseMatrix(int linhas, int colunas); // Inicializa uma matriz esparsa vazia com capacidade para m linhas e n colunas e verifica se os valores sao validos.
    ~SparseMatrix(); // Libera toda a memoria que foi alocada dinamicamente para a matriz.
    void print(); // Esta funcao imprime a matriz no terminal, inclusive os elementos iguais a zero.
    double get(int i, int j); //Devolve o valor na celula (i, j) da matriz, onde i eh a linha e j eh a coluna.
    int getLinhas(); // Recupera o valor das linhas
    int getColunas(); // Recupera o valor das colunas
    void insert(int i, int j, double valor); //Esta funcao-membro faz o valor na celula (i, j) da matriz ser igual a value, onde i e a linha e j e a coluna. Se ja houver um valor nessa posicao, ele e atualizado para esse novo valor. Essa funcao deve checar se os indices i, j passados por parametro sao validos; se nao forem validos, uma excecao deve ser lancada. Garante que não perca um valor já existente na linha.*/
};

#endif