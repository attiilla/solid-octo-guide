#include "Index.h"


Index::Index() : base_(map<string,vector<freq> >()){
}

void Index::Form(vector<string>& vc)
{
    for(unsigned long int i=0; i<vc.size(); i++)
    {
        for(unsigned int j=0; j<vc[i].size(); j++)
        {
            if(vc[i].begin()[j]=='+'||vc[i].begin()[j]=='-'||vc[i].begin()[j]=='.'||vc[i].begin()[j]==','||
               vc[i].begin()[j]=='?'||vc[i].begin()[j]=='!'||vc[i].begin()[j]=='@'||vc[i].begin()[j]=='\\'||
               vc[i].begin()[j]==':'||vc[i].begin()[j]==';'||vc[i].begin()[j]=='*'||vc[i].begin()[j]=='('||
               vc[i].begin()[j]==')'||vc[i].begin()[j]=='['||vc[i].begin()[j]==']'||vc[i].begin()[j]=='{'||
               vc[i].begin()[j]=='}'|| vc[i].begin()[j]=='\''|| vc[i].begin()[j]=='\"')
            {
                vc[i].erase(vc[i].begin()+j);
            }
        }
    }
}

Index::Index(string c): Index(){
    vector<string> vc = Conv(c);
    Form(vc);
    vector<vector<freq> > vvf;
    vector<freq> auxv;
    freq auxf;
    auxf.file = c;
    auxf.t = 1;
    auxv.push_back(auxf);
    //para cada i-ésima palavra
    for(unsigned int i=0;i<vc.size();i++){
            cout<<i<<":"<<vc[i]<<endl;
        if (base_.count(vc[i])==0){
            vvf.push_back(auxv);
            base_.insert(pair<string, vector<freq> >(vc[i],vvf[i]));
        } else {
            base_[vc[i]][0].t++;
        }
    }
}

/*auxf.file=c;
auxf.t=1
aux.push_back(auxf)
vvf.push_back(auxv)
*/





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

