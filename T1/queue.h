#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cctype>

using namespace std;

// Template de uma fila de prioridade d-heap, como no link https://en.wikipedia.org/wiki/D-ary_heap
template<class T>
class Queue
{
    public:

        Queue(int d=2);
        ~Queue(void);
        void empilha(T*);
        T* desempilha(void);
        T* top(void);
        bool empty(void) const;
        bool full(void) const;

    private:

        int final;
        T* *nodes;
        int size; //capacidade
        static const int SIZE=10; //variacao do crescimento
        int D;
        Queue(const Queue &);
        const Queue & operator=(const Queue &);

        //funcoes para reordenar a heap
        void rearranjaRaizCima(int, int);
        void rearranjaRaizBaixo(int, int);
        void swap(T* &, T* &);

};

//construtor
template<class T>
Queue<T>::Queue(int d)
{
    if(d<2) d=2;
    D=d;
    final=0;
    size=SIZE;
    nodes=new T*[size];
}

template<class T>
bool Queue<T>::empty(void) const
{
    return (final<=0);
}

template<class T>
bool Queue<T>::full(void) const
{
    return (final>=size);
}


//remove da pilha
template<class T>
T* Queue<T>::desempilha(void)
{
    T* rval=nodes[0];
    nodes[0]=nodes[final-1]; //move final para frente
    --final;
    rearranjaRaizBaixo(0, final-1); //reordena heap
    return rval;
}

//retorna topo
template<class T>
T* Queue<T>::top(void)
{
    return nodes[0];
}

//empilha elemento
template<class T>
void Queue<T>::empilha(T* qlq)
{
    if(full())
    {
        int nsize=size+SIZE;
        T* *nnodes=new T*[nsize];
        for(int i=0;i<size;++i)
            nnodes[i]=nodes[i];
        delete[] nodes;
        nodes=nnodes;
        size=nsize;
    }

    nodes[final++]=qlq;
    rearranjaRaizCima(0, final-1);
}

//rearranja uma fila para cima, quando adicionado algo apos a root
template<class T>
void Queue<T>::rearranjaRaizCima(int root, int bottom)
{
    int parent;

    if(bottom > root)
    {
        parent=(bottom-1)/D;
        if(*nodes[parent] > *nodes[bottom])
        {
            swap(nodes[parent], nodes[bottom]);
            rearranjaRaizCima(root, parent);
        }
    }
}

//nodesuma a fila para baixo, quando adicionado uma root nova
template<class T>
void Queue<T>::rearranjaRaizBaixo(int root, int bottom)
{
    int minchild, firstchild, child;

    firstchild=root*D+1;
    if(firstchild <= bottom)
    {
        minchild=firstchild;
        for(int i=2;i <= D;++i)
        {
            child=root*D+i;
            if(child <= bottom)
                if(*nodes[child] < *nodes[minchild])
                    minchild=child;
        }

        if(*nodes[root] > *nodes[minchild])
        {
            swap(nodes[root], nodes[minchild]);
            rearranjaRaizBaixo(minchild, bottom);
        }
    }
}

//realiza swap de duas variaveis
template<class T>
void Queue<T>::swap(T* &a, T* &b)
{
    T* c;
    c=a;
    a=b;
    b=c;
}

//destrutor
template<class T>
Queue<T>::~Queue(void)
{
    delete[] nodes;
}
#endif // _QUEUE_H

