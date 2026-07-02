#include <string>
#include "No.h"

class ListaEncadeada
{
public:      
    No<int>* inicio;

    int quantidade;
    
    ListaEncadeada();
    
    ~ListaEncadeada();
    
    void inserirNoInicio(int);

    int removerTodos(int);

    std::string imprimir();
    
    No<int>* getInicio();

    void setInicio(No<int>*); 
};
