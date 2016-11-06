#define _XOPEN_SOURCE 
#include <crypt.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __DEBUG__ 666

/* The macros of printing funtions. */
#ifdef __DEBUG__
#define printINT(x) printf("%s = %d\n", #x, (x));
#define printLNG(x) printf("%s = %ld\n", #x, (x));
#define printSTR(x) printf("%s = %s\n", #x, (x));
#else
#define printINT(x)
#define printLNG(x)
#define printSRT(x)
#endif
/* End macros */


int main()
{
    const char target[150] = "$6$naIJPKfO$SMkeSkFM36M6u3mZIyf2hAtt31WxuYtoTwLMjF9Fv49cprYPKtR1K88Ox5xvQdLdoBrAOmCnomRvaHc7VDiqQ0";
    const char salt[20] = "$6$naIJPKfO";
    char str[100][30];
    char password[100];
    FILE *fp;
    int n = 0;
    int i = 0, j = 0, k = 0;

    if( !(fp = fopen("john.txt", "rb")) ) {
        fprintf(stderr, "Cannot open the john.txt file.\n");
        exit(1);
    }

    /* Load all the data, john.txt, in memory. */
    while( fscanf(fp, "%s", str[n++]) != EOF );

    n = n - 1;

    /* Try to concatenate 3 strings, then crypt it to compare the target string. */
    for( i = 0 ; i < n ; i++) {
        for( j = 0 ; j < n ; j++ ) {
            for( k = 0 ; k < n ; k++) {
                strcat(password, str[i]);
                strcat(password, str[j]);
                strcat(password, str[k]);

                if( !strcmp( target, crypt(password, salt) ) ) {
                    printSTR(password);
                    exit(EXIT_SUCCESS); 
                }

                memset(password, 0, sizeof(password));
            }
        }
    }
                
    fclose(fp);
    return 0;
}
