#ifndef LLDE_H
#define LLDE_H

#include <no.h>

namespace ggs{
    class LLDE //Lista Linear Duplamente Encadeada
    {
    private:
        int quantidadeElementos;
        ggs::No *inicio;
        ggs::No *fim;
    public:
        LLDE();
        int getQuantidadeElementos() const;
        bool estaVazia()const;

        void inserirInicio(int elemento);
        int retirarInicio();
        int acessarInicio()const;

        void inserirFinal(int elemento);
        int retirarFinal();
        int acessarFinal()const;

        void inserirPosicao(int elemento, int posicao);
        int retirarPosicao(int posicao);
        int acessarPosicao(int posicao)const;

        void ordenarCrescente();
        void ordenarDecrescente();

        QString obterDadosLLDE()const;
    };
}

#endif // LLDE_H
