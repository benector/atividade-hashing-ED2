#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include "Balde.h"
#include "Diretorio.h"


using namespace std;

string toBinary(int val, int numBits)
{
    string r;
    while(val!=0) {r=(val%2==0 ?"0":"1")+r; val/=2;}
    
    int tamanho = r.length() ;
    if(tamanho < numBits)
    {
        string formatted = string(numBits - tamanho, '0') + r;
        return formatted;
    }
    return r;
    
}

int main()
{
    int M;
    cout << "Insira a capacidade dos baldes" << endl;
    cin >> M;

    int B;
    cout << "Insira a quantidade de bits das pseudo-chaves" << endl;
    cin >> B;

    int C;
    cout << "Insira a chave desejada" << endl;
    cin >> C;

    Diretorio *diretorio = new Diretorio(M);
    
    cout << "Inserindo chaves" << endl;
    diretorio->inserirChave(toBinary(1,B));
    diretorio->inserirChave(toBinary(8,B));
    diretorio->inserirChave(toBinary(10,B));
    diretorio->inserirChave(toBinary(3,B));




    diretorio->imprimirDiretorio();

    //balde->imprimirBalde();


    // int num = 20;
    // string binario = toBinary(num);


   // delete [] diretorio;
    system("pause");

    return 0;
}