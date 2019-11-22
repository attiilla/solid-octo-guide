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

//frequência, struct que aramazena o nome de um arquivo e o número de vezes que a palavra associada apareceu nesse arquivo
struct freq;

class Index{
public:
    //constrói um índice vazio
    Index();
    //constrói um índice com os valores do arquivo de nome citado
    Index(string c);
    //constrói um índice com todos os valores dos arquivos do vetor varq
    //converte o arquivo de nome c em um vetor de strings
    vector<string> Conv(string c);
    //formata um vetor de strings para retirar símbolo
    void Form(vector<string>& vc);
    //adiciona as informações do aquivo arq a um índice pre-existente
    void AddDataFromFile(ifstream arq);
    //adiciona as informações do aquivo arq a um índice pre-existente
    void AddDataFromFile(vector<ifstream> varq);
    //destrutor
    //~Index();
private:
    map<string,vector<freq> > base_;
    //adiciona uma variável do tipo frequência(freq) ao vetor de uma palavra que já existe no índice
    void addOldWord(freq f);
    //remove do mapa o nó com a chave s
    void removeKey(string s);
};
#endif
