#include "no.h"

namespace ggs {
    No::No():
        dado(0), enderecoProximo(0)
    {}

    No::No(int dado):
        dado(dado), enderecoProximo(0)
    {}

    No *No::getEnderecoProximo() const
    {
        return enderecoProximo;
    }

    void No::setEnderecoProximo(No *newEnderecoProximo)
    {
        enderecoProximo = newEnderecoProximo;
    }

    No *No::getEnderecoAnterior() const
    {
        return enderecoAnterior;
    }

    void No::setEnderecoAnterior(No *newEnderecoAnterior)
    {
        enderecoAnterior = newEnderecoAnterior;
    }

    int No::getDado() const
    {
        return dado;
    }

    void No::setDado(int newDado)
    {
        dado = newDado;
    }
}
