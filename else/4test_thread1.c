#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

char str[100][30];

void Test( const char *str, int i )
{
     for( int i = 0 ; i < 10000 ; i++ );
     
     printf( "%d %s\n", i, str );
}

int main(int argc, char* argv[])
{

    FILE *fp1;
    int n = 0;

    if( !(fp1 = fopen("john.txt", "rb")) ) {
        fprintf(stderr, "Cannot open the john.txt file.\n");
        exit(EXIT_FAILURE);
    }

    while( fscanf(fp1, "%s", str[n++]) != EOF );
    fclose(fp1);
    n = n -1;

    #pragma omp parallel for
    for( int i = 0 ; i < n ; i++ )
        Test(str[i], i);

    return 0;
}
