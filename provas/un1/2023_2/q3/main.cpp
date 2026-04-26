#include <iostream>
#include <vector>

using namespace std;

void merge(int array[], int inicio1, int inicio2, int fim2) {
    int elemEsquerda = inicio2 - inicio1 + 1;
    int elemDireita = fim2 - inicio2;

    vector<int> ladoEsquerdo(elemEsquerda);
    vector<int> ladoDireito(elemDireita);

    for (int i = 0; i < elemEsquerda; i++) ladoEsquerdo[i] = array[inicio1 + i];
    for (int j = 0; j < elemDireita; j++)
        ladoDireito[j] = array[inicio2 + 1 + j];

    int i = 0, j = 0, k = inicio1;

    while (i < elemEsquerda && j < elemDireita) {
        if (ladoEsquerdo[i] <= ladoDireito[j]) {
            array[k] = ladoEsquerdo[i];
            i++;
        } else {
            array[k] = ladoDireito[j];
            j++;
        }
        k++;
    }

    while (i < elemEsquerda) {
        array[k] = ladoEsquerdo[i];
        i++;
        k++;
    }

    while (j < elemDireita) {
        array[k] = ladoDireito[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = (esquerda + direita) / 2;
        mergeSort(array, esquerda, meio);
        mergeSort(array, meio + 1, direita);
        merge(array, esquerda, meio, direita);
    }
}

bool buscaBinaria(int array[], int esquerda, int direita, int alvo,
                  int i_ignore) {
    if (esquerda > direita) return false;

    int meio = (direita - esquerda) / 2 + esquerda;

    if (array[meio] == alvo && meio != i_ignore)
        return true;
    else if (array[meio] > alvo)
        return buscaBinaria(array, esquerda, meio - 1, alvo, i_ignore);
    else
        return buscaBinaria(array, meio + 1, direita, alvo, i_ignore);
}

bool soma2(int array[], int tamanho, int soma) {
    mergeSort(array, 0, tamanho - 1);  // Complexidade: (n log n)

    for (int i = 0; i < tamanho; i++) { // Complexidade: n
        int alvo = soma - array[i];

        // Complexidade log n;
        if (buscaBinaria(array, 0, tamanho-1, alvo, i)) return true;
    }

    return false;
}

int main(int argc, char const* argv[]) {
    int array[] = {0, 1, 2, 3, 4, 5};
    int lenght = sizeof(array) / sizeof(int);

    cout << soma2(array, lenght, 10) << endl;

    return 0;
}
