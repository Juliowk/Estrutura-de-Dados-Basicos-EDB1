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
}

int ListaEncadeada::removerTodos(int val)
{
    auto elemento = this->inicio;

    int count = 0;

    while (elemento != nullptr) {
        
        if (elemento == this->inicio && elemento->valor == val) {
            this->inicio = elemento->proximo;
            count++;
        } else if (elemento == this->inicio && elemento->proximo != nullptr && elemento->proximo->valor == val) {
            elemento->proximo = elemento->proximo->proximo;
            count++;
        } else if ( elemento->proximo != nullptr && elemento->proximo->valor == val) {
            elemento->proximo = elemento->proximo->proximo;
            count++;
        }

        elemento = elemento->proximo;
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
