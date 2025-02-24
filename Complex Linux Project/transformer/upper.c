#include "transform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 1024

char* convert_to_upper(const char* text) {
    int len = strlen(text);
    char* result = (char*)malloc(len + 1);
    
    for(int i = 0; i < len; i++) {
        result[i] = toupper(text[i]);
    }
    result[len] = '\0';
    
    return result;
}

int main() {
    char text[MAX_TEXT];
    char* result;

    printf("Enter text to convert to uppercase: ");
    fgets(text, MAX_TEXT, stdin);
    text[strcspn(text, "\n")] = 0;

    result = convert_to_upper(text);
    printf("Result: %s\n", result);
    free(result);
    
    return 0;
}