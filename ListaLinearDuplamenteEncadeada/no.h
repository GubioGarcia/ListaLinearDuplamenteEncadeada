#ifndef NO_H
#define NO_H

#include <QString>

namespace ggs{
    class No
    {
    private:
        int dado;
        No* enderecoProximo;
        No* enderecoAnterior;
    public:
        No();
        No(int dado);

        int getDado() const;
        void setDado(int newDado);
        No *getEnderecoProximo() const;
        void setEnderecoProximo(No *newEnderecoProximo);
        No *getEnderecoAnterior() const;
        void setEnderecoAnterior(No *newEnderecoAnterior);
    };
}
#endif // NO_H
