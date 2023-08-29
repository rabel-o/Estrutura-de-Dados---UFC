// LUÍS GUSTAVO RABELO DE OLIVEIRA - 540974
// KAUAN OLIVEIRA PERDIGAO LOPES - 514867


#ifndef LISTA_H
#define LISTA_H
#include "Node.h"
#include <iostream>

class List{

public:
    Node *m_head; // ponteiro que aponta para o no sentinela
    unsigned m_size; // numero de elementos da lista
    
    List(){ // Construtor 
        m_head = new Node(0, nullptr, nullptr);
        m_head->prev = m_head;
        m_head->next = m_head;
        m_size = 0;
    } 
    
    ~List(){ // Destrutor
        clear(); 
        delete m_head;
    }

    void clear(){ // Esvazia a lista
        Node *atual = m_head->next;
        while(atual != m_head){
            Node *prox = atual->next;
            delete atual;
            atual = prox;
        }
        m_head->prev = m_head;
        m_head->next = m_head;
        m_size = 0;
    }

    void print(){ // Realiza a impressão dos elementos
        Node *atual = m_head->next;
        while(atual != m_head){
            std::cout << atual->valor << " ";
        }
        std::cout << std::endl;
    }

    void push_back(const int& valor){ // Insere um elemento no final da lista
        Node *aux = new Node(valor, m_head->prev, m_head);
        aux->prev->next = aux;
        m_head->prev = aux;
        m_size++;
    }

    bool empty(){ // Retorna caso a lista esteja vazia
        return m_size == 0;
    }


    void bubbleSort(){
        bool trocou;
        if(empty() || m_head->next->next == m_head){
            return;
        }
        do{
            trocou = false;
            Node *atual = m_head->next;
            Node *proxNo = atual->next;

            while(proxNo != m_head){
                if(atual->valor > proxNo->valor){
                    std::swap(atual->valor, proxNo->valor);
                    trocou = true;
                }
                atual = proxNo;
                proxNo = proxNo->next;
            }
        }
        while(trocou);
    }


    void selectionSort(){
        Node *atual = m_head->next;
        while(atual->next != m_head){
            Node *proxNo = atual->next;
            Node *min = atual;

            while(proxNo != m_head){
                if(min->valor > proxNo->valor){
                    min = proxNo; 
                }
                proxNo = proxNo->next;
            }

            int t = atual->valor;
            atual->valor = min->valor;
            min->valor = t;
           


            atual = atual->next;
        }
    }

    void insertionSort(){
        Node *atual = m_head;
        do{
            Node* ant = atual->prev;
            int val = atual->next->valor;
            while(ant != m_head->prev && ant->valor > val){
                ant->next->valor = ant->valor;
                ant = ant->prev;
            }
            ant->next->valor = val;
            atual = atual->next;
        }
        while(atual != m_head);
    }

    Node* particao(Node* baixo, Node* alto) {
        int pivo = baixo->valor;
        Node* i = alto->next;

        for (Node* j = alto; j != baixo; j = j->prev) {
            if (j->valor >= pivo) {
                i = (i == nullptr) ? alto : i->prev;

                std::swap(i->valor, j->valor);
            }
        }

        i = (i == nullptr) ? alto : i->prev;
        std::swap(i->valor, baixo->valor);

        return i;
    }

    void quickSort(Node* baixo, Node* alto){
        if (baixo != nullptr && alto != nullptr && baixo != alto && baixo != alto->next) {
            Node* pivo = particao(baixo, alto);
            quickSort(baixo, pivo->prev);
            quickSort(pivo->next, alto);
        }
    }


    Node* merge(Node* left, Node* right) {
        // Caso base: se uma das listas está vazia, retorna a outra lista
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        Node* result = nullptr;

    if (left->valor <= right->valor) {
        result = left;
        result->next = merge(left->next, right);
        result->next->prev = result;
    } else {
        result = right;
        result->next = merge(left, right->next);
        result->next->prev = result;
    }

    return result;
}

void splitList(Node* source, Node** left, Node** right) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = source;
    *right = slow->next;
    slow->next = nullptr;
    (*right)->prev = nullptr;
}

void mergeSort(Node* baixo, Node* alto) {
    if (baixo != nullptr && alto != nullptr && baixo != alto && baixo != alto->next) {
        Node* pivo = particao(baixo, alto);
        mergeSort(baixo, pivo->prev);
        mergeSort(pivo->next, alto);
    }
}



void shellSort(List* list) {
    int size = list->m_size;
    int gap = 1;
    while (gap < size) {
        gap = 3 * gap + 1;
    }
    while (gap > 1) {
        gap /= 3;
        for (int i = gap; i < size; i++) {
            Node* valueNode = list->m_head->next;
            for (int k = 0; k < i; k++) {
                valueNode = valueNode->next;
            }
            int value = valueNode->valor;
            Node* jNode = valueNode->prev;
            while (jNode != list->m_head && value < jNode->valor) {
                jNode->next->valor = jNode->valor;
                jNode = jNode->prev;
            }
            jNode->next->valor = value;
        }
    }
}



};

void bubbleSort(List* list){
    list->bubbleSort();
}

void insertionSort(List* list){
    list->insertionSort();
}

void selectionSort(List* list){
    list->selectionSort();
}

void mergeSort(List* list) {
    list->mergeSort(list->m_head->next, list->m_head->prev);
}

void quickSort(List* list){
    list->quickSort(list->m_head->next, list->m_head->prev);
}

void shellSort(List* list){
    list->shellSort(list);
}

#endif

