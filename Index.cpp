#include "Index.h"



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
        transform(vc[i].begin(), vc[i].end(), vc[i].begin(),[](unsigned char c){ return tolower(c); });
    }
}

void Index::Form(string vc)
{

        transform(vc.begin(), vc.end(), vc.begin(),[](unsigned char c){ return tolower(c); });
}

vector<string> Index::Conv(string c){
    ifstream arq;
    vector<string> *vcp = new vector<string>;
    vector<string> vc = *vcp;
    arq.open("Resources\\"+c);
    if(arq.fail()){
        cerr<<"Falha ao abrir o arquivo "<<c<<endl;
    }
    copy(istream_iterator<string>(arq), istream_iterator<string>(), back_inserter(vc));
    return vc;
}
void Index::SetSize(int i){
    t_ = i;
}

void Index::AddFile(string c, int j){
    vector<string> vc = Conv(c);
    Form(vc);

    for(int i=0;i<vc.size();i++){
            //se a palavra n esta na base, cria um indice com a palavra e copia o vetor de zeros para o indice, e então seta a posição j(ordem do arquivo) para 1
        if(base_.count(vc[i])==0){
                for(int k=0;k<t_;k++){
                    if(k!=j){
                        base_[vc[i]][k] = 0;
                    } else {
                        base_[vc[i]][k] = 1;
                    }
                }
                keys_.push_back(vc[i]);
        } else {
            base_[vc[i]][j]++;
        }
    }
}

void Index::AddFile(vector<string> vc, int j){
    Form(vc);
    for(int i=0;i<vc.size();i++){
            //se a palavra n esta na base, cria um indice com a palavra e copia o vetor de zeros para o indice, e então seta a posição j(ordem do arquivo) para 1
        if(base_.count(vc[i])==0){
                for(int k=0;k<t_;k++){
                    if(k!=j){
                        base_[vc[i]][k] = 0;
                    } else {
                        base_[vc[i]][k] = 1;
                    }
                }
                //keys_.push_back(vc[i]);
        } else {
            base_[vc[i]][j]++;
        }
    }
}

int Index::filenum() const{
return t_;
}

void Index::Print(string c){
    Form(c);
    for(int i=0;i<=t_;i++){
        cout<<this->base_[c][i]<<" ";
    }
    cout<<endl;
}


double Index::idf(string c){
    int nx=0;
    for(int j=0;j<t_;j++){
        if(base_[c][j]!=0){
            nx++;
        }
    }
    if(nx==0){
        return 0;
    }
    double q = (double) nx;
    double d = (double) t_;
    return (log(d/q));
}


double Index::sim(vector<string> q, int k){
    double aux1, aux2, sum=0, qc1 = 0, qc2 =0;
    this->AddFile(q,t_);
    for(int j=0;j<keys_.size();j++){
        aux1=base_[keys_[j]][k]*idf(keys_[j]);
        cout<<"aux1 em "<<j<<"="<<aux1<<endl;
        //ponto de interesse
        aux2=base_[keys_[j]][t_]*idf(keys_[j]);
        aux2=aux2/2;
        //ponto de interesse
        cout<<"aux2 em "<<j<<"="<<aux2<<endl;
        sum = sum+aux1*aux2;
        qc1 = qc1 + aux1*aux1;
        qc2 = qc2 + aux2*aux2;
    }
    return(sum/(sqrt(qc1)*sqrt(qc2)));
}

void Index::run(){
    int i;
    vector<string>* cp = new vector<string>;
    vector<string> c = *cp;
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
    SetSize(c.size());
    for(i = 0;i<filenum();i++){
        AddFile(c[i], i);
    }
    vector<string> querry;
    querry.push_back("a");
    querry.push_back("b");
    this->AddFile(querry,t_);
    Print("a");
    cout<<"similaridade entre querry e arquivo 1 e: "<<sim(querry,0)<<endl;

    cout<<"Qual sua querry?(aperte enter apos cada palavra e tecle . para terminar)"<<endl;
    while(sup!=".")
    {
        cin>>sup;
        querry.push_back(sup);
    }
    double s[c.size()];
    int max=1;
    for(i=0;i<c.size();i++){
        s[i] = sim(querry,i);
        if(i>0){
            if(s[i]>s[max]){
                max = i;
            }
        }
    }
    cout<<"O arquivo que mais se assemelha a querry e: "<<c[max]<<endl;
}
