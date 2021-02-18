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
        Diretorio(int M,int B);
        ~Diretorio();
        int buscarChave(string chave);
        void alocarBalde(int inicio, int profundidade);
        void inserirBalde(Balde *balde);
        void dividirBalde(int posicaoBaldeCheio, int chave);
        void duplicarDiretorio(int posicaoBaldeCheio, int chave);
        void juntarBaldes(int posicaoBaldeCheio);
        void setProfundidadeGlobal(int M);
        void setQtdBaldes(int k);
        void inserirChave(int chave);
        void imprimirDiretorio();
        void imprimeDiretorioSaida(ofstream &outfile);
        int getProfundidadeGlobal();
        int getQtdBaldes();
        int getQtdRegistros();
        int getPosicaoDiretorio(int chave);
        void redistribuirChaves();
        string toBinary(int n, int B);


    private:
        map <int, Balde*> baldes; 
        int tamBaldes;
        int profundidadeGlobal;
        int qtdBaldes;
        int bitsChave;
        int qtdRegistros;
        int fatorDeCarga;
        

};

#endif //DIRTORIO_H