#include "rl.h"

vector<string> readFile(const char *nome)
{
    ifstream fp;
    fp.open(nome);
    vector<string> Main;
    string line;
    while(getline(fp,line))
        Main.push_back(line);

    fp.close();
    return Main;
}

void runLenghtToBin(string& s, fstream &fp)
{
    int atual=0, anterior=0;
    atual=s.find_first_not_of(s[anterior],anterior);

    while(atual!=-1) //realiza operacao de run-length
    {
        fp.put(atual - anterior);
        fp.put(s[anterior]);
        anterior = atual;
        atual=s.find_first_not_of(s[anterior],anterior);
    }
    string restante(s.substr(anterior));

    fp.put(restante.length());
    fp.put(s[anterior]);
    fp.put(1);
    fp.put(10);
}

void decodeRl(const char *input, const char *output)
{
    fstream fpIn, fpOut;
    fpIn.open(input);
    fpOut.open(output,ios::out);
    char pos, escrita;
    while(fpIn.get(pos))
    {
        int repeticoes = (int)pos;
        fpIn.get(escrita);
        for(int j=0; j<repeticoes; j++)
            fpOut.put(escrita);
    }
    fpIn.close();
    fpOut.close();
}

void encodeRl(const char *input, const char *output)
{
    vector<string> vet = readFile(input);
    string s;
    fstream fp(output,ios::out);
    for(unsigned int i=0; i<vet.size(); i++)
    {
        s=vet[i];
        runLenghtToBin(s, fp);
    }
    fp.close();
}
