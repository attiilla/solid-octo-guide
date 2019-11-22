#include "Index.h"

struct freq{
    string file;
    int t;
    freq(){
        file = "";
        t = 0;
    }
    freq(string s, int n){
        file = s;
        t = n;
    }
};


Index::Index() : base_(map<string,vector<freq> >()){
}

Index::Index(string c): Index(){
    vector<string> vc = Conv(c);
    Form(vc);
    vector<freq> vf;
    for(unsigned long int i=0;i<vc.size();i++){
        if (base_.count(vc[i])==0){
            vf[0].file = c;
            vf[0].t=1;
            //mymap.insert ( std::pair<char,int>('a',100) )
            base_.insert(pair<string,vector<freq> >(vc[i],vf));
        } else {
            base_[vc[i]].t=
        }
    }
}

vector<string> Index::Conv(string c){
    ifstream arq;
    vector<string> vc;
    arq.open("Resources\\"+c);
    if(arq.fail()){
        cerr<<"Falha ao abrir o arquivo "<<c<<endl;
    }
    copy(istream_iterator<string>(arq), istream_iterator<string>(), back_inserter(vc));
    return vc;
}

void Form(vector<string>& vc)
{
    for(unsigned long int i=0; i<vc.size(); i++)
    {
        for(int j=0; j<vc[i].size(); j++)
        {
            if(vc[i].begin()[j]=='+'||'-'||'.'||','||'?'||'!'||'@')
            {
                vc[i].erase(vc[i].begin()+j);
            }
        }
    }
}
