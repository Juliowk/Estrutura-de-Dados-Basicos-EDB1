#include "Conjunto.h"

#include <iostream>

Conjunto::Conjunto(const int capacidade)
    : capacidade(capacidade), quantidade(0) {
  this->elementos = new int[capacidade];
}

Conjunto::~Conjunto() { delete[] this->elementos; }

bool Conjunto::contem(int elemento) const {
  for (int i = 0; i < tamanho(); i++)
    if (this->elementos[i] == elemento) return true;

  return false;
}

bool Conjunto::inserir(int elemento) {
  int quantidade = tamanho();

  if (this->capacidade == quantidade) return false;
  if (contem(elemento)) return false;

  this->elementos[quantidade] = elemento;
  this->quantidade++;
  return true;
}

bool Conjunto::remover(int elemento) {
  int quantidade = tamanho();

  for (int i = 0; i < quantidade; i++) {
    if (this->elementos[i] == elemento) {
      for (int j = i; i < quantidade; j++) {
        this->elementos[j] = this->elementos[j + 1];
      }
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
