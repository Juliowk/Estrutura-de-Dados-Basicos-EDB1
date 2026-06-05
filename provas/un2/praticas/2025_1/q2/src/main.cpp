#include <iostream>
#include <string>

#include "Lista.h"

int main() {
  std::string str;

  Lista l;
  l.inserirInicio("1");
  l.inserirInicio("2");
  l.inserirInicio("3");
  l.inserirInicio("4");
  l.inserirInicio("5");
  
  l.inserirInicio("1");
  l.inserirInicio("2");
  l.inserirInicio("3");
  l.inserirInicio("4");
  l.inserirInicio("5");
  
  l.inserirInicio("1");
  l.inserirInicio("2");
  l.inserirInicio("3");
  l.inserirInicio("4");
  l.inserirInicio("5");
  
  l.inserirInicio("1");
  l.inserirInicio("2");
  l.inserirInicio("3");
  l.inserirInicio("4");
  l.inserirInicio("5");

  std::cout << l.imprimir() << std::endl;
  std::cout << l.removerTodos("1") << std::endl;
  std::cout << l.imprimir() << std::endl;

  return 0;
}
