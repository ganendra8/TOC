#include<stdio.h>
#include<string.h>

char input[20];
int l;
int flag;

void q2(int i){
    if(input[i] == '\0')
    flag = 1;
}

void q1(int i){
    if(i<l){
        if(input[i] == '1'){
        i++;
        q2(i);
        }
    }
}

void q0(int i){
    if(i<l){
        int k = i;
        if(input[i] == '0'){
            k++;
            q0(k);
            q1(k);
        }else{
            if(input[i] == '1'){
            i++;
            q0(i);
            }
        }
    }
}

int main(){

    printf("\nEnter a String: ");
    gets(input);

    l = strlen(input);
    int i = 0;
    flag = 0;
    q0(i);
    printf("Suyog Rana Magar\n");
    if(flag == 1)
        printf("String Accepted\n");
        else
        printf("String Rejected\n");
    return 0;
}
