#include "bwt.h"
#include "rl.h"
#include "queue.h"
#include "huffman.h"
#include <ctime>
#include <istream>


int main(int argc, char *argv[])
{
    //bwt
    int blocksize;
    string input, output, op("encode"), bwttrue("--bwt=true"),bwtfalse("--bwt=false"), huffmantrue("--huffman=true"),huffmanfalse("--huffman=false"),runlfalse("--runl=false"),runltrue("--runl=true");
    bool bwt=false,huffman=false,runl=false, enc=false;
    if(op.compare(argv[1])==0) enc=true;
    input = argv[3];
    output = argv[5];
    clock_t inicio, fim, start, terminate;
    for(int i=1; i<argc; i++)
    {
        if(bwttrue.compare(argv[i])==0)
        {
            bwt=true;
            string txt = argv[i+1];
            if(txt.find("--txtblck=")!=string::npos)
            {
                txt=txt.substr(10);
                blocksize=atoi(txt.c_str());
            }
        }
        if(huffmantrue.compare(argv[i])==0)
            huffman=true;
        if(runltrue.compare(argv[i])==0)
            runl=true;
    }
    if(enc)
    {
        start = clock();
        if(bwt && runl && huffman)
        {
            inicio = clock();
            cout << "Rodando BWT!" << endl;
            encodeBWT(input.c_str(),"bwtToRl",blocksize);
            fim = clock();
            cout << "Fim Bwt. Duracao: " << float(fim - inicio)/ CLOCKS_PER_SEC << endl << "Rodando Rl." << endl;
            encodeRl("bwtToRl","rlToHuff");
            inicio = clock();
            cout << "Fim Rl. Duracao: " << float(inicio - fim)/ CLOCKS_PER_SEC << endl << "Rodando Huffman." << endl;
            encodeHuff("rlToHuff",output.c_str());
            fim = clock();
            cout << "Fim Huff. Duracao: " << float(fim - inicio)/ CLOCKS_PER_SEC << endl;
            remove("bwtToRl");
            remove("rlToHuff");
            cout << "Fim codificacao!" << endl;
            terminate=clock();
            cout <<"Duracao total: " << float(terminate-start)/ CLOCKS_PER_SEC << endl;
            return 1;
        }
        else if(bwt)
        {
            if(runl) //bwt + runlength
            {
                inicio = clock();
                cout << "Rodando BWT!" << endl;
                encodeBWT(input.c_str(),"bwtToRl",blocksize);
                fim = clock();
                cout << "Fim Bwt. Duracao: " << float(fim - inicio)/ CLOCKS_PER_SEC << endl << "Rodando Rl." << endl;
                encodeRl("bwtToRl",output.c_str());
                inicio = clock();
                cout << "Fim Rl. Duracao: " << float(inicio - fim)/ CLOCKS_PER_SEC << endl;
                remove("bwtToRl");
                cout << "Fim codificacao!" << endl;
                terminate=clock();
                cout <<"Duracao total: " << float(terminate-start)/ CLOCKS_PER_SEC << endl;
                return 1;
            }
            else if(huffman) //bwt + huffman
            {
                inicio = clock();
                cout << "Rodando BWT!" << endl;
                encodeBWT(input.c_str(),"bwtToHuff",blocksize);
                fim = clock();
                cout << "Fim Bwt. Duracao: " << float(fim - inicio)/ CLOCKS_PER_SEC << endl << "Rodando Huffman." << endl;
                encodeHuff("bwtToHuff",output.c_str());
                fim = clock();
                cout << "Fim Huff. Duracao: " << float(inicio - fim)/ CLOCKS_PER_SEC << endl;
                remove("bwtToHuff");
                cout << "Fim codificacao!" << endl;
                terminate=clock();
                cout <<"Duracao total: " << float(terminate-start)/ CLOCKS_PER_SEC << endl;
                return 1;
            }
            inicio = clock();
            cout << "Rodando BWT!" << endl;
            encodeBWT(input.c_str(),output.c_str(),blocksize);
            fim = clock();
            cout << "Fim Bwt. Duracao: " << float(fim - inicio)/ CLOCKS_PER_SEC << endl;
            cout << "Fim codificacao!" << endl;
            terminate=clock();
            cout <<"Duracao total: " << float(terminate-start)/ CLOCKS_PER_SEC << endl;
            return 1;
        }
        else if(runl)
        {
            if(huffman) //runl + huffman
            {
                inicio = clock();
                cout << "Rodando RL!" << endl;
                encodeRl(input.c_str(),"rlToHuff");
                fim = clock();
                cout << "Fim Rl. Duracao: " << float(fim - inicio)/ CLOCKS_PER_SEC << endl << "Rodando Huffman." << endl;
                encodeHuff("rlToHuff",output.c_str());
                inicio = clock();
                cout << "Fim Huff. Duracao: " << float(inicio - fim)/ CLOCKS_PER_SEC << endl;
                remove("rlToHuff");
                cout << "Fim codificacao!" << endl;
                terminate=clock();
                cout <<"Duracao total: " << float(terminate-start)/ CLOCKS_PER_SEC << endl;
                return 1;
            }
            //apenas runl
            inicio = clock();
            cout << "Rodando RL!" << endl;
            encodeRl(input.c_str(),output.c_str());
            cout << "Fim Rl. Duracao: " << float(fim - inicio)/ CLOCKS_PER_SEC << endl;
        }
        else //apenas huffman
        {
            inicio = clock();
            cout << "Rodando Huff!" << endl;
            encodeHuff(input.c_str(),output.c_str());
            cout << "Fim Huff. Duracao: " << float(fim - inicio)/ CLOCKS_PER_SEC << endl;
        }
        terminate=clock();
        cout <<"Duracao total: " << float(terminate-start)/ CLOCKS_PER_SEC << endl;
        cout << "Fim codificacao!" << endl;
    }
    if(!enc)
    {
        start = clock();
        if(bwt && runl && huffman)
        {
            inicio = clock();
            cout << "Rodando Huff!" << endl;
            decodeHuff(input.c_str(),"huffToRl");
            fim = clock();
            cout << "Fim Huff. Duracao: " << double(fim - inicio) << endl << "Rodando Rl." << endl;
            decodeRl("huffToRl","rlToBwt");
            inicio = clock();
            cout << "Fim Rl. Duracao: " << double(inicio - fim) << endl << "Rodando Bwt." << endl;
            decodeBWT("rlToBwt",output.c_str(),blocksize);
            fim = clock();
            cout << "Fim Bwt. Duracao: " << double(fim - inicio) << endl;
            remove("rlToBwt");
            remove("huffToRl");
            cout << "Fim decodificacao!" << endl;
            terminate=clock();
            cout <<"Duracao total: " << double(terminate-start) << endl;
            return 1;
        }
        else if(bwt)
        {
            if(runl)//runl + bwt
            {
                inicio = clock();
                cout << "Rodando Rl!" << endl;

                decodeRl(input.c_str(),"rlToBwt");
                fim = clock();
                cout << "Fim Rl. Duracao: " << double(fim - inicio) << endl << "Rodando Bwt." << endl;

                decodeBWT("rlToBwt",output.c_str(),blocksize);
                inicio = clock();
                cout << "Fim Bwt. Duracao: " << double(inicio - fim) << endl;

                remove("rlToBwt");
                cout << "Fim decodificacao!" << endl;
                terminate=clock();
                cout <<"Duracao total: " << double(terminate-start) << endl;

                return 1;
            }
            else if(huffman) //huffman + bwt
            {
                inicio = clock();
                cout << "Rodando Huff!" << endl;
                decodeHuff(input.c_str(),"huffToBwt");
                fim = clock();
                cout << "Fim Huff. Duracao: " << double(fim - inicio) << endl << "Rodando Bwt." << endl;
                decodeBWT("huffToBwt",output.c_str(),blocksize);
                inicio = clock();
                cout << "Fim Bwt. Duracao: " << double(inicio - fim) << endl;

                remove("huffToBwt");
                cout << "Fim decodificacao!" << endl;
                terminate=clock();
                cout <<"Duracao total: " << double(terminate-start) << endl;

                return 1;
            }
            //apenas BWT
            inicio = clock();
            cout << "Rodando BWT!" << endl;

            decodeBWT(input.c_str(),output.c_str(),blocksize);
            fim = clock();
            cout << "Fim BWT. Duracao: " << double(fim - inicio) << endl;
            cout << "Fim decodificacao!" << endl;
            terminate=clock();
            cout <<"Duracao total: " << double(terminate-start) << endl;

            return 1;
        }
        else if(runl)
        {
            if(huffman) //runl + huffman
            {
                inicio = clock();
                cout << "Rodando Huff!" << endl;
                decodeHuff(input.c_str(),"rlToHuff");
                fim = clock();
                cout << "Fim Huff. Duracao: " << double(fim - inicio) << endl << "Rodando Rl." << endl;
                decodeRl("rlToHuff",output.c_str());
                inicio = clock();
                cout << "Fim Rl. Duracao: " << double(inicio - fim) << endl;
                remove("rlToHuff");
                cout << "Fim decodificacao!" << endl;
                terminate=clock();
                cout <<"Duracao total: " << double(terminate-start) << endl;

                return 1;
            }
            //apenas runl
            inicio = clock();
            cout << "Rodando RL!" << endl;
            decodeRl(input.c_str(),output.c_str());
            fim = clock();
            cout << "Fim Huff. Duracao: " << double(fim - inicio) << endl;

        }
        else //apenas huffman
        {
            inicio = clock();
            cout << "Rodando Huff!" << endl;
            decodeHuff(input.c_str(),output.c_str());
            fim = clock();
            cout << "Fim Huff. Duracao: " << double(fim - inicio) << endl;

        }
        cout << "Fim decodificacao!" << endl;
        terminate=clock();
        cout <<"Duracao total: " << double(terminate-start) << endl;

    }
    return 0;
}
