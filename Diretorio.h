#ifndef DIRETORIO_H
#define DIRETORIO_H
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include "Balde.h"

class Diretorio{
    public:
        Diretorio();
        Diretorio(int M);
        ~Diretorio();
        Balde buscarBalde(int k);
        void alocarBalde(int inicio);
        void inserirBalde(Balde *balde);
        void dividirBalde(map<string, Balde*>::iterator posicaoBaldeCheio, string chave);
        void duplicarDiretorio();
        void setProfundidadeGlobal(int M);
        void setQtdBaldes(int k);
        void inserirChave(string chave);
        void imprimirDiretorio();
        int getProfundidadeGlobal();
        int getQtdBaldes();
        string getPosicaoDiretorio(string chave);
        string toBinary(int n, int B);


    private:
        map <string, Balde*> baldes; 
        int tamBaldes;
        int profundidadeGlobal;
        int qtdBaldes;

};

#endif //DIRTORIO_H