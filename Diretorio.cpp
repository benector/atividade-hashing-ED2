#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include "Balde.h"
#include "Diretorio.h"


using namespace std; 

Diretorio::Diretorio(int M){
    
    this->tamBaldes = M;
    this->profundidadeGlobal =1;
    this->alocarBalde(0);
    this->qtdBaldes = 1;


};


Diretorio::~Diretorio(){
    
}

string Diretorio::toBinary(int val, int numBits)
{
    string r;
    while(val!=0) {r=(val%2==0 ?"0":"1")+r; val/=2;}
    
    int tamanho = r.length() ;
    if(tamanho <numBits)
    {
        string formatted = string(numBits - tamanho, '0') + r;
        return formatted;
    }
    return r;
    
}

void Diretorio::alocarBalde(int inicio){
    
    cout << "ALocando balde" <<  endl;

    cout << "Criando balde" <<  endl;

    Balde *balde = new Balde(this->tamBaldes,this->profundidadeGlobal -1);

    // cout << "Profundidade global: " << this->profundidadeGlobal << endl;
    // De i até 2 elevado a profundidade global que é o número de entradas do diretório

    int nBits = pow(2, this->profundidadeGlobal);

    // cout << "N bits: " << nBits <<endl;
    for(int i = inicio; i<nBits ; i++)
    {
        this->baldes.insert(make_pair(this->toBinary(i, nBits), balde));
    }
    this->setQtdBaldes(this->qtdBaldes+1);


}
void Diretorio::inserirBalde(Balde *balde){

    
    this->baldes.insert(make_pair(this->toBinary(this->qtdBaldes, this->profundidadeGlobal), balde));
    this->setQtdBaldes(this->qtdBaldes+1);
}


string Diretorio::getPosicaoDiretorio(string chave){
    
    return chave.substr(0,pow(2,this->profundidadeGlobal));

}
void Diretorio::inserirChave(string chave){
    
    cout << "Tentando inserir chave " << chave << endl;

    string posicao = this->getPosicaoDiretorio(chave);

    cout << "Posicao: " << posicao << endl;

    //Checar se existe posição no diretório para essa chave
    if (baldes.find(posicao) == baldes.end())
    {
        //Se não, ele cria a chave e adiciona 1 registro a ela
        cout << "Sem espaço" << endl;
    }
    else
    {
        //Se existe checa se o balde está cheio
        if(!(baldes[posicao]->isFull()))
            baldes[posicao]->inserirChave(chave);
        else if (baldes[posicao]->getProfundidadeLocal() < this->profundidadeGlobal){
            cout << "Dividindo balde" << endl;
            dividirBalde(baldes.find(posicao), chave);
            baldes[posicao]->inserirChave(chave);
        }
    }
    cout << endl;
}

void Diretorio::dividirBalde(map<string, Balde*>::iterator posicaoBaldeCheio, string chave){
    
    cout << "Posicao balde cheio: " << posicaoBaldeCheio->first << endl;
    //Criando um novo balde
    Balde *novoBalde = new Balde(this->tamBaldes,this->profundidadeGlobal);

    //Obtendo outra posição que aponta para obalde cheio e que receberá o balde novo
    map<string, Balde*>::iterator posicaoBaldeNovo;

    //Obtendo outra posição que aponta para o balde cheio guardando o novo balde nessa posição
    if((posicaoBaldeCheio != baldes.end()) && ( next(posicaoBaldeCheio,1)->second == posicaoBaldeCheio->second))
        posicaoBaldeNovo = next(posicaoBaldeCheio,1);
    else
        posicaoBaldeNovo = prev(posicaoBaldeCheio,1);

    posicaoBaldeNovo->second = novoBalde;

    Balde *baldeNovo = posicaoBaldeNovo->second;

    cout << "Posicao balde novo: " << posicaoBaldeNovo->first << endl;

    //Obtendo balde cheio

    Balde *baldeCheio = posicaoBaldeCheio->second;
    //Obtendo chaves do balde cheio
    vector <string> chaves = baldeCheio->getChaves();
    
    //Ajustando poteiros e dLocal e redistribuindo as chaves
    for(int i = 0; i<baldeCheio->getQtdChaves(); i++)
    {
        cout << "Chave balde cheio: "<< posicaoBaldeCheio->first <<endl;
        cout << "Balde para a chave" << chaves[i] << ": " << this->getPosicaoDiretorio(chaves[i]) <<endl;

        if(posicaoBaldeCheio->first != this->getPosicaoDiretorio(chaves[i])){

            baldeNovo->inserirChave(chaves[i]);
            baldeCheio->removeChave(i);
        }
    }
    baldeCheio->setProfundidadeLocal(baldeCheio->getProfundidadeLocal()+1);

}

void Diretorio::setProfundidadeGlobal(int K){
    this->profundidadeGlobal = K;
}

void Diretorio::setQtdBaldes(int k){
    this->qtdBaldes = k;
}

int Diretorio::getProfundidadeGlobal(){
    return this->profundidadeGlobal;
}

int Diretorio::getQtdBaldes(){
    return this->qtdBaldes;
}

void Diretorio::imprimirDiretorio()
{
    map<string,Balde*>::iterator it= this->baldes.begin();
    
    cout << "====IMPRIMINDO DIRETORIO E BALDES====" << endl;

    cout << endl;
    for (it; it!=baldes.end(); ++it)
    {
        cout << "[" << it->first << "] ";
        
        for(int i=0; i< it->second->getQtdChaves(); i++)
        {
            if(i>0)
             cout <<  setfill (' ') << setw (it->first.length()+8);
            
            cout  << it->second->getChaves()[i]  ;
            
            if(i==0)
            cout << " [" <<it->second->getProfundidadeLocal() << "]" << endl;
            cout << endl;
            
        }
        cout<<endl;
    }
    cout << "========================" << endl;

}


