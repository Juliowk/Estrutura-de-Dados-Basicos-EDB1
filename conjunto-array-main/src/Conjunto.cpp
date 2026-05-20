#include "Conjunto.h"

#include <iostream>

Conjunto::Conjunto(const int capacidade) : capacidade(capacidade), quantidade(0) {
  elementos = new int[capacidade];
}

Conjunto::~Conjunto() { delete[] elementos; }

bool Conjunto::contem(int elemento) const {
  for (int i = 0; i < quantidade; i++)
    if (elementos[i] == elemento) return true;

  return false;
}

bool Conjunto::inserir(int elemento) {
  if (quantidade == capacidade) return false;
  if (contem(elemento)) return false;

  elementos[quantidade] = elemento;
  quantidade++;

  return true;
}

bool Conjunto::remover(int elemento) {
    if (!contem(elemento)) return false;

    for (int i = 0; i < quantidade; i++) {
        if (elementos[i] == elemento) {
            elementos[i] = elementos[quantidade - 1];
            quantidade--;
            return true;
        }
    }

    return false;
}

int Conjunto::tamanho() const { return this->quantidade; }

void Conjunto::imprimir() const {
  std::cout << "{ ";
  for (int i = 0; i < quantidade; ++i) {
    std::cout << this->elementos[i] << " ";
  }
  std::cout << "}" << std::endl;
}
