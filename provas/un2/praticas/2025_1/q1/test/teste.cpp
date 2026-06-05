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
#include "../../lib/doctest.h"
#include "../header/Lista.h"

Lista criarLista() {
  Lista lista;
  lista.inserirInicio("A");
  lista.inserirInicio("B");
  lista.inserirInicio("C");
  lista.inserirInicio("D");
  return lista;
}

TEST_CASE("Move o primeiro nó para o início") {
  Lista lista = criarLista();
  REQUIRE(lista.imprimir() == "D<->C<->B<->A");
  CHECK(lista.moverParaInicio("D") == true);
  CHECK(lista.imprimir() == "D<->C<->B<->A");
}

TEST_CASE("Move o último nó para o início") {
  Lista lista = criarLista();
  REQUIRE(lista.imprimir() == "D<->C<->B<->A");
  CHECK(lista.moverParaInicio("A") == true);
  CHECK(lista.imprimir() == "A<->D<->C<->B");
}

TEST_CASE("Move nó do meio para o início") {
  Lista lista = criarLista();
  REQUIRE(lista.imprimir() == "D<->C<->B<->A");
  CHECK(lista.moverParaInicio("C") == true);
  CHECK(lista.imprimir() == "C<->D<->B<->A");
}

TEST_CASE("Tenta mover nó inexistente para o início") {
  Lista lista = criarLista();
  REQUIRE(lista.imprimir() == "D<->C<->B<->A");
  CHECK(lista.moverParaInicio("X") == false);
  CHECK(lista.imprimir() == "D<->C<->B<->A");
}
