#include <stdio.h>
#include <stdbool.h>


bool isMultiLineComment(const char *str) {
    enum State { q0, q1, q2, q3, q4 };
    enum State currentState = q0;
    
    int i = 0;
    while (str[i] != '\0') {
        switch (currentState) {
            case q0:
                if (str[i] == '/') {
                    currentState = q1;
                } else {
                    return false; // Invalid character sequence, not starting with "/*"
                }
                break;
            case q1:
                if (str[i] == '*') {
                    currentState = q2;
                } else {
                    return false; // Invalid character sequence, expected '*'
                }
                break;
            case q2:
                if (str[i] == '*') {
                    currentState = q3;
                }
                // Continue accepting characters inside the comment
                break;
            case q3:
                if (str[i] == '/') {
                    currentState = q4;
                    return true; // Valid multi-line comment found
                } else if (str[i] != '*') {
                    currentState = q2; // Return to the inside comment state if not '*'
                }
                break;
            case q4:
                // Shouldn't reach here in valid cases of multi-line comment
                return false;
        }
        i++;
    }
    
    return false; // If ended in q2 or q3 without finding "*/", it's an invalid sequence
}

int main() {
    const char *comment1 = "/* Comment_1 */";
    const char *notComment1 = "/* Comment_2 ";
    const char *notComment2 = "/ Comment_3 */";
    const char *comment2 = "/* This is a\nmulti-line\ncomment */";
    
    printf("%s: %s\n", comment1, isMultiLineComment(comment1) ? "Valid comment" : "Not a valid comment");
    printf("%s: %s\n", notComment1, isMultiLineComment(notComment1) ? "Valid comment" : "Not a valid comment");
    printf("%s: %s\n", notComment2, isMultiLineComment(notComment2) ? "Valid comment" : "Not a valid comment");
    printf("%s: %s\n", comment2, isMultiLineComment(comment2) ? "Valid comment" : "Not a valid comment");
    
    return 0;
}
