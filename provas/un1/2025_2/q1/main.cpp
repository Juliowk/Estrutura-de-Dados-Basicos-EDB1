#define __CHECK_INTEGRIDADE__ 1
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

using namespace std;

int sum(int v[], int i, int tamanho) {
    if (i == tamanho) return 0;
    return v[i] + sum(v, i + 1, tamanho);
}

int calcularMedia(int v[], int tamanho) { return sum(v, 0, tamanho) / tamanho; }

TEST_CASE("Questão 1 - Testes da função calcularMedia") {
    int v1[] = {1, 2, 3, 4, 5};
    int t1 = sizeof(v1) / sizeof(int);
    CHECK(calcularMedia(v1, t1) == 3);

    int v2[] = {2, 4, 8, 16};
    int t2 = sizeof(v2) / sizeof(int);
    CHECK(calcularMedia(v2, t2) == 7);

    int v3[] = {-2, 4, 8};
    int t3 = sizeof(v3) / sizeof(int);
    CHECK(calcularMedia(v3, t3) == 3);

    int v4[] = {10, 20};
    int t4 = sizeof(v4) / sizeof(int);
    CHECK(calcularMedia(v4, t4) == 15);

    int v5[] = {100};
    int t5 = sizeof(v5) / sizeof(int);
    CHECK(calcularMedia(v5, t5) == 100);
}
