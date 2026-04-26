/*
#include <iostream>
#include <vector>

using namespace std;

void merge(int array[], int esquerda, int meio, int direita) {
    int elemEsquerda = meio - esquerda + 1;
    int elemDireita = direita - meio;

    vector<int> ladoEsquerdo(elemEsquerda);
    vector<int> ladoDireito(elemDireita);

    for (int i = 0; i < elemEsquerda; i++)
        ladoEsquerdo[i] = array[esquerda + i];
    for (int j = 0; j < elemDireita; j++) ladoDireito[j] = array[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;

    while (i < elemEsquerda && j < elemDireita) {
        if (ladoEsquerdo[i] >= ladoDireito[j]) {
            array[k] = ladoEsquerdo[i];
            i++;
        } else {
            array[k] = ladoDireito[j];
            j++;int elemEsquerda = meio - esquerda + 1;
    int elemDireita = direita - meio;

    vector<int> ladoEsquerdo(elemEsquerda);
    vector<int> ladoDireito(elemDireita);

    for (int i = 0; i < elemEsquerda; i++)
        ladoEsquerdo[i] = array[esquerda + i];
    for (int j = 0; j < elemDireita; j++) ladoDireito[j] = array[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;

    while (i < elemEsquerda && j < elemDireita) {
        if (ladoEsquerdo[i] >= ladoDireito[j]) {
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

int main(int argc, char const* argv[]) {
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    mergeSort(array, 0, 9);

    for (int i : array) cout<<i<<" ";
    cout<<endl;


    return 0;
}
*/

#include <cassert>
#include <iostream>
#include <vector>

#include "DadosEntrada.h"

using namespace std;

void mergeSort(int[], int, int);
bool estaDecrescente(int[], int);

int main(void) {
    cout << "\t---\tQuestão 02: Início\t---" << endl;

    int tamanho = 1000000;

    mergeSort(
        arrayAleatorio, 0,
        tamanho - 1);  // arrayAleatorio é definido    dentro de DadosEntrada.h

    assert(estaDecrescente(arrayAleatorio, tamanho));

    mergeSort(
        arrayCrescente, 0,
        tamanho - 1);  // arrayCrescente é definido    dentro de DadosEntrada.h

    assert(estaDecrescente(arrayCrescente, tamanho));

    cout << "\t---\tQuestão 02: Passou em todos os testes\t---" << endl;

    return 0;
}

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
        if (ladoEsquerdo[i] >= ladoDireito[j]) {
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

/**
 * Esta é uma função auxiliar que eu criei para poder testar se sua ordenação
 está correta. Não altere-a.
*/
bool estaDecrescente(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (array[i] < array[i + 1]) {
            return false;
        }
    }

    return true;
}