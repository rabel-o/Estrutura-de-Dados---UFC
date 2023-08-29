/********************************************
 * LUIS GUSTAVO RABELO DE OLIVEIRA - 540974 *
 * KAUAN OLIVEIRA PERDIGÃO LOPES - 514867   *
*********************************************/

#include <iostream>
#include <stdexcept>
#include "SparseMatrix.h"

//construtor
 SparseMatrix::SparseMatrix(int linhas, int colunas){
    //inicialização dos atributos
    this->linhas = linhas;
    this->colunas = colunas;
    m_head = new Node(nullptr, nullptr, 0, 0, 0);

    if(linhas > 0 && colunas > 0){
    
    Node* aux = m_head;

    //criação das linhas
    for(int i = 0; i < linhas; i++){ //complexidade O(n)
        Node* criadorLinhas = new Node(nullptr, nullptr, i++, 0, 0);
        criadorLinhas->direita = criadorLinhas;
        aux->abaixo = criadorLinhas;
        aux = aux->abaixo;
    }
    aux->abaixo = m_head; //Encadeando circularmente os nós sentinelas

    //criação das colunas
    aux = m_head;
    for(int i = 0; i < colunas; i++){ //complexidade O(n)
        Node* criadorColunas = new Node(nullptr, nullptr, 0, i++, 0);
        criadorColunas->abaixo = criadorColunas;
        aux->direita = criadorColunas;
        aux = aux->direita;
        }  
        aux->direita = m_head; //Encadeando circularmente os nós sentinelas
    } else {
        try
        {
            throw "Erro!!! Parametros incorretos";
        } catch(const char * mensagem) {
            std::cerr << mensagem << std::endl;
        }
    }
 }

 //Destrutor
 SparseMatrix::~SparseMatrix(){
    for(int i = 0; i < linhas; i++){ //percorrendo as linhas
        Node* aux = m_head;

        for(int j = 0; j <  colunas; j++){ //percorrendo as colunas
            if(aux->direita == aux){ //se aux apontar para ele mesmo, significa que chegou ao fim
                break;
            }
            Node *before = aux->direita;
            aux->direita = before->direita;
            delete before; //deletando before e liberando memoria, ajustando os ponteiros
        }

        m_head = m_head->abaixo;
        delete aux; //liberando memoria e seguindo para a proxima linha
    }

    std::cout << "Destruicao de Matriz realizada." << std::endl;

 }


//imprime a matriz
 void SparseMatrix::print(){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            std::cout << get(i+1, j+1) << " ";
        }

        std::cout << std::endl;

    }
 }

 double SparseMatrix::get(int i, int j){
    // Faz a verificaçao dos valores
    if((i < 0) || (j < 0) || (i > linhas) || (j > colunas)){
        throw std::out_of_range("A posicao eh invalida!");
    } else {
        Node *noLinhas = m_head->abaixo;
        //Viajará até a linha que foi especificada
        for(int contador = 1; contador < i; contador++){ 
            noLinhas = noLinhas->abaixo;
        }

        Node *aux = noLinhas->direita;
        //Viajará até a coluna que foi especificada e achará o valor
        while(aux != noLinhas){ //O(n)
            if((aux->linha == i) && (aux->coluna == j)){
                return aux->valor;
            }
            aux = aux->direita;
        }
    }
    return 0;
}


 int SparseMatrix::getLinhas(){ //complexidade O(1)
    return this->linhas;
 }

 int SparseMatrix::getColunas(){ //complexidade O(1)
    return this->colunas;
 }


 void SparseMatrix::insert(int i, int j, double valor){
    //verifica se os parametros passados para a matriz são válidos
    if((i < 0) || (i > linhas) || (j < 0) || (j > colunas)){
        throw std::out_of_range("A posicao eh invalida!");
    }

    int contador = 0;
    Node* noLinhas = m_head;
    while(contador < i){
        noLinhas = noLinhas->abaixo;
        contador++;
    }

    contador = 0;
    Node* noCol = m_head;
    while(contador < j){
        noCol = noCol->direita;
        contador++;
    }

    // verificando se há algum nó na posição. caso haja, apenas o valor é modificado 
    if(valor != 0){
        if(get(i, j) != 0){
            Node *viajaLinha = noLinhas; // este no percorrerá as linhas

            while(viajaLinha->direita != noLinhas && viajaLinha->direita->coluna < j){ // viajando para a direita
                viajaLinha = viajaLinha->direita;
            }

            viajaLinha->direita->valor = valor;

        } else {

            Node* newNode = new Node(nullptr, nullptr, i, j, valor);

            Node *viajaLinha = noLinhas; // este no percorrerá as linhas

            while(viajaLinha->direita != noLinhas && viajaLinha->direita->coluna < j){ // viajando para a direita
                viajaLinha = viajaLinha->direita;
            }
        

            Node* aux = viajaLinha->direita;
            viajaLinha->direita = newNode;
            newNode->direita = aux;

            Node* viajaColuna = noCol; // este no percorrerá as colunas

            while(viajaColuna->abaixo != noCol && viajaColuna->abaixo->linha < i){ // viajando para baixo
                viajaColuna = viajaColuna->abaixo;
            }

            aux = viajaColuna->abaixo;
            viajaColuna->abaixo = newNode;
            newNode->abaixo = aux;
        }

    //agora, precisamos deletar o no
    } else {
        if(get(i, j) != 0){
        // vamos percorrer toda a lista e remover o elemento da linha
        Node* viajaLinha = noLinhas;
        while(viajaLinha->direita != noLinhas && viajaLinha->direita->coluna < j){
            viajaLinha = viajaLinha->direita;
        }

        // agora, vamos liberar a memoria
        Node* aux = viajaLinha->direita->direita;
        Node* aux2 = viajaLinha->direita;
        delete aux2;
        viajaLinha->direita = aux;


        // vamos percorrer toda a lista e remover o elemento da linha
        Node* viajaColuna = noCol;
        while(viajaColuna->abaixo != noCol && viajaColuna->abaixo->linha < i){
            viajaColuna = viajaColuna->abaixo;
        }

        // agora, vamos liberar a memoria
        Node* aux3 = viajaColuna->abaixo->abaixo;
        Node* aux4 = viajaColuna->abaixo;
        delete aux4;
        viajaColuna->abaixo = aux3;

        }
    }
 }