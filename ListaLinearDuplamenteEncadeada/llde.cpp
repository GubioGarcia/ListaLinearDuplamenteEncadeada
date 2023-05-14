#include "llde.h"

namespace ggs{
    int LLDE::getQuantidadeElementos() const{
        return quantidadeElementos;
    }

    LLDE::LLDE():
        quantidadeElementos(0), inicio(0), fim(0)
    {}

    bool LLDE::estaVazia() const{
        return (quantidadeElementos == 0);
    }

    QString LLDE::obterDadosLLDE()const{
        if(estaVazia()) throw QString("Lista esta Vazia - obterDadosLLSE");
        No* auxiliar = inicio;
        QString saida = "";
        for(int i=0; i<quantidadeElementos; i++){
            saida += "|" + QString::number(auxiliar->getDado()) + "|";
            auxiliar = auxiliar->getEnderecoProximo();
            if(i<quantidadeElementos-1) saida += " -> ";
        }
        return saida;
    }

    void LLDE::inserirInicio(int elemento){
        try{
            No *auxiliar = new No(elemento);
            if(estaVazia()){
                inicio = fim = auxiliar;
                quantidadeElementos++;
                return;
            }
            auxiliar->setEnderecoProximo(inicio);
            inicio->setEnderecoAnterior(auxiliar);
            inicio = auxiliar;
            quantidadeElementos++;
        } catch (std::bad_alloc &erro){
            throw QString("No não foi criado - ERRO DE MEMORIA - inserirInicio");
        }
    }

    int LLDE::acessarInicio()const{
        if(estaVazia()) throw QString("Lista está vazia - acessarInicio");
        return inicio->getDado();
    }

    int LLDE::retirarInicio(){
        if(estaVazia()) throw QString("Lista está vazia - retirarInicio");
        int valor = inicio->getDado();
        if(quantidadeElementos == 1){
            quantidadeElementos--;
            delete inicio;
            inicio = fim = 0;
            return valor;
        }
        inicio = inicio->getEnderecoProximo();
        delete inicio->getEnderecoAnterior();
        inicio->setEnderecoAnterior(0);
        quantidadeElementos--;
        return valor;
    }

    void LLDE::inserirFinal(int elemento){
        try {
            No *auxiliar = new No(elemento);
            if(estaVazia()){
                quantidadeElementos++;
                inicio = fim = auxiliar;
                return;
            }
            fim->setEnderecoProximo(auxiliar);
            auxiliar->setEnderecoAnterior(fim);
            quantidadeElementos++;
            fim = auxiliar;
        } catch (std::bad_alloc &erro) {
            throw QString("No não foi criado - ERRO DE MEMORIA - inserirFinal");
        }
    }

    int LLDE::acessarFinal()const{
        if(estaVazia()) throw QString("Lista está vazia - acessarFinal");
        return fim->getDado();
    }

    int LLDE::retirarFinal(){
        if(estaVazia()) throw QString("Lista esta Vazia - retirarFinal");
        if(quantidadeElementos == 1){
            No* aux = fim;
            int valor = fim->getDado();
            quantidadeElementos--;
            inicio = fim = 0;
            delete aux;
            return valor;
        }
        int valor = fim->getDado();
        No *aux = fim;
        fim = aux->getEnderecoAnterior();
        fim->setEnderecoProximo(0);
        quantidadeElementos--;
        delete aux;
        return valor;
    }

    void LLDE::inserirPosicao(int elemento, int posicao){
        try {
            if(posicao < 0 || posicao > quantidadeElementos) throw QString("Posição fora do intervalo válido - acessarPosicao");
            if(posicao == 0) return inserirInicio(elemento);
            if(posicao == quantidadeElementos) return inserirFinal(elemento);
            No *aux = inicio;
            for(int i=0; i < posicao-1; i++){
                aux = aux->getEnderecoProximo();
            }
            No *novoNo = new No(elemento);
            quantidadeElementos++;
            novoNo->setEnderecoProximo(aux->getEnderecoProximo());
            novoNo->setEnderecoAnterior(aux);
            aux->setEnderecoProximo(novoNo);
        } catch (std::bad_alloc &erro) {
            throw QString("No não foi criado - ERRO DE MEMORIA - inserirFinal");
        }
    }

    int LLDE::acessarPosicao(int posicao)const{
        if(estaVazia()) throw QString("Lista está vazia - acessarPosicao");
        if(posicao < 0 || posicao >= quantidadeElementos) throw QString("Posição fora do intervalo válido - acessarPosicao");
        if(posicao == 0) return acessarInicio();
        if(posicao == quantidadeElementos - 1) return acessarFinal();
        No *aux = inicio;
        for(int i=0; i < posicao; i++){
            aux = aux->getEnderecoProximo();
        }
        return aux->getDado();
    }

    int LLDE::retirarPosicao(int posicao){
        if(estaVazia()) throw QString("Lista está vazia - retirarPosicao");
        if(posicao < 0 || posicao >= quantidadeElementos) throw QString("Posição fora do intervalo válido - acessarPosicao");
        if(posicao == 0) return retirarInicio();
        if(posicao == quantidadeElementos - 1) return retirarFinal();
        No *aux = inicio;
        for(int i=0; i < posicao; i++){
            aux = aux->getEnderecoProximo();
        }
        int valor = aux->getDado();
        aux->getEnderecoAnterior()->setEnderecoProximo(aux->getEnderecoProximo());
        aux->getEnderecoProximo()->setEnderecoAnterior(aux->getEnderecoAnterior());
        delete aux;
        quantidadeElementos--;
        return valor;
    }

    void LLDE::ordenarCrescente(){
        if(estaVazia()) throw QString("Lista está vazia - ordenarCrescente");
        if(quantidadeElementos == 1) return;
        No *i, *j;
        int menorValor;
        for (i = inicio; i != nullptr; i = i->getEnderecoProximo()) {
            menorValor = i->getDado();
            No *noMenorValor = i;
            for (j = i->getEnderecoProximo(); j != nullptr; j = j->getEnderecoProximo()) {
                if (j->getDado() < menorValor) {
                    menorValor = j->getDado();
                    noMenorValor = j;
                }
            }
            if (noMenorValor != i) {
                int aux = i->getDado();
                i->setDado(menorValor);
                noMenorValor->setDado(aux);
            }
        }
    }

    void LLDE::ordenarDecrescente(){
        if(estaVazia()) throw QString("Lista está vazia - ordenarDecrescente");
        if(quantidadeElementos == 1) return;
        No *i, *j;
        int maiorValor;
        for (i = inicio; i != nullptr; i = i->getEnderecoProximo()) {
            maiorValor = i->getDado();
            No *noMaiorValor = i;
            for (j = i->getEnderecoProximo(); j != nullptr; j = j->getEnderecoProximo()) {
                if (j->getDado() > maiorValor) {
                    maiorValor = j->getDado();
                    noMaiorValor = j;
                }
            }
            if (noMaiorValor != i) {
                int aux = i->getDado();
                i->setDado(maiorValor);
                noMaiorValor->setDado(aux);
            }
        }
    }
}
