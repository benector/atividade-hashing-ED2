#ifndef BALDE_H
#define BALDE_H
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

class Balde{
    public:
        Balde();
        Balde(int M, int profundidadeLocal);
        ~Balde();
        int getChave(int k);
        void inserirChave(string chave);
        void setCapacidade(int M);
        void setQtdChaves(int k);
        void setProfundidadeLocal(int val);
        void setDBits(int d);
        void removeChave(int i);
        void imprimirBalde();
        int getCapacidade();
        int getQtdChaves();
        vector <string> getChaves();
        int getProfundidadeLocal();
        int getDBits();
        bool isFull();

        string toBinary(int val, int numBits);


    private:
        vector <string> chaves;
        int dBits;
        int capacidade;
        int profundidadeLocal;
        int qtdChaves;
};

#endif // BALDE_H
