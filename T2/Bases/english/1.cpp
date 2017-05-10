#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <fstream>
#include <unistd.h>
#include <dirent.h>
#include <vector>
#include <locale>
#include <algorithm>

using namespace std;

class WithComma: public numpunct<char> // class for decimal numbers with comma
{
protected:
    char do_decimal_point() const
    {
        return ',';    // override the function that gives the decimal separator
    }
};

vector<string> files;
locale myloc(locale(),new WithComma);

fstream fp, fp2;
double leit;
string curr;

void createfilesBwt()
{
    files.push_back("50mbBwt100.out");
    files.push_back("100mbBwt100.out");
    files.push_back("200mbBwt100.out");
    files.push_back("50mbBwt500.out");
    files.push_back("100mbBwt500.out");
    files.push_back("200mbBwt500.out");
    files.push_back("50mbBwt1000.out");
    files.push_back("100mbBwt1000.out");
    files.push_back("200mbBwt1000.out");
    files.push_back("50mbBwt10000.out");
    files.push_back("100mbBwt10000.out");
    files.push_back("200mbBwt10000.out");
}
void createfilesBwtH()
{
    files.push_back("50mbBwtH100.out");
    files.push_back("100mbBwtH100.out");
    files.push_back("200mbBwtH100.out");
    files.push_back("50mbBwtH500.out");
    files.push_back("100mbBwtH500.out");
    files.push_back("200mbBwtH500.out");
    files.push_back("50mbBwtH1000.out");
    files.push_back("100mbBwtH1000.out");
    files.push_back("200mbBwtH1000.out");
    files.push_back("50mbBwtH10000.out");
    files.push_back("100mbBwtH10000.out");
    files.push_back("200mbBwtH10000.out");
}
void createfilesBwtHRl()
{
    files.push_back("50mbBwtHRl100.out");
    files.push_back("100mbBwtHRl100.out");
    files.push_back("200mbBwtHRl100.out");
    files.push_back("50mbBwtHRl500.out");
    files.push_back("100mbBwtHRl500.out");
    files.push_back("200mbBwtHRl500.out");
    files.push_back("50mbBwtHRl1000.out");
    files.push_back("100mbBwtHRl1000.out");
    files.push_back("200mbBwtHRl1000.out");
    files.push_back("50mbBwtHRl10000.out");
    files.push_back("100mbBwtHRl10000.out");
    files.push_back("200mbBwtHRl10000.out");
}
void createfilesBwtRl()
{
    files.push_back("50mbBwtRl100.out");
    files.push_back("100mbBwtRl100.out");
    files.push_back("200mbBwtRl100.out");
    files.push_back("50mbBwtRl500.out");
    files.push_back("100mbBwtRl500.out");
    files.push_back("200mbBwtRl500.out");
    files.push_back("50mbBwtRl1000.out");
    files.push_back("100mbBwtRl1000.out");
    files.push_back("200mbBwtRl1000.out");
    files.push_back("50mbBwtRl10000.out");
    files.push_back("100mbBwtRl10000.out");
    files.push_back("200mbBwtRl10000.out");
}
void createfilesH()
{
    files.push_back("english50mbH.out");
    files.push_back("english100mbH.out");
    files.push_back("english200mbH.out");
}
void createfilesHRl()
{
    files.push_back("50mbHRl.out");
    files.push_back("100mbHRl.out");
    files.push_back("200mbHRl.out");
}
void createfilesRl()
{
    files.push_back("english50mbRl.out");
    files.push_back("english100mbRl.out");
    files.push_back("english200mbRl.out");
}

void writeFile()
{
    for(unsigned int i=0; i<files.size(); i++)
    {
        fp.open(files[i].c_str());
        cout << "Lendo " << files[i] << endl;
        while(fp >> curr)
        {

            if(curr.compare("Duracao:")==0)
            {
                fp >> curr;
                leit = atof(curr.c_str());
                if(leit<0) leit=leit*(-1);
                fp2 << leit << " ";
            }

        }
        fp2 << endl;
        fp.close();
    }
    files.clear();
}
int main()
{

    fp2.open("counts.txt",ios::out);
    fp2.imbue(myloc);

//    createfilesBwt();
//    writeFile();
//    createfilesBwtH();
//    writeFile();
//    createfilesBwtHRl();
//    writeFile();
//    createfilesBwtRl();
//    writeFile();
    createfilesHRl();
    writeFile();
    createfilesH();
    writeFile();
    createfilesRl();
    writeFile();
}
