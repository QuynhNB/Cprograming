#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256

int main(int argc, char **argv)
{
    int i, count = 0;
    char string[BUFFER_SIZE];
    char rev_string[BUFFER_SIZE];

    while(fgets(string, BUFFER_SIZE, stdin) > 0) {
        for(i = strlen(string) - 2; i >= 0; i--)
            rev_string[count++] = string[i];
        for(i = 0; i < count; i++)
            putchar(rev_string[i]);
        putchar('\n');
        memset(string, 0, BUFFER_SIZE);
        memset(rev_string, 0, BUFFER_SIZE);
        fflush(stdin);
   }

    return 0;
}
