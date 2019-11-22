#include <iostream>
#include <fstream>
#include <istream>
#include <iterator>
#include <algorithm>
#include "Index.h"
int main()
{
    unsigned int i;
    vector<string> c;
    vector<string> d;
    string sup;
    cout<< "Coloque todos os arquivos que voce deseja ler no diretório Resources dentro do projeto"<<endl;
    cout << "Quais os nomes dos arquivos (seguidos da extensão) que voce deseja usar para construir o banco de dados?" << endl;
    cout<<"Ex1: Notas.txt"<<endl;
    cout<<"Ex2:FilaComListaEncadeada.txt"<<endl;
    cout << "Envie F para terminar."<<endl;
    while(sup!="F"&&sup!="f")
    {
        cin>>sup;
        c.push_back(sup);
    }
    c.pop_back();
    ifstream arq;
    arq.open("Resources\\"+c[0]);
    if(arq.fail()){
        cerr<<"Falha ao abrir o arquivo "<<c[0]<<endl;
    }
    copy(istream_iterator<string>(arq), istream_iterator<string>(), back_inserter(d));

    //form

     for(i=0;i<d.size();i++){
        transform(d[i].begin(), d[i].end(), d[i].begin(), ::tolower);
        cout<<d[i]<<endl;
    }




    return 0;
}
