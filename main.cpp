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

    Diretorio *diretorio1 = new Diretorio(M,B);
    Diretorio *diretorio2 = new Diretorio(M,B);


    ofstream outfile("relatorio.txt");

    cout << "Inserindo chaves aleatórias" << endl;
    int tam = pow(2,B);

    for (int i = 0; i < N; i++)
    {
        int num = rand() % tam ;
        outfile << "Inserindo chave "<<toBinary(num,B) << endl;
        diretorio1->inserirChave(num);
        diretorio1->imprimirDiretorio();
        outfile << "Fator de carga: "<<( diretorio1->getQtdRegistros()/float(diretorio1->getQtdBaldes()*M)*100)<< endl;

      //  diretorio1->imprimeDiretorioSaida(outfile);

    }
    outfile << "Quantidade de chaves: " << diretorio1->getQtdRegistros() << endl;
    outfile << "Quantidade de baldes: " << diretorio1->getQtdBaldes() << endl;

    cout << "Inserindo chaves com padrão de bits" << endl;


    for (int i = 0; i < N ; i++)
    {
        outfile << "Inserindo chave "<<toBinary(i,B) << endl;
        diretorio2->inserirChave(i);
        diretorio2->imprimirDiretorio();
        outfile << "Fator de carga: "<<diretorio2->getQtdRegistros()/float(diretorio2->getQtdBaldes()*M)*100 << "%" << endl;

       /// diretorio2->imprimeDiretorioSaida(outfile);

    }
    outfile << "Quantidade de chaves: " << diretorio2->getQtdRegistros() << endl;
    outfile << "Quantidade de baldes: " << diretorio2->getQtdBaldes() << endl;
//     outfile.close();
//         diretorio->inserirChave(0);
//     diretorio->imprimirDiretorio();

//     diretorio->inserirChave(5);
//     diretorio->imprimirDiretorio();

//   diretorio->inserirChave(14);
//     diretorio->imprimirDiretorio();

//     diretorio->inserirChave(15);
//     diretorio->imprimirDiretorio();

//   diretorio->inserirChave(3);
//    diretorio->imprimirDiretorio();


//  diretorio->inserirChave(7);
//      diretorio->imprimirDiretorio();

//        diretorio->inserirChave(2);
//       diretorio->imprimirDiretorio();
//      diretorio->inserirChave(6);
//       diretorio->imprimirDiretorio();
//         diretorio->inserirChave(4);
//       diretorio->imprimirDiretorio();

    //  cout <<"quantidade de chaves: "<< diretorio->getQtdRegistros() << endl;
//     diretorio->inserirChave(0);
//     diretorio->imprimirDiretorio();

//     diretorio->inserirChave(5);
//     diretorio->imprimirDiretorio();

//     diretorio->inserirChave(14);
//     diretorio->imprimirDiretorio();

//     diretorio->inserirChave(3);
//     diretorio->imprimirDiretorio();

//    diretorio->inserirChave(16);



   // delete [] diretorio;
    system("pause");

    return 0;
}