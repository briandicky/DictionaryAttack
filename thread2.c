#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void Test( int n )
{
    printf( "<T:%d> - %d\n", omp_get_thread_num(), n );
}

int main(int argc, char* argv[])
{
    #pragma omp parallel
    {
        Test( 0 );
    }

    return 0;
}
