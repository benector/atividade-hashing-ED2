#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include "Balde.h"
#include "Diretorio.h"



using namespace std; 

Balde::Balde(){
    
    this->qtdChaves = 0;
    this->profundidadeLocal = 0;

};

Balde::Balde(int M, int profundidadeLocal){
       this->capacidade = M;
       this->profundidadeLocal = profundidadeLocal;
       this->qtdChaves = 0;
}

Balde::~Balde(){

}

void Balde::inserirChave(string chave){
    
    this->chaves.push_back(chave);
    this->setQtdChaves(this->qtdChaves + 1);
    

}

bool Balde::isFull()
{
    if(this->qtdChaves == this->capacidade)
        return true;
    return false;
}


void Balde::setCapacidade(int M){
    this->capacidade = M;
}

void Balde::setQtdChaves(int k){
    this->qtdChaves = k;
}

void Balde::setProfundidadeLocal(int val){
    this->profundidadeLocal = val;
}

void Balde::setDBits(int d){
    this->dBits = d;
}

int Balde::getCapacidade(){
    return this->capacidade;
}

int Balde::getQtdChaves(){
    return this->qtdChaves;
}

vector <string>  Balde::getChaves(){
    return this->chaves;
}

int Balde::getProfundidadeLocal(){
    return this->profundidadeLocal;
}

int Balde::getDBits(){
    return this->dBits;;
}

void Balde::removeChave(int i)
{
    chaves.erase(chaves.begin()+i);
    this->setQtdChaves(qtdChaves-1);

}

void Balde::imprimirBalde(){

    cout << "====IMPRIMINDO BALDE ====" << endl;
    vector<string>::iterator it= this->chaves.begin();

    for(it; it!= this->chaves.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << "========================" << endl;
}