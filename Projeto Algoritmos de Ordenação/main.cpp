// LUÍS GUSTAVO RABELO DE OLIVEIRA - 540974
// KAUAN OLIVEIRA PERDIGAO LOPES - 514867

#include <iostream>
#include "Lista.h"
#include "temporiza.h"
#include <fstream>

// AS PASTAS "RESULTADOS" E "DADOS" ESTÃO DENTRO DA PASTA OUTPUT.

using namespace std;

/*************************************************\
 // CODIGO QUE LIDA COM SISTEMAS DE ARQUIVOS     *
 // DO WINDOWS E DE SISTEMAS BASEADOS EM UNIX    *
 // CASO SE FAÇA NECESSÁRIO, É SO DESCOMENTAR    *
                                                 *
#ifdef _WIN32                                    *
    #include <direct.h>                          *
    #define CREATE_DIR(path) _mkdir(path)        *
#else                                            *
    #include <sys/stat.h>                        *
    #define CREATE_DIR(path) mkdir(path, 0777)   *
#endif                                           *
                                                 *
// Função para criar uma pasta                   *
void criarPasta(const string& nomePasta) {       *
    CREATE_DIR(nomePasta.c_str());               *
}                                                *
/*************************************************/

int main(){

    //criarPasta("dados"); // Chamada da função "criarPasta"
    //criarPasta("resultados"); // Chamada da função "criarPasta"

    marcador("quickSort", quickSort);
    marcador("mergeSort", mergeSort);
    marcador("bubbleSort", bubbleSort);
    marcador("insertionSort", insertionSort);
    marcador("selectionSort", selectionSort);
    marcador("shellSort", shellSort);
}