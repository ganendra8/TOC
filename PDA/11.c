#include <stdio.h>
#include <string.h>
#define MAX 100

enum states {q0, q1, qf};

void push(char ch);
void pop();
char get_stack_top();
enum states delta(enum states s, char ch, char st_top);

struct stack {
    char symbols[MAX];
    int top;
} s;

int main() {
    char input[20];
    enum states curr_state = q0;
    s.top = -1;  // Initial stack is empty

    printf("\nEnter a binary string: ");
    fgets(input, 20, stdin);  // safer than gets

    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    int i = 0;
    char ch = input[i];
    char st_top = 'e';  // Initial stack symbol

    while (i <= strlen(input)) {
        curr_state = delta(curr_state, ch, st_top);
        ch = input[++i];
        st_top = get_stack_top();
    }

    if (curr_state == qf && s.top == -1) {
        printf("\nThe string %s is accepted.\n", input);
    } else {
        printf("\nThe string %s is not accepted.\n", input);
    }

    return 0;
}

enum states delta(enum states s, char ch, char st_top) {
    switch (s) {
        case q0:
            if (ch == '0' && st_top == 'e') {
                push('$');  // Push initial marker
                push('0');
                return q1;
            }
            break;

        case q1:
            if (ch == '0' && (st_top == '$' || st_top == '0')) {
                push('0');
                return q1;
            }
            if (ch == '1' && (st_top == '$' || st_top == '1')) {
                push('1');
                return q1;
            }
            if ((ch == '1' && st_top == '0') || (ch == '0' && st_top == '1')) {
                pop();
                return q1;
            }
            if (ch == '\0' && st_top == '$') {
                pop();
                return qf;
            }
            break;

        default:
            break;
    }
    return s;
}

char get_stack_top() {
    if (s.top == -1)
        return 'e';  // Stack is empty
    return s.symbols[s.top];
}

void push(char ch) {
    if (s.top < MAX - 1) {
        s.symbols[++s.top] = ch;
    } else {
        printf("\nStack full.\n");
    }
}

void pop() {
    if (s.top > -1) {
        s.top--;
    } else {
        printf("\nStack empty.\n");
    }
}
