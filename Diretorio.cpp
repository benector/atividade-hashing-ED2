#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include "Balde.h"
#include "Diretorio.h"


using namespace std; 

Diretorio::Diretorio(int M, int B){
    
    this->tamBaldes = M;
    this->profundidadeGlobal =1;
    this->alocarBalde(0, profundidadeGlobal-1);
    this->qtdBaldes = 1;
    this->bitsChave = B;
    this->qtdRegistros = 0;

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
        r = string(numBits - tamanho, '0') + r;
    }
    
    //cout << "Binario formatado: " << r << endl;

    return r;
    
}

void Diretorio::alocarBalde(int inicio, int profundidade){
    
    cout << "ALocando balde" <<  endl;

    cout << "Criando balde" <<  endl;

    Balde *balde = new Balde(this->tamBaldes,profundidade);

    // cout << "Profundidade global: " << this->profundidadeGlobal << endl;
    // De i até 2 elevado a profundidade global que é o número de entradas do diretório

    int nBits = pow(2, this->profundidadeGlobal);

    // cout << "N bits: " << nBits <<endl;
    for(int i = inicio; i<nBits ; i++)
    {
        this->baldes.insert(make_pair(i, balde));
    }
    this->setQtdBaldes(this->qtdBaldes+1);


}

int  Diretorio::buscarChave(string chave){

    int i = getPosicaoDiretorio(stoull(chave,0,2));
        cout << "posicao: " << i << endl;

    if (baldes.find(i) == baldes.end())
    {
        //Se não, ele cria a chave e adiciona 1 registro a ela
        cout << "A chave nao existe nos registros" << endl;
        return -1;
    }
    else
    {
        for(int k =0; k< baldes[i]->getQtdChaves(); k++)
        {
            if(baldes[i]->getChaves()[k] == chave)
            {
                cout << "Chave encontrada no balde " << i << endl;
                return i;
            }
        }  
        cout << "A chave não existe nos registros" << endl;
        return -1;
    }
}

void Diretorio::inserirBalde(Balde *balde){

    
    this->baldes.insert(make_pair(qtdBaldes, balde));
    this->setQtdBaldes(this->qtdBaldes+1);
}


int Diretorio::getPosicaoDiretorio(int chave){
    
    int bits = profundidadeGlobal;
    
    //Calcula posicao no diretorio a partir dos dBits
    string hash = toBinary(chave, bitsChave).substr(0,profundidadeGlobal);

    ///Converte o binario para inteiro
    int posicao = stoull(hash, 0, 2);
    return posicao;

}
void Diretorio::inserirChave(int chave){
    
    cout << "Tentando inserir chave " << chave << " [ " << toBinary(chave, bitsChave) << " ]" << endl;

    cout << "Verificando se a chave já existe nos registros..." << endl;

    if(buscarChave(toBinary(chave,bitsChave)) == -1)
    {
        int posicao = this->getPosicaoDiretorio(chave);

        //Checar se existe posição no diretório para essa chave
        if (baldes.find(posicao) == baldes.end())
        {
            //Se não, ele cria a chave e adiciona 1 registro a ela
            cout << "Sem espaço" << endl;
        }
        else
        {
            //Se existe checa se o balde está cheio
            cout<< "Quatidade de chaves no balde: " << baldes[posicao]->getQtdChaves() << endl;
            if(!(baldes[posicao]->isFull()))
            {
                  baldes[posicao]->inserirChave(toBinary(chave, bitsChave));
                    qtdRegistros++;
            }
            else if (baldes[posicao]->getProfundidadeLocal() < this->profundidadeGlobal){
                cout << "Dividindo balde" << endl;
                dividirBalde(posicao, chave);
                baldes[posicao]->inserirChave(toBinary(chave, bitsChave));
                qtdRegistros++;

            }else{
                cout << "Duplicando diretorio" << endl;
                duplicarDiretorio(posicao,chave);
                baldes[getPosicaoDiretorio(chave)]->inserirChave(toBinary(chave, bitsChave));
                qtdRegistros++;

            }
        }
    }
    cout << endl;
}

