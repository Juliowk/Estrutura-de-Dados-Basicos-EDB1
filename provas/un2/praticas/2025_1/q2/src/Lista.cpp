#define __CHECK_INTEGRIDADE__ 1
#include "../header/Lista.h"

#include <iostream>
#include <sstream>  // pra implementar o método imprimir ​
#include <stdexcept>
#include <vector>

// Implemente aqui sua solução ​
int Lista::removerTodos(const std::string& valor)  // versão: EAMB-1.0
{                                                  // Begin​​⁣
  auto atual = this->primeiro;
  No* anterior = nullptr;

  int count = 0;

  while (atual != nullptr) {
    if (atual->valor == valor) {
      if (atual == this->primeiro && this->tamanho() == 1)
        this->primeiro = nullptr;
      else if (atual == this->primeiro)
        this->primeiro = atual->proximo;
      else if (atual == this->ultimo) {
        this->ultimo = anterior;
        anterior->proximo = nullptr;
      } else
        anterior->proximo = atual->proximo;

      delete atual;
      count++;
      this->quantidade--;
    }

    anterior = atual;
    atual = atual->proximo;
  }

  return count;

}  // End​

// Não alterar código daqui pra baixo ​
Lista::Lista() {
  this->quantidade = 0;
  this->primeiro = nullptr;
  this->ultimo = nullptr;
}
Lista::~Lista() {
  auto a = this->primeiro;
  while (a != nullptr) {
    auto b = a;
    a = a->proximo;
    delete b;
  }
  this->primeiro = nullptr;
  this->ultimo = nullptr;
  this->quantidade = 0;
}
bool Lista::inserirInicio(const std::string& x) {
  No* n = new No(x);
  n->proximo = this->primeiro;
  this->primeiro = n;
  if (this->quantidade == 0) {
    this->ultimo = n;
  }
  this->quantidade++;
  return true;
}
const std::string& Lista::primeiroElemento() const {
  if (quantidade > 0) {
    return primeiro->valor;
  } else {
    throw std::out_of_range(
        "A lista está vazia. Não é possível acessar o primeiro elemento.");
  }
}
const std::string& Lista::ultimoElemento() const {
  if (quantidade > 0) {
    return ultimo->valor;
  } else {
    throw std::out_of_range(
        "A lista está vazia. Não é possível acessar o último elemento.");
  }
}
unsigned long Lista::tamanho() const { return quantidade; }
std::string Lista::imprimir() const {
  std::ostringstream o;
  o << "{";
  No* p = primeiro;
  while (p != nullptr) {
    o << p->valor;
    if (p->proximo != nullptr) o << ", ";
    p = p->proximo;
  }
  o << "}";
  return o.str();
}
