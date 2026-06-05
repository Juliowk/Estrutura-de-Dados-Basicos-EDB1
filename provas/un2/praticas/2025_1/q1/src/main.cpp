#include <iostream>

#include "Lista.h"

int main() {
  Lista l;

  l.inserirInicio("1");
  l.inserirInicio("2");
  l.inserirInicio("3");
  l.inserirInicio("4");
  l.inserirInicio("5");
  l.inserirInicio("6");

  std::cout << "Tamanho " << l.tamanho() << std::endl;
  std::cout << l.imprimir() << std::endl;
  std::cout << (l.moverParaInicio("1") ? "true" : "false") << std::endl;

  return 0;
}