#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cctype>

#define width_unit 5

//classe principal para huffman. Cria e destroi nodes, e faz operacoes com caracteres, baseado em tabela de frequencia
class Tree
{
    private:
        class Node
        {
            public:
                unsigned int freq;
                unsigned char ch;
                Node *left, *right;
                //construtor
                Node(void)
                    :freq(0), ch('\0'), left(NULL), right(NULL) {}
        };

        Node *root;

        Tree(const Tree &);
        const Tree & operator=(const Tree &);
        void destruir(Node * N);
        void print(ostream &, Node *, int) const;
        void print(Node *, int) const;

    public:
        Tree(void);
        ~Tree(void);
        friend ostream & operator<<(ostream &, const Tree &);

        //getters e setters
        unsigned int get_freq(void) const;
        unsigned char get_char(void) const;
        void set_freq(unsigned int);
        void set_char(unsigned char);
        Node* get_left(void) const;
        Node* get_right(void) const;
        void set_left(Node *);
        void set_right(Node *);
        Node* get_root(void) const;

        //overload nos operadores para funcionarem com arvores
        bool operator==(const Tree &) const;
        bool operator!=(const Tree &) const;
        bool operator<(const Tree &) const;
        bool operator>(const Tree &) const;
        bool operator<=(const Tree &) const;
        bool operator>=(const Tree &) const;

        //operacoes para criar e percorrer arvore huffman
        void huf(Node *, unsigned char, string, string &) const;
        void huf_list(Node *, string) const;
        bool get_huf_char(string, unsigned char &) const;
        string print_char(Node *) const;
};

//construtor
Tree::Tree(void)
{
    Node* N=new Node;
    root=N;
}

//deleta arvore
void Tree::destruir(Node *N)
{
    if(N)
    {
        destruir(N->left);
        destruir(N->right);
        delete N;
    }
}

//destrutor
Tree::~Tree(void)
{
    destruir(root);
}

unsigned int Tree::get_freq(void) const
{
    return root->freq;
}

unsigned char Tree::get_char(void) const
{
    return root->ch;
}

void Tree::set_freq(unsigned int f)
{
    root->freq=f;
}

void Tree::set_char(unsigned char c)
{
    root->ch=c;
}

Tree::Node* Tree::get_left(void) const
{
    return root->left;
}

Tree::Node* Tree::get_right(void) const
{
    return root->right;
}

void Tree::set_left(Node* N)
{
    root->left=N;
}

void Tree::set_right(Node* N)
{
    root->right=N;
}

Tree::Node* Tree::get_root(void) const
{
    return root;
}

//salva arvore em arquivo
void Tree::print(ostream & saida, Node * curr, int level) const
{
    if(curr)
    {
        print(saida,curr->right,level+1);
        saida<<setw(level*width_unit)<<print_char(curr)<<":"
           <<curr->freq<<endl;
        print(saida,curr->left,level+1);
    }
}

//imprime arvore no terminal
void Tree::print(Node * curr, int level) const
{
    if(curr)
    {
        print(curr->right,level+1);
        cout<<setw(level*width_unit)<<print_char(curr)<<":"
            <<curr->freq<<endl;
        print(curr->left,level+1);
    }
}

ostream & operator<<(ostream &saida, const Tree &t)
{
    t.print(saida, t.root, 1);
    return saida;
}

bool Tree::operator==(const Tree & T) const
{
    return (root->freq == T.root->freq);
}

bool Tree::operator!=(const Tree & T) const
{
    return (root->freq != T.root->freq);
}

bool Tree::operator<(const Tree & T) const
{
    return (root->freq < T.root->freq);
}

bool Tree::operator>(const Tree & T) const
{
    return (root->freq > T.root->freq);
}

bool Tree::operator<=(const Tree & T) const
{
    return (root->freq <= T.root->freq);
}

bool Tree::operator>=(const Tree & T) const
{
    return (root->freq >= T.root->freq);
}

//entrada: no raiz, o char, a string atual na arvore e uma string para salvar o codigo
void Tree::huf(Node* N, unsigned char c, string str, string & s) const
{
    if(N)
    {
        if(!N->left && !N->right && N->ch == c)
            s=str;
        else
        {
            huf(N->left, c, str+"0",s);
            huf(N->right, c, str+"1",s);
        }
    }
}

//input: no raiz, string referente ao no. apenas para impressao e debug
void Tree::huf_list(Node* N, string str) const
{
    if(N)
    {
        if(!N->left && !N->right)
            cout<<print_char(N)<<" "<<str<<endl;
        else
        {
            huf_list(N->left, str+"0");
            huf_list(N->right, str+"1");
        }
    }
}

//entradas: string para percorrer na arvore e um char para salvar o caracter encontrado
bool Tree::get_huf_char(string s, unsigned char & c) const
{
    Node * curr=root;
    for(unsigned int i=0;i<s.size();++i)
    {
        if(s[i]=='0')
            curr=curr->left;
        if(s[i]=='1')
            curr=curr->right;
    }

    bool found=false;

    if(!curr->left && !curr->right)
    {
        found=true;
        c=curr->ch;
    }

    return found;
}

string Tree::print_char(Node * N) const
{
    string s="";

    if(!N->left && !N->right)
    {
        unsigned char c=N->ch;
        if(iscntrl(c) || c==32)
        {
            char* cp=new char;
            for(int i=0;i<3;++i)
            {
                sprintf(cp,"%i",c%8);
                c-=c%8;
                c/=8;
                s=(*cp)+s;
            }
            s='/'+s;
        }
        else
            s=c;
    }
    return s;
}

