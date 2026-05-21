#include <iostream>
#include <string>

#include "Lista.h"

using namespace std;

int main() {
  Lista lista = Lista();
  lista.inserirInicio("01");
  lista.inserirFim("02");
  lista.inserirFim("01");
  lista.inserirFim("03");
  lista.inserirFim("01");
  lista.inserirFim("01");
  lista.inserirFim("04");
  lista.inserirFim("05");

  cout << lista.imprimir() << endl;

  return 0;
}

/*
int main()
{
  std::string str;

  Lista l;
  while (true)
  {
    std::cout << "Digite uma palavra para adicionar ao início da Lista" <<
std::endl; std::cin >> str; const std::string s = str; l.inserirInicio(s);
    l.imprimir();
  }
  return 0;
}
*/