void Diretorio::dividirBalde(int posicaoBaldeCheio, int chave){
    cout<< "PROFUNDIDADE GLOBAL: " <<profundidadeGlobal << endl;
    cout << "Posicao balde cheio: " << posicaoBaldeCheio<< endl;
    //Criando um novo balde
    Balde *novoBalde = new Balde(this->tamBaldes,this->profundidadeGlobal);

    int posicaoBaldeNovo;

    //Obtendo outra posição que aponta para o balde cheio guardando o novo balde nessa posição
    cout << "Qtd baldes: " << qtdBaldes << endl;
    if((posicaoBaldeCheio ==0) || ((posicaoBaldeCheio < qtdBaldes-1) && ( baldes[posicaoBaldeCheio] == baldes[posicaoBaldeCheio+1])))
        posicaoBaldeNovo = posicaoBaldeCheio+1;
    else 
        posicaoBaldeNovo = posicaoBaldeCheio-1;

    baldes[posicaoBaldeNovo]= novoBalde;

    Balde *baldeNovo = baldes[posicaoBaldeNovo];

    cout << "Posicao balde novo: " << posicaoBaldeNovo << endl;

    //Obtendo balde cheio

    Balde *baldeCheio = baldes[posicaoBaldeCheio];
    //Obtendo chaves do balde cheio
    vector <string> chaves = baldeCheio->getChaves();
    
    int qtdChaves = baldeCheio->getQtdChaves();

    int i = 0;
    //Ajustando poteiros e dLocal e redistribuindo as chaves
    for(int cont  = 0; cont<qtdChaves; cont++)
    {
        cout << "CHAVE: " << chaves[i] << endl;
        //binario 2 digitos da chave
        string dBits =  chaves[i].substr(0,profundidadeGlobal);
        string binPosicao = toBinary(posicaoBaldeCheio,profundidadeGlobal);
        cout << "dbITS: "<< dBits << "  Binario posicao balde cheio:  " << binPosicao << endl;
        cout << "Balde para a chave" << chaves[i] << " : " << chaves[i].substr(0,this->profundidadeGlobal) << " = " << stoull(dBits,0,2)<<endl;

        if(binPosicao != dBits){
            cout << "Removendo chave" << chaves[i] << endl;
            baldeNovo->inserirChave(chaves[i]);
            baldeCheio->removeChave(i);
        }
        i++;
        //cout << "Chave que ficou no lugar: " << baldes[posicaoBaldeCheio]->getChaves()[i] << endl;

    }
     
    baldeCheio->setProfundidadeLocal(baldeCheio->getProfundidadeLocal()+1);
    qtdBaldes+=1;

}

