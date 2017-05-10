#ifndef _BWT_H
#define _BWT_H

#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <fstream>

using namespace std;

int unsigned_memcmp( void *p1, void *p2, unsigned int i );
int bounded_compare( const unsigned int *i1,const unsigned int *i2 );
void encodeBwt(const char *input, const char *output, int block);
void decodeBWT(const char *input, const char *output, int block);

#endif
