#include <iostream>

#include "ListaDuplamenteEncadeada.h"

int main() {
  ListaDuplamenteEncadeada l;

  l.inserirFim("0");
  l.inserirFim("1");
  l.inserirFim("2");
  l.inserirFim("3");
  l.inserirFim("4");

  std::cout << l.checarConsistencia() << std::endl;

  return 0;
}