#include <stdio.h>

int strcmp(char *str1, char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}
#include <stdio.h>

char* strcpy(char *destination, char *source) {
    char *ptr = destination;
    
    while (*source) {
        *destination = *source;
        destination++;
        source++;
    }
    
    *destination = '\0';  
    
    return ptr;
}
#include <stdio.h>

char* strcat(char *destination, char *source) {
    char *ptr = destination;
    
    while (*destination) {
        destination++;
    }
    
    while (*source) {
        *destination = *source;
        destination++;
        source++;
    }
    
    *destination = '\0';  
    
    return ptr;
}
#include <stdio.h>


int strcmp(char *str1, char *str2);
char* strcpy(char *destination, char *source);
char* strcat(char *destination,char *source);

int main() {
    
    char *str1 = "Hello";
    char *str2 = "Hello";
    int cmp = strcmp(str1, str2);
    
    if (cmp == 0) {
        printf("Strings are equal.\n");
    } else if (cmp < 0) {
        printf("String 1 is less than string 2.\n");
    } else {
        printf("String 1 is greater than string 2.\n");
    }
    
   
    char dest[20];
    char *source = "Copy this string";
    strcpy(dest, source);
    printf("Copied string: %s\n", dest);
    
  
    char str[50] = "Hello";
    char *suffix = " World!";
    strcat(str, suffix);
    printf("Concatenated string: %s\n", str);
    
    return 0;
}
