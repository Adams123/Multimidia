#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

void decodeBWT(const char *input, const char *output, int block)
{
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
