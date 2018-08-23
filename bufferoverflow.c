#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPassword() {
    char password[16];
    int isValid = 0; /*compiler assigns memory to isValid next to password*/
    printf("Admin Login\n");
    printf("Enter your password: ");
    memset(password, 0, 16);
    scanf("%s", password); /*this statement will overwrite value to isValid when user enter more than 16 characters*/
    //scanf("%16s", password);
    fflush(stdin);
    if(strncmp(password, "password", 8) == 0){
        printf("password is %s\n", password);
        isValid = 1;
    }
    return isValid; /*return true when buffer over flow happens*/

int main() {
    if(checkPassword()) {
        printf("\n*****************\n");
        printf(" Access Granted.\n");
        printf("*****************\n");
    }
    else {
        printf("\nAccess Denied.\n");
    }
    return 0;
}

