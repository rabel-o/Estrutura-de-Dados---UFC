/********************************************
 * LUIS GUSTAVO RABELO DE OLIVEIRA - 540974 *
 * KAUAN OLIVEIRA PERDIGÃO LOPES - 514867   *
*********************************************/

#ifndef NODE
#define NODE

struct Node{

    //atributos do nó
    Node* direita;
    Node* abaixo;
    int linha;
    int coluna;
    double valor;

    //construtor do nó que recebe seus atributos e é inicializado
    Node(Node* direita, Node* abaixo, int linha, int coluna, double valor){
        this->valor = valor;
        this->direita = direita;
        this->abaixo = abaixo;
        this->linha = linha;
        this->coluna = coluna;
    }
};
#endif