#ifndef _RunLength_h
#define _RunLength_h

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

/*! Le um arquivo retornando um vetor de strings
    \param Nome do arquivo
    \return Um vector de string, onde cada tupla eh uma linha do arquivo.
*/
vector<string> readFile(const char *nome);

/*! Realiza a compressao de uma string pelo algoritmo Run-Length. Salva no formato Quantidade Char
    \param String a ser comprimida
    \param Arquivo onde sera salvo a string.
*/
void runLenghtToBin(string&, fstream &);

/*! Comprime um arquivo utilizando o RunLength
    \param Nome do arquivo
    \file Arquivo comprimido
*/
void encodeRl(const char *, const char*);

/*! Decodifica um arquivo no formato do RunLength
    \param Nome do arquivo
    \file Arquivo descomprimido
*/
void decodeRl(const char *,const char *);

#endif // _RunLength_h

