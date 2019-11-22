#include <iostream>
#include <fstream>
#include <istream>
#include <iterator>
#include <algorithm>
#include "Index.h"
int main()
{
    vector<string> c;
    vector<string> d;
    string sup;
    /*cout<< "Coloque todos os arquivos que voce deseja ler no diretório Resources dentro do projeto"<<endl;
    cout << "Quais os nomes dos arquivos (seguidos da extensão) que voce deseja usar para construir o banco de dados?" << endl;
    cout<<"Ex1: Notas.txt"<<endl;
    cout<<"Ex2:FilaComListaEncadeada.txt"<<endl;
    cout << "Envie F para terminar."<<endl;
    while(sup!="F"&&sup!="f")
    {
        cin>>sup;
        c.push_back(sup);
    }
    c.pop_back();*/
    c.push_back("shake.txt");
    cout<<"o god why"<<endl;
    Index in(c[0]);
    /*struct freq f;
    f.file="ubba.txt";
    f.t=1;
    struct freq f2;
    f2 = f;
    f2.t++;*/
    if(in.base_["ubba"][0].t!=1||in.base_["ubba"][0].file!="ubba.txt"){
        cout<<"erro 1\n";
    }else{
        cout<<"1 OK\n";
    }
    if(in.base_["lubba"][0].t!=1||in.base_["lubba"][0].file!="ubba.txt"){
        cout<<"erro 1\n";
    }else{
        cout<<"2 OK\n";
    }
    if(in.base_["dub"][0].t!=2||in.base_["ubba"][0].file!="ubba.txt"){
        cout<<"erro 3\n";
    }else{
        cout<<"3 OK\n";
    }
    return 0;
}
