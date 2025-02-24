#include "transform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* convert_to_lower(const char* text) {
    int len = strlen(text);
    char* result = (char*)malloc(len + 1);
    
    for(int i = 0; i < len; i++) {
        result[i] = tolower(text[i]);
    }
    result[len] = '\0';
    
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char* result = convert_to_lower(argv[1]);
    printf("Result: %s\n", result);
    free(result);
    
    return 0;
}