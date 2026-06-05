// Compatibilidade do doctest no Windows/MinGW:
// - <cstdio> e <io.h> fornecem _fileno para o doctest
// - DOCTEST_CONFIG_NO_MULTITHREADING desativa o uso de std::mutex
// - gmtime_s é definido via std::gmtime quando ausente
#include <io.h>

#ifndef fileno
#define fileno _fileno
#endif

#include <cstdio>
#include <ctime>

#ifndef _fileno
#define _fileno fileno
#endif

#if defined(__MINGW32__) && !defined(gmtime_s)
static inline int doctest_compat_gmtime_s(std::tm* dest,
                                          const std::time_t* src) {
  auto tmp = std::gmtime(src);
  if (!tmp) return 1;
  *dest = *tmp;
  return 0;
}
#define gmtime_s(dest, src) doctest_compat_gmtime_s(dest, src)
#endif

#define DOCTEST_CONFIG_NO_MULTITHREADING
#define DOCTEST_CONFIG_COLORS_NONE
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stdexcept>
#include <string>

#include "../../lib/doctest.h"
#include "Lista.h"

TEST_CASE("1. Lista vazia") {
  Lista lista;
  CHECK(lista.removerTodos("x") == 0);
  CHECK_THROWS_AS(lista.primeiroElemento(), std::out_of_range);
  CHECK_THROWS_AS(lista.ultimoElemento(), std::out_of_range);
}

TEST_CASE("2. Lista com um único nó igual ao valor") {
  Lista lista;
  lista.inserirInicio("a");
  CHECK(lista.removerTodos("a") == 1);
  CHECK(lista.tamanho() == 0);
  CHECK_THROWS_AS(lista.primeiroElemento(), std::out_of_range);
  CHECK_THROWS_AS(lista.ultimoElemento(), std::out_of_range);
}

TEST_CASE("3. Lista com um único nó diferente do valor") {
  Lista lista;
  lista.inserirInicio("a");
  CHECK(lista.removerTodos("b") == 0);
  CHECK(lista.tamanho() == 1);
  CHECK(lista.primeiroElemento() == "a");
  CHECK(lista.ultimoElemento() == "a");
}

TEST_CASE("4. Todos os elementos são iguais ao valor") {
  Lista lista;
  lista.inserirInicio("x");
  lista.inserirInicio("x");
  lista.inserirInicio("x");
  lista.inserirInicio("x");
  CHECK(lista.removerTodos("x") == 4);
  CHECK(lista.tamanho() == 0);
  CHECK_THROWS_AS(lista.primeiroElemento(), std::out_of_range);
  CHECK_THROWS_AS(lista.ultimoElemento(), std::out_of_range);
}

TEST_CASE("5. Nenhum elemento igual ao valor") {
  Lista lista;
  lista.inserirInicio("d");
  lista.inserirInicio("c");
  lista.inserirInicio("b");
  lista.inserirInicio("a");
  CHECK(lista.removerTodos("z") == 0);
  CHECK(lista.tamanho() == 4);
  CHECK(lista.primeiroElemento() == "a");
  CHECK(lista.ultimoElemento() == "d");
}

TEST_CASE("6. Vários nós com o valor alternados") {
  Lista lista;
  lista.inserirInicio("i");
  lista.inserirInicio("x");
  lista.inserirInicio("h");
  lista.inserirInicio("x");
  lista.inserirInicio("g");
  lista.inserirInicio("x");
  lista.inserirInicio("f");
  CHECK(lista.removerTodos("x") == 3);
  CHECK(lista.tamanho() == 4);
  CHECK(lista.primeiroElemento() == "f");
  CHECK(lista.ultimoElemento() == "i");
}

TEST_CASE("7. Valor no início da lista") {
  Lista lista;
  lista.inserirInicio("d");
  lista.inserirInicio("b");
  lista.inserirInicio("a");
  lista.inserirInicio("x");
  CHECK(lista.removerTodos("x") == 1);
  CHECK(lista.tamanho() == 3);
  CHECK(lista.primeiroElemento() == "a");
  CHECK(lista.ultimoElemento() == "d");
}

TEST_CASE("8. Valor no final da lista") {
  Lista lista;
  lista.inserirInicio("x");
  lista.inserirInicio("c");
  lista.inserirInicio("b");
  lista.inserirInicio("a");
  CHECK(lista.removerTodos("x") == 1);
  CHECK(lista.tamanho() == 3);
  CHECK(lista.primeiroElemento() == "a");
  CHECK(lista.ultimoElemento() == "c");
}

TEST_CASE("9. Valor aparece uma vez no meio") {
  Lista lista;
  lista.inserirInicio("d");
  lista.inserirInicio("x");
  lista.inserirInicio("b");
  lista.inserirInicio("a");
  CHECK(lista.removerTodos("x") == 1);
  CHECK(lista.tamanho() == 3);
  CHECK(lista.primeiroElemento() == "a");
  CHECK(lista.ultimoElemento() == "d");
}
