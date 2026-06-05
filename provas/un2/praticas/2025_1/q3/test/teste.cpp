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
#include <string>

#include "../../lib/doctest.h"
#include "Fila.h"

TEST_CASE("Fila - Tamanho inicial deve ser zero") {
  Fila<int> fila(5);
  CHECK(fila.tamanho() == 0);
  CHECK(fila.vazia());
  CHECK_FALSE(fila.cheia());
}

TEST_CASE("Fila - Enfileirar elementos até a capacidade máxima") {
  Fila<int> fila(3);
  fila.enfileirar(10);
  fila.enfileirar(20);
  fila.enfileirar(30);
  CHECK(fila.tamanho() == 3);
  CHECK(fila.cheia());
  CHECK(fila.frente() == 10);
}

TEST_CASE("Fila - Enfileirar além da capacidade deve lançar exceção") {
  Fila<int> fila(2);
  fila.enfileirar(1);
  fila.enfileirar(2);
  CHECK_THROWS_AS(fila.enfileirar(3), std::overflow_error);
}

TEST_CASE("Fila - Desenfileirar elementos na ordem correta (FIFO)") {
  Fila<int> fila(3);
  fila.enfileirar(5);
  fila.enfileirar(10);
  fila.enfileirar(15);

  CHECK(fila.desenfileirar() == 5);
  CHECK(fila.desenfileirar() == 10);
  CHECK(fila.desenfileirar() == 15);
  CHECK(fila.vazia());
  CHECK(fila.tamanho() == 0);
}

TEST_CASE("Fila - Desenfileirar de fila vazia deve lançar exceção") {
  Fila<int> fila(2);
  CHECK_THROWS_AS(fila.desenfileirar(), std::underflow_error);
}

TEST_CASE("Fila - Acessar frente de fila vazia deve lançar exceção") {
  Fila<std::string> fila(2);
  CHECK_THROWS_AS(fila.frente(), std::underflow_error);
}

TEST_CASE("Fila - Comportamento circular (volta ao início do array)") {
  Fila<int> fila(3);
  fila.enfileirar(1);
  fila.enfileirar(2);
  fila.enfileirar(3);
  CHECK(fila.cheia());

  CHECK(fila.desenfileirar() == 1);
  fila.enfileirar(4);

  CHECK(fila.frente() == 2);
  CHECK(fila.desenfileirar() == 2);
  CHECK(fila.desenfileirar() == 3);
  CHECK(fila.desenfileirar() == 4);
  CHECK(fila.vazia());
}

TEST_CASE("Fila - Impressão da fila deve refletir os elementos na ordem") {
  Fila<int> fila(4);
  fila.enfileirar(100);
  fila.enfileirar(200);
  fila.enfileirar(300);
  CHECK(fila.imprimir() == "{ 100 200 300 }");

  fila.desenfileirar();
  fila.enfileirar(400);
  CHECK(fila.imprimir() == "{ 200 300 400 }");
}

TEST_CASE("Fila - Teste com diferentes tipos (int, double, string)") {
  Fila<double> filaD(2);
  filaD.enfileirar(3.14);
  filaD.enfileirar(2.71);
  CHECK(filaD.frente() == doctest::Approx(3.14));

  Fila<std::string> filaS(2);
  filaS.enfileirar("abc");
  filaS.enfileirar("xyz");
  CHECK(filaS.frente() == "abc");
}