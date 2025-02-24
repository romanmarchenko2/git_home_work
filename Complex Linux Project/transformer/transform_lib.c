#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* convert_to_upper(const char* text) {
    int len = strlen(text);
    char* result = (char*)malloc(len + 1);
    
    for(int i = 0; i < len; i++) {
        result[i] = toupper(text[i]);
    }
    result[len] = '\0';
    
    return result;
}

char* convert_to_lower(const char* text) {
    int len = strlen(text);
    char* result = (char*)malloc(len + 1);
    
    for(int i = 0; i < len; i++) {
        result[i] = tolower(text[i]);
    }
    result[len] = '\0';
    
    return result;
}