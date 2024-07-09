
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
                else f = 'a';
                break;
            case 'b':
                if (str[i] == '0') f = 'b';
                else if (str[i] == '1') f = 'c';
                else f = 'a';
                break;
            case 'c':
                if (str[i] == '0') f = 'd';
                else f = 'a';
                break;
            case 'd':
                // Once in state 'd', stay there as the substring "010" has been found
                f = 'd';
                break;
        }
    }
    if (f == 'd')
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");

    return 0;
}