void Diretorio::duplicarDiretorio(int posicaoBaldeCheio, int chave){

    cout << "Posicao balde cheio: " << posicaoBaldeCheio << endl;
    this->setProfundidadeGlobal(this->getProfundidadeGlobal()+1);

    int tamanho = pow(2, profundidadeGlobal);

    for(int i = tamanho/2; i<tamanho; i++)
    {
        Balde *balde = new Balde(tamBaldes, profundidadeGlobal);
        this->baldes.insert(make_pair(i,balde));
    }

    //Criando balde novo
    Balde *novoBalde = new Balde(this->tamBaldes,this->profundidadeGlobal);
    novoBalde->setDBits(profundidadeGlobal);
    qtdBaldes+=1;

    
    for(int i = tamanho-1, j=(tamanho/2)-1; i>0; i-=2,j--)
    {
        //int deslocado = i >> 1;
        cout << "Balde[" <<i << "]" <<  "aponta para balde " << "Balde[" <<j<< "]" <<  endl;
        // if(i<tamanho/2){
        //     cout << "Chave balde i" << baldes[i]->getChaves()[0]<< endl;
        //     cout << "Chave balde i" << baldes[j]->getChaves()[0]<< endl;

        // }
       // cout << "Tamanho/2-1: " << (tamanho/2)-1 << endl;
        //baldes[i]->setProfundidadeLocal(baldes[i]->getProfundidadeLocal()+1);
        //if((i-1)>0)
        baldes[i] = baldes[j];
        baldes[i-1] = baldes[j];

        // if(i<tamanho/2)
        // cout << "Chave balde i após arrumado" << baldes[i]->getChaves()[0]<< endl;

    }
    dividirBalde(posicaoBaldeCheio,chave);

    // cout << "Posicao balde cheio apos duplicação: " << posicaoBaldeCheio << endl;
    // int posicaoBaldeNovo;

    // //Obtendo outra posição que aponta para o balde cheio guardando o novo balde nessa posição
    // if((posicaoBaldeCheio ==0) || ((posicaoBaldeCheio < qtdBaldes-1) && ( baldes[posicaoBaldeCheio] == baldes[posicaoBaldeCheio+1])))
    //     posicaoBaldeNovo = posicaoBaldeCheio+1;
    // else
    //     posicaoBaldeNovo = posicaoBaldeCheio-1;

    // cout << "Posicao balde novo: " << posicaoBaldeNovo << endl;

    // baldes[posicaoBaldeNovo]= novoBalde;

    // // Percorre as chaves do balde cheio removendo aquelas
    // // Que não se encaixam mais nessa posição

    // vector <string> chaves = baldes[posicaoBaldeCheio]->getChaves();

    // for(int i =0; i<baldes[posicaoBaldeCheio]->getQtdChaves();i++)
    // {
    //     //1000 => 10
    //     string chave =  chaves[i].substr(0,profundidadeGlobal);

    //     //1 => 01
    //     string chavePosicao = toBinary(posicaoBaldeCheio,pow(2,this->profundidadeGlobal));

    //     //Se os d bits mais a esquerda desas chaves nesse balde não mais correspondem
    //     //A chave dessa possicao, removemos e inserimos na posição correta
    //     if(chave != chavePosicao){

    //         cout << "Removendo chave " << chaves[i] << endl;
    //        // cout << "i: " << i << endl;
    //         baldes[posicaoBaldeCheio]->removeChave(i);

    //         cout << "Posicao certa para essa chave: " << chave<< endl;
    //         baldes[getPosicaoDiretorio(stoull(chaves[i],0,2))]->inserirChave(chaves[i]);
    //       // cout << "Chave que ficou no lugar: " << baldes[posicaoBaldeCheio]->getChaves()[i] << endl;
    //     }
        
    // }
    baldes[posicaoBaldeCheio]->setProfundidadeLocal(baldes[posicaoBaldeCheio]->getProfundidadeLocal()+1);
    
    
}

void Diretorio::juntarBaldes(int posicaoBaldeCheio){

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

int Diretorio::getQtdRegistros(){
    return this->qtdRegistros;
}

void Diretorio::imprimirDiretorio()
{    
    cout << "====IMPRIMINDO DIRETORIO E BALDES====" << endl;

    cout << endl;
    cout<< "[" << profundidadeGlobal << "]" <<endl;
    cout << endl;
    for (int i =0; i< pow(2,profundidadeGlobal); i++)
    {
        string chavePosicao = toBinary(i,profundidadeGlobal);
        cout << "[" << chavePosicao<< "] ";
        
        for(int j=0; j< baldes[i]->getQtdChaves(); j++)
        {
            if(j>0)
             cout <<  setfill (' ') << setw (chavePosicao.length()+8);
            
            cout  << baldes[i]->getChaves()[j]  ;
            
            if(j==0)
            cout << " [" <<baldes[i]->getProfundidadeLocal() << "]" << endl;
           
            cout << endl;
            
        }
        cout << endl;        

    }
    
    cout << "========================" << endl;

}

void Diretorio::imprimeDiretorioSaida(ofstream &outfile)
{
    
    outfile << "====IMPRIMINDO DIRETORIO E BALDES====" << endl;

    outfile << endl;
    outfile<< "[" << profundidadeGlobal << "]" <<endl;
    outfile << endl;
    for (int i =0; i< pow(2,profundidadeGlobal); i++)
    {
        string chavePosicao = toBinary(i,profundidadeGlobal);
        outfile << "[" << chavePosicao<< "] ";
        
        for(int j=0; j< baldes[i]->getQtdChaves(); j++)
        {
            if(j>0)
             outfile <<  setfill (' ') << setw (chavePosicao.length()+8);
            
            outfile  << baldes[i]->getChaves()[j]  ;
            
            if(j==0)
            outfile << " [" <<baldes[i]->getProfundidadeLocal() << "]" << endl;
           
            outfile << endl;
            
        }
        outfile << endl;        

    }
    
    outfile << "========================" << endl;
}


