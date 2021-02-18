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
       this->dBits = profundidadeLocal+1;
}

Balde::~Balde(){

}

void Balde::inserirChave(string chave){
    
    // if(qtdChaves>0){

    //     string c1;
    //     string c2;

    //     if(chave < chaves[qtdChaves-1])
    //     {
    //         c1= chave;
    //         c2 = chaves[qtdChaves-1];

    //     }else{
    //          c1= chaves[qtdChaves-1];
    //          c2 = chave ;
    //     }
    //        //cout << "C1: " << c1 << " c2: " << c2 << endl;

    //     int i =0;

    //     while(i < c1.length() && (c1[i]==c2[i]))
    //     {
    //         i++;
    //     }
    //     // if(chaves[this->qtdChaves-1].substr(0,dBits) == chave.substr(0,dBits))
    //     //     this->profundidadeLocal = dBits;
    //     // else
    //     //     this->profundidadeLocal = dBits-1;
    //     profundidadeLocal = i;
    // }
    
    this->chaves.push_back(chave);
    this->setQtdChaves(qtdChaves + 1);
    

}

bool Balde::isFull()
{
    if(this->qtdChaves < this->capacidade)
    {
        cout << "Nao ta cheio " << endl;
                return false;

    }
    cout << "Ta cheio " << endl;

    return true;
}


void Balde::setCapacidade(int M){
    this->capacidade = M;
}

void Balde::setQtdChaves(int k){
    this->qtdChaves = k;
}

void Balde::setChaves(vector<string>chaves){
    this->chaves = chaves;
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

void Balde::calcularProfundidade(){

   
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