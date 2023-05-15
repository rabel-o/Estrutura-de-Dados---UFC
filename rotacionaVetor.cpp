#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot) {
    int size = vet.size();
    
    nrot %= size; // Ajusta o número de rotações caso seja maior que o tamanho do vetor
    
    if (nrot == 0) {
        return; // Não é necessário fazer nada se o número de rotações for 0
    }
    
    vector<int> temp(nrot);
    
    // Copia os últimos nrot elementos para um vetor temporário
    for (int i = size - nrot, j = 0; i < size; i++, j++) {
        temp[j] = vet[i];
    }
    
    // Move os elementos restantes para a direita
    for (int i = size - 1; i >= nrot; i--) {
        vet[i] = vet[i - nrot];
    }
    
    // Copia os elementos do vetor temporário para as primeiras posições
    for (int i = 0; i < nrot; i++) {
        vet[i] = temp[i];
    }
}

void show(vector<int>& vet) {
    cout << "[ ";
    for (int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main() {
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for (int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
    
    return 0;
}
