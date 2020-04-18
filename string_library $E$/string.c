#include <stdio.h>
#include "_string.h"  ///this must be included

size_t strlen(const char* str);
int strcmp(const char* str1, const char* str2);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t n);
char* strcat(char* dest, const char* src);
char* strncat(char* dest, const char* src, size_t n);
const char* strchr(const char* str, int c);
const char* strrchr(const char* str, int c);

///ststr is the hardest function.  It uses a tricky nested loop and must return an address.
///Here are some hints:
 /// Loop thru str1, looking for the first char of str2
 /// if(str1[i] == str2[0]) Then start inner loop, j=0
 /// loop while str1[i+j] is not null and str2[j] is not null
 /// inside loop, if(str1[i+j] != str2[j]) Then break out of inner loop
 /// when inner loop completes, if(str2[j] == '\0') Then return &str1[i]
 /// if outer loop completes, then return NULL
const char* strstr(const char* str1, const char* str2);
int isalnum(int c );

int main(void){
    char string[69] = "seven";
    char two[12] = " eleven";

    int count = 2;
    //printf("before: %s\n", string);
    //strncat(string, two, count);
    //printf("after: %s\n", string);

    count = strchr(&string, 'e');
    printf("Found \'e\' at: %d\n", count);
}  ///Add your own unit tests here.  When uploading, you can leave it blank.

///Server unit testers will only tell you if it failed or not
///Unit test your own code and study the specifications provided in the description

size_t strlen(const char* str){
    int i = 0;
    while(str[i] != NULL) {
        i++;
    }
    return i;
}

int strcmp(const char* str1, const char* str2){
    int wtf = 1, temp = 0;
    for(int i = 0; i < wtf; i++) {
        if(str1[i] == NULL && str2[i] == NULL){
            return 0;
        }
        else if(str1[i] == NULL) {
            return 0 - str2[i];
        }
        else if(str2[i] == NULL) {
            return str1[i];
        }
        if(str1[i] == str2[i]) {
            wtf++;
        }
        else{
            temp = (int)str1[i] - (int)str2[i];
            return temp;
        }
    }
}

char* strcpy(char* dest, const char* src) {
    for(int i = 0; src[i] != NULL; i++) {
        dest[i] = src[i];
        dest[i + 1] = NULL;
    }
    return dest;
}

char* strncpy(char* dest, const char* src, size_t n) { ///
    //printf("n: %d\n", n);
    for(int i = 0; i <= (int)n && src[i] != NULL; i++) {
        dest[i] = src[i];
        dest[i + 1] = NULL;
    }
    return dest;
}

char* strcat(char* dest, const char* src) {
    int destLen = strlen(dest);

    for(int i = 0; src[i] != NULL; i++) {
        dest[destLen + i] = src[i];
        dest[destLen + i + 1] = NULL;
    }
    return dest;
}

char* strncat(char* dest, const char* src, size_t n){
    int destLen = strlen(dest);

    for(int i = 0; src[i] != NULL && i < (int)n; i++) {
        dest[destLen + i] = src[i];
        dest[destLen + i + 1] = NULL;
    }
    return dest;
}

const char* strchr(const char* str, int c){
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == c) {
            //printf("str[i] == c\n");
            return &str[i];
        }
    }
    return NULL;
}

const char* strrchr(const char* str, int c) {
    for(int i = strlen(str); i > 0; i--) {
        if(str[i] == c) {
            //printf("str[i] == c\n");
            return &str[i];
        }
    }
    return NULL;
}

const char* strstr(const char* str1, const char* str2){
    for(int i = 0, j = 0; str1[i] != NULL; i++) {
        if(str2[0] == str1[i]) {
            for(j = 0; str1[i + j] != NULL && str2[j] != NULL; j++) {
                if(str1[i + j] != str2[j]) {
                    break;
                }
            }
            if(str2[j] == NULL) {
                return &str1[i];
            }
        }
    }
    return NULL;
}

int isalnum(int c ){
    for(char i = 'a'; i <= 'z'; i++) {
        if(i == c) {
            return 1;
        }
    }
    for(char i = 'A'; i <= 'Z'; i++) {
        if(i == c) {
            return 1;
        }
    }
    for(char i = '0'; i <= '9'; i++) {
        if(i == c) {
            return 1;
        }
    }
    return 0;
}
