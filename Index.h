#ifndef INDEX
#define INDEX
#include <iostream>
#include <fstream>
#include <istream>
#include <iterator>
#include <string>
#include <map>
#include <vector>
using namespace std;

//frequ�ncia, struct que aramazena o nome de um arquivo e o n�mero de vezes que a palavra associada apareceu nesse arquivo
struct freq;

class Index{
public:
    //constr�i um �ndice vazio
    Index();
    //constr�i um �ndice com os valores do arquivo de nome citado
    Index(string c);
    //constr�i um �ndice com todos os valores dos arquivos do vetor varq
    //converte o arquivo de nome c em um vetor de strings
    vector<string> Conv(string c);
    //formata um vetor de strings para retirar s�mbolo
    void Form(vector<string>& vc);
    //adiciona as informa��es do aquivo arq a um �ndice pre-existente
    void AddDataFromFile(ifstream arq);
    //adiciona as informa��es do aquivo arq a um �ndice pre-existente
    void AddDataFromFile(vector<ifstream> varq);
    //destrutor
    //~Index();
private:
    map<string,vector<freq> > base_;
    //adiciona uma vari�vel do tipo frequ�ncia(freq) ao vetor de uma palavra que j� existe no �ndice
    void addOldWord(freq f);
    //remove do mapa o n� com a chave s
    void removeKey(string s);
};
#endif
