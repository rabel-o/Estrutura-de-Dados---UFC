// LUÍS GUSTAVO RABELO DE OLIVEIRA - 540974
// KAUAN OLIVEIRA PERDIGAO LOPES - 514867

#ifndef NODE
#define NODE_H
#include <iostream>

struct Node 
{
    int valor;
    Node *prev;
    Node *next;

    Node(const int& val, Node *pontPrev, Node *pontNext){ // Construtor
        valor = val;
        next = pontNext;
        prev = pontPrev;
    }
};

#endif 