//salva um bit no arquivo
void huf_write(unsigned char i, ofstream & outfile)
{
    static int bit_pos=0;
    static unsigned char c='\0';

    if(i<2) //caso EOF
    {
        if(i==1)
            c=c | (i<<(7-bit_pos));
        else
            c=c & static_cast<unsigned char>(255-(1<<(7-bit_pos)));
        ++bit_pos;
        bit_pos%=8;
        if(bit_pos==0)
        {
            outfile.put(c);
            c='\0';
        }
    }
    else
        outfile.put(c);
}

//le um bit de um arquivo
unsigned char huf_read(ifstream & infile)
{
    static int bit_pos=0;
    static unsigned char c=infile.get();

    unsigned char i;

    i=(c>>(7-bit_pos))%2; //pega um unico bit do arquivo
    ++bit_pos;
    bit_pos%=8;
    if(bit_pos==0)
    {
        if(!infile.eof())
        {
            c=infile.get();
        }
        else
            i=2;
    }
    return i;
}

void encodeHuff(string inFile, string outFile)
{
    ifstream infile(inFile.c_str(), ios::in|ios::binary);
    ofstream outfile(outFile.c_str(), ios::out|ios::binary);

    unsigned int frequency[256];
    for(int i=0;i<256;++i)
        frequency[i]=0;

    //cria tabela de frequencia
    char c;
    unsigned char ch;
    while(infile.get(c))
    {
        ch=c;
        ++frequency[ch];
    }

    infile.clear();
    infile.seekg(0);

    Queue<Tree> q(3);
    Tree* inicial;

    for(int i=0;i<256;++i)
    {
        //salva a tabela de frequencia para decodificacao, dividindo os 32bits em 4 bytes
        outfile.put(static_cast<unsigned char>(frequency[i]>>24));
        outfile.put(static_cast<unsigned char>((frequency[i]>>16)%256));
        outfile.put(static_cast<unsigned char>((frequency[i]>>8)%256));
        outfile.put(static_cast<unsigned char>(frequency[i]%256));

        if(frequency[i]>0)
        {
            inicial=new Tree;
            inicial->set_freq(frequency[i]);
            inicial->set_char(static_cast<unsigned char>(i));
            q.empilha(inicial);
        }
    }

    Tree* inicial2;
    Tree* inicial3;

    //junta os chars de menor frequencia ate esvazia a pilha
    do
    {
        inicial=q.desempilha();
        if(!q.empty())
        {
            inicial2=q.desempilha();
            inicial3=new Tree;
            inicial3->set_freq(inicial->get_freq()+inicial2->get_freq());
            inicial3->set_left(inicial->get_root());
            inicial3->set_right(inicial2->get_root());
            q.empilha(inicial3);
        }
    }
    while(!q.empty());

    //cria tabela de valores binario de cada char
    string H_table[256];
    unsigned char uc;
    for(unsigned short us=0;us<256;++us)
    {
        H_table[us]="";
        uc=static_cast<unsigned char>(us);
        inicial->huf(inicial->get_root(), uc, "", H_table[us]);
    }

    //salva no arquivo bit a bit
    unsigned char ch2;
    while(infile.get(c))
    {
        ch=c;
        for(unsigned int i=0;i<H_table[ch].size();++i)
        {
            if(H_table[ch].at(i)=='0')
                ch2=0;
            if(H_table[ch].at(i)=='1')
                ch2=1;
            huf_write(ch2, outfile);
        }
    }
    ch2=2;
    huf_write(ch2, outfile);

    infile.close();
    outfile.close();

}

void decodeHuff(string inFile, string outFile)
{
    ifstream infile(inFile.c_str(), ios::in|ios::binary);
    ofstream outfile(outFile.c_str(), ios::out|ios::binary);

    unsigned int frequency[256];
    char c;
    unsigned char ch;
    unsigned int j=1;
    for(int i=0;i<256;++i)
    {
        frequency[i]=0;
        for(int k=3;k>=0;--k)
        {
            infile.get(c);
            ch=c;
            frequency[i]+=ch*(j<<(8*k));
        }
    }

    Queue<Tree> q(3);
    Tree* inicial;

    for(int i=0;i<256;++i)
    {
        if(frequency[i]>0)
        {
            inicial=new Tree;
            inicial->set_freq(frequency[i]);
            inicial->set_char(static_cast<unsigned char>(i));
            q.empilha(inicial);
        }
    }

    Tree* inicial2;
    Tree* inicial3;

    do
    {
        inicial=q.desempilha();
        if(!q.empty())
        {
            inicial2=q.desempilha();
            inicial3=new Tree;
            inicial3->set_freq(inicial->get_freq()+inicial2->get_freq());
            inicial3->set_left(inicial->get_root());
            inicial3->set_right(inicial2->get_root());
            q.empilha(inicial3);
        }
    }
    while(!q.empty());

    string st;
    unsigned char ch2;
    unsigned int total_chars=inicial->get_freq();
    while(total_chars>0)
    {
        st="";
        do
        {
            ch=huf_read(infile);
            if(ch==0)
                st=st+'0';
            if(ch==1)
                st=st+'1';
        }while(!inicial->get_huf_char(st, ch2));

        outfile.put(static_cast<char>(ch2));
        --total_chars;
    }
    infile.close();
    outfile.close();
}

#endif // _HUFFMAN_H
