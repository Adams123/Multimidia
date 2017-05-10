#include "bwt.h"
int memcmp_signed;
long length;
unsigned char *buffer;

int unsigned_memcmp( void *p1, void *p2, unsigned int i )
{
    unsigned char *pc1 = (unsigned char *) p1;
    unsigned char *pc2 = (unsigned char *) p2;
    while ( i-- )
    {
        if ( *pc1 < *pc2 )
            return -1;
        else if ( *pc1++ > *pc2++ )
            return 1;
    }
    return 0;
}

int bounded_compare( const unsigned int *i1,const unsigned int *i2 )
{
    unsigned int l1 = (unsigned int) ( length - *i1 );
    unsigned int l2 = (unsigned int) ( length - *i2 );
    int result;
    if ( memcmp_signed )
        result = unsigned_memcmp( buffer + *i1,
                                  buffer + *i2,
                                  l1 < l2 ? l1 : l2 );
    else
        result = memcmp( buffer + *i1,
                         buffer + *i2,
                         l1 < l2 ? l1 : l2 );
    if ( result == 0 )
        return l2 - l1;
    else
        return result;
};
void encodeBwt(const char *input, const char *output, int block)
{
    buffer = (unsigned char *)malloc(sizeof(unsigned char) *block);
    int indices[block+1];


    freopen( input, "rb", stdin );
    freopen( output, "wb", stdout );
    for ( ; ; )
    {
        length = fread( (char *) buffer, 1, block, stdin );
        if ( length == 0 )
            break;
        long l = length + 1;
        fwrite( (char *) &l, 1, sizeof( long ), stdout );
        int i;
        for ( i = 0 ; i <= length ; i++ )
            indices[ i ] = i;
        qsort( indices,(int)( length + 1 ),sizeof( int ),( int (*)(const void *, const void *) ) bounded_compare );
        long first;
        long last;
        for ( i = 0 ; i <= length ; i++ )
        {
            if ( indices[ i ] == 1 )
                first = i;
            if ( indices[ i ] == 0 )
            {
                last = i;
                fputc( '?', stdout );
            }
            else
                fputc( buffer[ indices[ i ] - 1 ], stdout );
        }
        fwrite( (char *) &first, 1, sizeof( long ), stdout );
        fwrite( (char *) &last, 1, sizeof( long ), stdout );
    }
    free(buffer);
}

void decodeBWT(const char *input, const char *output, int block)
{
    fprintf(stderr,"decoding");
    unsigned char buffer[ block + 1 ];
    unsigned int T[ block + 1 ];
    long buflen;
    unsigned int Count[ 257 ];
    unsigned int RunningTotal[ 257 ];

    freopen( input, "rb", stdin );
    freopen( output, "wb", stdout );

    for ( ; ; )
    {
        if ( fread( (char *) &buflen, sizeof( long ), 1, stdin ) == 0 )
            break;
        if ( buflen > ( block + 1 ) )
        {
            fprintf( stderr, "Buffer overflow!\n" );
            abort();
        }
        if ( fread( (char *)buffer, 1, (size_t) buflen, stdin ) !=
                (size_t) buflen )
        {
            fprintf( stderr, "Error reading data\n" );
            abort();
        }
        unsigned long first;
        fread( (char *) &first, sizeof( long ), 1, stdin );
        unsigned long last;
        fread( (char *)&last, sizeof( long ), 1, stdin );
        unsigned int i;
        for ( i = 0 ; i < 257 ; i++ )
            Count[ i ] = 0;
        for ( i = 0 ; i < (unsigned int) buflen ; i++ )
            if ( i == last )
                Count[ 256 ]++;
            else
                Count[ buffer[ i ] ]++;
        int sum = 0;
        for ( i = 0 ; i < 257 ; i++ )
        {
            RunningTotal[ i ] = sum;
            sum += Count[ i ];
            Count[ i ] = 0;
        }
        for ( i = 0 ; i < (unsigned int) buflen ; i++ )
        {
            int index;
            if ( i == last )
                index = 256;
            else
                index = buffer[ i ];
            T[ Count[ index ] + RunningTotal[ index ] ] = i;
            Count[ index ]++;
        }
        unsigned int j;
        i = (unsigned int) first;
        for ( j = 0 ; j < (unsigned int) ( buflen - 1 ) ; j++ )
        {
            putc( buffer[ i ], stdout );
            i = T[ i ];
        }
    }
}

int main(int argc, char *argv[])
{
    //encodeBwt(argv[1],argv[2],10000);
    decodeBWT(argv[1],argv[2],10000);
}