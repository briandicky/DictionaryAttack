#define _XOPEN_SOURCE 
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
    char str[100][30];
    char target[150];
    char salt[20];
    char password[100];
    FILE *fp1, *fp2;
    int n = 0;
    int i = 0, j = 0, k = 0;

    if( !(fp1 = fopen("john.txt", "rb")) ) {
        fprintf(stderr, "Cannot open the john.txt file.\n");
        exit(EXIT_FAILURE);
    }

    /* Load all the data, john.txt, in memory. */
    while( fscanf(fp1, "%s", str[n++]) != EOF );
    fclose(fp1);
                                                         
    /* n is the number of strings from john.txt file. */
    n = n - 1;

    if( !(fp2 = fopen("sample_testcase.txt", "rb")) ) {
        fprintf(stderr, "Cannot open the sample_testcase.txt file.\n");
        exit(EXIT_FAILURE);
    }
    
    /* try to strtok and concatenate the salt string and the target string. */
    char tmp[150];
    char *tok1, *tok2, *tok3;
    if( fscanf(fp2, "%s", tmp) == EOF ) {
        fprintf(stderr, "Cannot read the sample_testcase.txt file.\n");
        exit(EXIT_FAILURE);
    }
    fclose(fp2);

    tok1 = strtok(tmp, "$");
    tok1 = strtok(NULL, "$");
    tok2 = strtok(NULL, "$");
    tok3 = strtok(NULL, ":");

    strcpy(salt, "$");
    strcat(salt, tok1);
    strcat(salt, "$");
    strcat(salt, tok2);
    
    strcpy(target, salt);
    strcat(target, "$");
    strcat(target, tok3);
    /* End of strtok */


    /* Try to concatenate 3 strings, then crypt it to compare the target string. */
    for( i = 0 ; i < n ; i++) {
        for( j = 0 ; j < n ; j++ ) {
            for( k = 0 ; k < n ; k++) {
                strcat(password, str[i]);
                strcat(password, str[j]);
                strcat(password, str[k]);

                if( !strcmp( target, crypt(password, salt) ) ) {
                    printf("password = %s\n", password);
                    exit(EXIT_SUCCESS); 
                }

                /* Flush the password buffer. */
                memset(password, 0, sizeof(password));
            }
        }
    }
                
    return 0;
}
