#include <stdio.h>
#include <ctype.h>
#include <string.h>

void shiftStr(char str[], int shift);
void encipher(FILE* inFile, FILE* outFile, int key);
int validFileSuffix(char str[]);

const int BUFFER_SIZE = 2048;

int main()
{
    char inName[BUFFER_SIZE];

    //TODO(0):  Declare strings for outName and outPrefix
    char outName[BUFFER_SIZE];
    char outPrefix[BUFFER_SIZE];
    FILE* inFile = NULL;
    FILE* outFile = NULL;


    int key;

    ///*****************
    ///printf(" \'c\' + 4 = %c\n", 'c' + 4);
    ///*****************


    //TODO(1):  Prompt and read file name
    printf("Read file name (*.txt): ");
    scanf("%s", inName);
    printf("\n");

    //TODO(2):  Validate file name

    while(validFileSuffix(inName)!= 1) {
       //Error message and prompt / read again
        printf("Error.  *.txt required.\n");
        printf("Read file name (*.txt): ");
        scanf("%s", inName);
        printf("\n");
    }

    //TODO(3):  Open read file
    inFile = fopen(inName, "r");

    //TODO(4):  If the input file is NULL, error and exit program
    if(inFile == NULL) {
        printf("Error: failed to open %s\n", inName);
        return 0;
    }
    //TODO(5):  Prompt and read output file prefix
    printf("Output file prefix: ");
    scanf("%s", outPrefix);
    printf("\n");

    //TODO(6):  Copy prefix to output file string, concatenate input file name
    strcat(outPrefix, inName);

    //TODO(7):  Open output file.  If it fails, exit the program.
    outFile = fopen(outPrefix, "w");

    if(outFile == NULL) {
        printf("Error: failed to open %s\n", outName);
        return 0;
    }
    ///TODO(8):  Prompt and read the key.  Don't forget the & for the int on scanf!!
    printf("Key: ");
    scanf("%d", &key);
    printf("\n");

    printf("Encrypting...\n");
    encipher(inFile, outFile, key);
    printf("Complete.\n");
}

///TODO(9):  validFileSuffix
int validFileSuffix(char str[]) {
    int lel = strlen(str);
    char reps4jesus[5] = {str[lel - 4], str[lel - 3], str[lel - 2], str[lel - 1]}; ///find out if the array is right (substr)
    //printf("   reps4jesus: \"%s\"\n", reps4jesus);///works

    if(strcmp(reps4jesus, ".txt") == 0) {
        return 1;
    }
    else return 0;
}
///TODO(10):  encipher
void encipher(FILE* inFile, FILE* outFile, int key) {
    char herbalTonic[BUFFER_SIZE];
    while(fgets(herbalTonic, BUFFER_SIZE, inFile)) {
        shiftStr(herbalTonic, key);
        fprintf(outFile, "%s", herbalTonic);
    }
}
///declare a string of size BUFFER_SIZE
///using fgets, read while it does not return NULL
///call shiftStr to shift the buffer
///use fprintf to output the string to the output file

///TODO(11):  shiftStr
void shiftStr(char str[], int shift) {
    printf("shiftStr\n");
    int what;

    for(int i = 0; i < strlen(str); i++) {
        //printf("   original: %c   shift: %c\n", str[i], str[i] + shift);

        if(isalpha(str[i]) != 0) {
            //printf("   Is alpha at %c: %d\n", str[i], i);
            //printf("   str(%c) + shift(%d): %c \n", str[i], shift, str[i] + shift);

            if(str[i] >= 'A' && str[i] <= 'Z') {
                what = str[i] + shift;
                if(what > 'Z') {
                    str[i] = str[i] - 26 + shift;
                }
                else if(what < 'A') {
                    str[i] = str[i] + 26 + shift;
                }
                else {
                    str[i] += shift;
                }

            }
            else if(str[i] >= 'a' && str[i] <= 'z') {
                what = str[i] + shift;
                if(what > 'z') {
                    str[i] = str[i] - 26 + shift;
                }
                else if(what < 'a') {
                    str[i] = str[i] + 26 + shift;
                }
                else {
                    str[i] += shift;
                }

            }
            ///printf("str[i]: %c\n", str[i]);

    }
}}
///Mod the shift with 26
///loop through each char
///only process if isalpha is nonzero
///if lowercase and char + shift > 'z' OR uppercase and char + shift > 'Z', subtract 26 from shift
///else if lowercase and char + shift < 'a' OR uppercase and char + shift < 'A', add 26 to shift
///add shift to the char, continue loop

