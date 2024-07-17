#include <stdio.h>
#include <stdbool.h>


bool isSingleLineComment(const char *str) {
    enum State { q0, q1, q2, q3 };
    enum State currentState = q0;
    
    int i = 0;
    while (str[i] != '\0') {
        switch (currentState) {
            case q0:
                if (str[i] == '/') {
                    currentState = q1;
                } else {
                    return false; 
                }
                break;
            case q1:
                if (str[i] == '/') {
                    currentState = q2;
                } else {
                    return false; // Invalid character sequence, expected second '/'
                }
                break;
            case q2:
                if (str[i] == '\n') {
                    currentState = q3;
                    return true; // Valid single-line comment found
                }
                // Continue accepting characters inside the comment
                break;
            case q3:
                // Shouldn't reach here in valid cases of single-line comment
                return false;
        }
        i++;
    }
    
    // If ended in q2, it means the comment was not terminated by '\n'
    if (currentState == q2) {
        return true; // Consider it a valid comment if it ends without '\n'
    }
    
    return false; // If ended in q0 or q1, it's an invalid sequence
}

int main() {
    printf("Suyog Rana Magar\n");
    const char *comment1 = "// Comment_1";
    const char *notComment1 = "/ Comment_2";
    
    printf("%s: %s\n\n", comment1, isSingleLineComment(comment1) ? "Valid comment" : "Not a valid comment");
    printf("%s: %s\n", notComment1, isSingleLineComment(notComment1) ? "Valid comment" : "Not a valid comment");
    
    return 0;
}