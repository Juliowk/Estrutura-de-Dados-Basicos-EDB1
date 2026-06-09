//
//  ListaDuplamenteEncadeada.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../header/ListaDuplamenteEncadeada.h"
#include <string>
#include <sstream>

/**
 * @brief Construtor da lista duplamente encadeada.
 *
 * Cria nós sentinelas (cabeça e cauda) e estabelece o encadeamento inicial da lista.
 * Inicializa o contador de elementos como zero.
 */
ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() {
    this->cabeca = new No<std::string>();
    this->cauda = new No<std::string>();

    this->cabeca->setAnterior(nullptr);
    this->cabeca->setProximo(this->cauda);

    this->cauda->setAnterior(this->cabeca);
    this->cauda->setProximo(nullptr);

    this->quantidade = 0;
}

/**
 * @brief Destrutor da lista.
 *
 * Libera a memória de todos os nós (elementos e sentinelas).
 * Após a execução, `cabeca`, `cauda` e `quantidade` são resetados.
 */
ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
    No<std::string>* atual = this->cabeca;

    while (atual != nullptr) {
        No<std::string>* proximo = atual->getProximo();
        delete atual;
        atual = proximo;
    }

    this->cabeca = nullptr;
    this->cauda = nullptr;
    this->quantidade = 0;
}

No<std::string>* ListaDuplamenteEncadeada::getCabeca(void) {
    return this->cabeca;
}

No<std::string>* ListaDuplamenteEncadeada::getCauda(void) {
    return this->cauda;
}

/**
 * @brief Insere @p s em ordem decrescente, mantendo a ordenação.
 * @param s Elemento a ser inserido.
 * @return true se inserido com sucesso, false se já existia.
 */
bool ListaDuplamenteEncadeada::inserirOrdenado(std::string s) {
    
    if (this->vazia()) {
        auto no = new No<std::string>(s);

        this->cabeca->setProximo(no);
        this->cauda->setAnterior(no);

        no->setAnterior(this->cabeca);
        no->setProximo(this->cauda);

        this->quantidade++;
        return true;
    }

    auto elemento = this->cabeca->getProximo(); //primeiro elemento;

    while (elemento != this->cauda) {

        if (elemento->getValor() == s) return false;

        if (elemento->getValor() < s) {
            auto no = new No<std::string>(s);

            elemento->getAnterior()->setProximo(no);
            no->setAnterior(elemento->getAnterior());
            no->setProximo(elemento);
            elemento->setAnterior(no);

            this->quantidade++;
            return true;
        }

        if (elemento->getProximo() == this->cauda) {
            auto no = new No<std::string>(s);
            this->cauda->getAnterior()->setProximo(no);
            no->setAnterior(this->cauda->getAnterior());
            no->setProximo(this->cauda);
            this->cauda->setAnterior(no);

            this->quantidade++;
            return true;
        }

        elemento = elemento->getProximo();
    }

    return false;
}

/**
 * @brief Verifica se a lista está vazia.
 * @return true se a lista estiver vazia, false caso contrário.
 */
bool ListaDuplamenteEncadeada::vazia(void) {
    return this->quantidade == 0;
}

/**
 * @brief Retorna o número de elementos na lista.
 * @return A quantidade de elementos atualmente armazenados.
 */
int ListaDuplamenteEncadeada::tamanho(void) {
    return this->quantidade;
}

/**
 * @brief Retorna uma representação em string da lista, no formato encadeado.
 * @return String representando a lista. Ex.: "A<->B<->C".
 */
std::string ListaDuplamenteEncadeada::imprimir(void) {
    std::stringstream ss;

    No<std::string>* atual = this->cabeca->getProximo();

    while (atual != this->cauda) {
        ss << atual->getValor();

        atual = atual->getProximo();

        if (atual != this->cauda) {
            ss << "<->";
        }
    }

    return ss.str();
}

/**
 * @brief Verifica a integridade estrutural da lista.
 *
 * Confirma:
 * - Ponteiros de cabeça e cauda não nulos.
 * - Encadeamento correto de todos os nós.
 * - Contagem real de nós (excluindo sentinelas) igual ao atributo `quantidade`.
 * - Encadeamento correto em listas vazias (cabeça aponta direto para cauda e vice-versa).
 *
 * @return Um valor da enumeração StatusDaLista que indica se a lista está consistente ou qual problema foi encontrado.
 */
StatusDaLista ListaDuplamenteEncadeada::checarConsistencia(void) {
    if (this->cabeca == nullptr) {
        return CABECA_NULA;
    }

    if (this->cauda == nullptr) {
        return CAUDA_NULA;
    }

    if (this->cabeca->getAnterior() != nullptr) {
        return CABECA_ANTERIOR;
    }

    if (this->cabeca->getProximo() == nullptr) {
        return CABECA_PROXIMO_NULO;
    }

    if (this->cauda->getProximo() != nullptr) {
        return CAUDA_PROXIMO;
    }

    if (this->cauda->getAnterior() == nullptr) {
        return CAUDA_ANTERIOR_NULO;
    }

    if (this->cabeca == this->cauda) {
        return CABECA_CAUDA;
    }

    int contador = 0;
    No<std::string>* atual = this->cabeca;

    while (atual != this->cauda) {
        No<std::string>* proximo = atual->getProximo();

        if (proximo == nullptr) {
            return ENCADEAMENTO_INCORRETO;
        }

        if (proximo->getAnterior() != atual) {
            return ENCADEAMENTO_INCORRETO;
        }

        atual = proximo;

        if (atual != this->cauda) {
            contador++;
        }
    }

    if (contador != this->quantidade) {
        return ENCADEAMENTO_INCORRETO;
    }

    if (this->quantidade == 0) {
        if (this->cabeca->getProximo() != this->cauda ||
            this->cauda->getAnterior() != this->cabeca) {
            return ENCADEAMENTO_INCORRETO;
        }
    }

    return OK;
}

/**
 * @brief Verifica se os elementos estão em ordem decrescente.
 *
 * @return true se a lista estiver ordenada em ordem decrescente,
 *         false caso contrário.
 */
bool ListaDuplamenteEncadeada::checarOrdenacao(void) {
    if (this->quantidade <= 1) {
        return true;
    }

    No<std::string>* atual = this->cabeca->getProximo();

    while (atual->getProximo() != this->cauda) {
        if (atual->getValor() < atual->getProximo()->getValor()) {
            return false;
        }

        atual = atual->getProximo();
    }

    return true;
}