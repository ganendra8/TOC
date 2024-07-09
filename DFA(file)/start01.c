
#include <stdio.h>
#define max 100

int main() {
    char str[max], f = 'a';
    int i;
     printf("Suygo Rana Magar\n");
    printf("\nEnter the string to be checked: ");
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case 'a':
                if (str[i] == '0') f = 'b';
                else f = 'd'; // Transition to a dead state
                break;
            case 'b':
                if (str[i] == '1') f = 'c';
                else f = 'd'; // Transition to a dead state
                break;
            case 'c':
                // Stay in accepting state 'c' for any further input
                f = 'c';
                break;
            case 'd':
                // Stay in dead state 'd' for any further input
                f = 'd';
                break;
        }
    }
    if (f == 'c')
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");

    return 0;
}
