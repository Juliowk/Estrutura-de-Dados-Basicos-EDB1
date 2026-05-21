#include "Lista.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

Lista::Lista() {
  this->quantidade = 0;
  this->primeiro = nullptr;
  this->ultimo = nullptr;
}

/**
 * @brief Destrutor da lista. Remove todos os nós alocados dinamicamente.
 */
Lista::~Lista() {
  auto aux = this->primeiro;

  while (aux != nullptr) {
    auto tmp = aux;
    aux = aux->proximo;
    delete tmp;
  }

  this->primeiro = nullptr;
  this->ultimo = nullptr;
  this->quantidade = 0;
}

/**
 * @brief Insere um elemento no início da lista.
 *
 * @param elemento Elemento a ser inserido.
 * @return true se inserido com sucesso.
 */
bool Lista::inserirInicio(const std::string& elemento) {
  No* novo = new No(elemento);
  novo->proximo = this->primeiro;

  this->primeiro = novo;

  if (this->quantidade == 0) {
    this->ultimo = novo;
  }

  this->quantidade++;

  return true;
}

/**
 * @brief Insere um elemento no fim da lista.
 *
 * @param elemento Elemento a ser inserido.
 * @return true se inserido com sucesso.
 */
bool Lista::inserirFim(const std::string& elemento) {
  No* novo = new No(elemento);
  novo->proximo = nullptr;

  if (this->quantidade == 0) {
    this->primeiro = novo;
  }

  this->ultimo->proximo = novo;
  this->ultimo = novo;

  quantidade++;
  return true;
}

/**
 * @brief Insere um elemento na posição i da lista.
 *
 * @param i Posição onde o elemento será inserido.
 * @param elemento Elemento a ser inserido.
 * @return true se a inserção for realizada com sucesso.
 * @throws std::out_of_range se o índice passado como parâmetro for menor do
 que 1 ou maior do que o tamanho+1.
*/
bool Lista::inserirNaPosicao(int i, const std::string& elemento) {
  if (i < 0 || i > (int)this->quantidade + 1) return false;

  if (i == 0) {
    inserirInicio(elemento);
    return true;
  }

  No* noAnterior = this->primeiro;
  for (int j = 1; j < i; j++) noAnterior = noAnterior->proximo;

  No* novo = new No(elemento);
  novo->proximo = noAnterior->proximo;
  noAnterior->proximo = novo;

  this->quantidade++;
  return true;
}

/**
 * @brief Remove o elemento do início da lista.
 *
 * @return true se o elemento for removido com sucesso.
 * @throws std::out_of_range se a lista estiver vazia.
 */
bool Lista::removerInicio() {
  if (this->quantidade == 0) return false;

  auto aux = this->primeiro;
  this->primeiro = this->primeiro->proximo;

  if (this->quantidade == 1) this->ultimo = nullptr;

  delete aux;
  this->quantidade--;
  return true;
}

/**
 * @brief Remove o elemento do fim da lista.
 *
 * @return true se o elemento for removido com sucesso.
 * @throws std::out_of_range se a lista estiver vazia.
 */
bool Lista::removerFim() {
  if (this->quantidade == 0) return false;

  if (this->quantidade == 1) {
    delete this->primeiro;

    this->primeiro = nullptr;
    this->ultimo = nullptr;

  } else {
    auto penultimo = this->primeiro;
    while (penultimo->proximo != this->ultimo) penultimo = penultimo->proximo;

    auto aux = penultimo->proximo;
    penultimo->proximo = nullptr;
    this->ultimo = penultimo;

    delete aux;
  }

  this->quantidade--;
  return true;
}

/**
 * @brief Remove o elemento da posição i da lista.
 *
 * @param i Posição do elemento a ser removido.
 * @return true se o elemento for removido com sucesso.
 * * @throws std::out_of_range se o índice passado como parâmetro for menor
 do que 1 ou maior do que o tamanho.
 */
bool Lista::removerNaPosicao(int i) {
  if (i < 0 || i > (int)this->quantidade - 1) return false;

  if (i == 0) {
    removerInicio();
    return true;
  } else if (i == (int)this->quantidade - 1) {
    removerFim();
    return true;
  }

  auto alvo = this->primeiro;
  No* anterior = nullptr;

  int count = 0;
  while (count != i) {
    anterior = alvo;
    alvo = alvo->proximo;
    count++;
  }

  anterior->proximo = alvo->proximo;

  this->quantidade--;
  delete alvo;
  return true;
}

/**
 * @brief Retorna o primeiro elemento da lista.
 *
 * @return Referência constante para a string armazenada no primeiro nó.
 * @throws std::out_of_range se a lista estiver vazia.
 */
const std::string& Lista::primeiroElemento() const {
  if (quantidade > 0) {
    return primeiro->valor;
  } else {
    throw std::out_of_range(
        "A lista está vazia. Não é possível acessar o primeiro elemento.");
  }
}

/**
 * @brief Retorna o último elemento da lista.
 *
 * @return Referência constante para a string armazenada no último nó.
 * @throws std::out_of_range se a lista estiver vazia.
 */
const std::string& Lista::ultimoElemento() const {
  if (quantidade > 0) {
    return ultimo->valor;
  } else {
    throw std::out_of_range(
        "A lista está vazia. Não é possível acessar o último elemento.");
  }
}

/**
 * @brief Retorna o elemento armazenado na posição i da lista.
 *
 * @param i Índice do elemento a ser acessado.
 * @return Referência constante para a string armazenada na posição i.
 * @throws std::out_of_range se o índice passado como parâmetro for menor do
 que 1 ou maior do que o tamanho.
 */
const std::string& Lista::elementoNaPosicao(int i) const {
  if (i < 0 || i >= (int)this->tamanho())
    throw std::out_of_range("Indice invalido");

  auto aux = this->primeiro;
  int count = 0;

  while (count != i) {
    aux = aux->proximo;
    count++;
  }

  return aux->valor;
}

/**
 * @brief Retorna o número de elementos armazenados na lista.
 *
 * @return Quantidade de elementos.
 */
unsigned long Lista::tamanho() const { return quantidade; }

/**
 * @brief Imprime os elementos da lista no formato: { elem1, elem2, ... }
 */
std::string Lista::imprimir() const {
  std::ostringstream oss;
  oss << "{";
  No* atual = primeiro;
  while (atual != nullptr) {
    oss << atual->valor;
    if (atual->proximo != nullptr) oss << ", ";
    atual = atual->proximo;
  }
  oss << "}";
  return oss.str();
}

/**
 * @brief Remove todos os nós cujo valor é igual ao parâmetro.
 *
 * @param valor Valor a ser removido da lista.
 * @return Quantidade de nós removidos.
 */
int Lista::removerTodos(const std::string& valor) {
  int count = 0;

  auto atual = this->primeiro;
  No* anterior = nullptr;

  while (atual != nullptr) {
    if (atual->valor == valor) {
      if (anterior == nullptr) {
        auto temp = atual;

        this->primeiro = atual->proximo;

        atual = atual->proximo;
        delete temp;
        this->quantidade--;
      } else {
        auto temp = atual;

        anterior->proximo = atual->proximo;
        atual = atual->proximo;

        delete temp;
        this->quantidade--;
      }

      count++;
    } else {
      anterior = atual;
      atual = atual->proximo;
    }
  }

  return count;
}

Lista::No::No(std::string valor) {
  this->valor = valor;
  this->proximo = nullptr;
}

Lista::No::~No() {}