//
//  ListaEncadeada.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "../header/ListaEncadeada.h"
#include "../header/No.h"
#include <iostream>
#include <string>
#include <sstream>

ListaEncadeada::ListaEncadeada()
{
    this->inicio = nullptr;
    this->quantidade = 0;
}

ListaEncadeada::~ListaEncadeada()
{
    // To-Do
}

void ListaEncadeada::inserirNoInicio(int e)
{
    auto n = new No<int>(e);
    if (inicio == nullptr)
        inicio = n;
    else
    {
        n->setProximo(inicio);
        inicio = n;
    }
    this->quantidade++;
}

int ListaEncadeada::removerTodos(int val) {
    auto atual = this->inicio;
    No<int>* anterior = nullptr;

    int count = 0;

    while (atual != nullptr) {

        auto proximo = atual->getProximo();

        if (atual->getValor() == val) {
            if (atual == this->inicio)
                this->inicio = atual->getProximo();
            else
                anterior->setProximo(proximo);

            count++;
            delete atual;
        } else{
            anterior = atual;
        }

        atual = proximo;
    }

    return count;
}

No<int> *ListaEncadeada::getInicio()
{
    return this->inicio;
}

std::string ListaEncadeada::imprimir()
{
    std::stringstream resultado;

    auto no = this->getInicio();

    while (no != nullptr)
    {
        resultado << no->getValor() << "->";
        no = no->getProximo();
    }
    resultado << "null";

    return resultado.str();
}
