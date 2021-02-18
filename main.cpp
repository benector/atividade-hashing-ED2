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

    int N;
    cout << "Insira o numero de tentativas" << endl;
    cin >> N;
    
    cout << endl;

    Diretorio *diretorio = new Diretorio(M,B);

    // ofstream outfile("relatorio.txt");


    // cout << "Inserindo chaves" << endl;
    // srand(time(NULL));

    // int tam = pow(2,B);
    // for (int i = 0; i < N; i++)
    // {
    //     int num = rand() % tam ;
    //     outfile << "Inserindo chave "<<toBinary(num,B) << endl;
    //     diretorio->inserirChave(num);
    //     diretorio->imprimirDiretorio();
    //     diretorio->imprimeDiretorioSaida(outfile);

    // }
    
    // outfile.close();
        diretorio->inserirChave(0);
    diretorio->imprimirDiretorio();

    diretorio->inserirChave(5);
    diretorio->imprimirDiretorio();

  diretorio->inserirChave(14);
    diretorio->imprimirDiretorio();

    diretorio->inserirChave(15);
    diretorio->imprimirDiretorio();

  diretorio->inserirChave(3);
   diretorio->imprimirDiretorio();


 diretorio->inserirChave(7);
     diretorio->imprimirDiretorio();

       diretorio->inserirChave(2);
      diretorio->imprimirDiretorio();
     diretorio->inserirChave(6);
      diretorio->imprimirDiretorio();
        diretorio->inserirChave(4);
      diretorio->imprimirDiretorio();

      cout <<"quantidade de chaves: "<< diretorio->getQtdRegistros() << endl;
//     diretorio->inserirChave(0);
//     diretorio->imprimirDiretorio();

//     diretorio->inserirChave(5);
//     diretorio->imprimirDiretorio();

//     diretorio->inserirChave(14);
//     diretorio->imprimirDiretorio();

//     diretorio->inserirChave(3);
//     diretorio->imprimirDiretorio();


  

//    diretorio->inserirChave(16);




//     diretorio->imprimirDiretorio();

    //balde->imprimirBalde();


    // int num = 20;
    // string binario = toBinary(num);


   // delete [] diretorio;
    system("pause");

    return 0;
}