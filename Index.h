#ifndef INDEX
#define INDEX
#include <iostream>
#include <fstream>
#include <istream>
#include <iterator>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;



class Index{
public:
    //rodar
    void run();

    //converte o arquivo de nome c em um vetor de strings
    vector<string> Conv(string c);

    //formata um vetor de strings para retirar s�mbolos e tornar as letras min�sculas
    void Form(vector<string>& vc);

    ////formata uma string para tornar suas letras min�sculas
    void Form(string c);

    //adiciona as informa��es do aquivo arq de nome c ao mapa, j � a ordem em que ele � lido(0 para o primeiro, 1 para o segundo, etc)
    void AddFile(string c, int j);

    //adiciona todas as palavras de vc ao mapa, j associa essas informa��es ao elmento v[j] do vector do mapa
    void AddFile(vector<string> vc, int j);

    //exibe todos os elementos do vector que relacionado a chave c do mapa(base_[c])
    void Print(string c);

    //retorna t_
    int filenum() const;

    //calcula import�ncia de c
    double idf(string c);

    //calcula a semelhan�a entre a querry e o arquivo de numero i
    double sim(vector<string> q, int i);


private:
    map<string, int[50]> base_;
    int t_;
    vector<string> keys_;
    void SetSize(int i);
    friend class Teste;
};
#endif
