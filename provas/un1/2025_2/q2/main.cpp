#define __CHECK_INTEGRIDADE__ 1
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../doctest.h"
#include "DadosEntrada.h"

using namespace std;

int mediana(int* arr, int esquerda, int direita) {
    int a, b, c;
    int indMeio = esquerda + (direita - esquerda) / 2;

    a = arr[esquerda];
    b = arr[indMeio];
    c = arr[direita];

    if ((a < b && b < c) || (a > b && b > c))
        return indMeio;
    else if ((c < a && a < b) || (c > a && a > b))
        return esquerda;
    else
        return direita;
}

void swap(int* array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int particionar(int* arr, int esquerda, int direita) {
    swap(arr, mediana(arr, esquerda, direita), direita);

    int pivo = arr[direita];
    int i = esquerda - 1;

    for (int j = esquerda; j < direita; j++) {
        if (arr[j] >= pivo) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, direita);
    return i + 1;
}

void quickSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = particionar(arr, esquerda, direita);
        quickSort(arr, esquerda, pivo - 1);
        quickSort(arr, pivo + 1, direita);
    }
}

/**
 * Não altere o código abaixo.
 * Sua solução deve ser implementada na função mergeSort.
 */
// Função auxiliar para verificar ordem decrescente
bool estaDecrescente(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (array[i] < array[i + 1]) {
            return false;
        }
    }

    return true;
}

// Função auxiliar ao teste
void CHECK_EQUALS(const vector<int>& entrada, const vector<int>& esperado) {
    vector<int> copia = entrada;
    int* arr = copia.data();
    quickSort(arr, 0, copia.size() - 1);
    CHECK(copia == esperado);
}

//  Testes
TEST_CASE("Casos básicos") {
    CHECK_EQUALS({}, {});
    CHECK_EQUALS({1}, {1});
    CHECK_EQUALS({1, 2}, {2, 1});
}

TEST_CASE("Casos médios") {
    CHECK_EQUALS({3, 1, 4, 2}, {4, 3, 2, 1});
    CHECK_EQUALS({5, 3, 8, 4, 2}, {8, 5, 4, 3, 2});
    CHECK_EQUALS({10, 9, 8, 7, 6, 5}, {10, 9, 8, 7, 6, 5});
}

TEST_CASE("Casos com repetidos e negativos") {
    CHECK_EQUALS({1, 3, 3, 2, 2, 1}, {3, 3, 2, 2, 1, 1});
    CHECK_EQUALS({-3, -1, -2, 0}, {0, -1, -2, -3});
    CHECK_EQUALS({1000, -100, 500, 0, -1, 999}, {1000, 999, 500, 0, -1, -100});
}

TEST_CASE("Caso array pequeno e aleatório") {
    int t1 = sizeof(arrayPequeno) / sizeof(int);
    quickSort(arrayPequeno, 0, t1 - 1);

    CHECK(estaDecrescente(arrayPequeno, t1));
}

TEST_CASE("Caso array grande e aleatório") {
    int t1 = sizeof(arrayGrande) / sizeof(int);
    quickSort(arrayGrande, 0, t1 - 1);

    CHECK(estaDecrescente(arrayGrande, t1));
}
