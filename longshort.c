#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]){

    // declare variables
    char line[255];
    int shortLine = 0;
    int longLine = 0;

    // open two destination files and one read file
    FILE *readFile = fopen(argv[1], "r");
    FILE *shortFile = fopen(argv[2], "w");
    FILE *longFile = fopen(argv[3], "w");
    
    // while there is a line
    while(fgets(line, 255, readFile) != NULL){
        
        // find the length of the line
        int length = 0;
        for(int i = 0; line[i] != '\0'; i++){
            length++;
        }

        // if the line is less than 20 characters, capitalize and write to a file
        if(length < 20){

            for(int i = 0; i < length; i++){
                line[i] = toupper(line[i]);
            }
            fputs(line, shortFile);
            shortLine++;
        }

        // if the line is 20 or more characters, lowercase and write to a file
        if(length >= 20){

            for(int i = 0; i < length; i++){
                line[i] = tolower(line[i]);
            }
            fputs(line, longFile);
            longLine++;
        }
        
    }

    // close files
    fclose(readFile);
    fclose(shortFile);
    fclose(longFile);

    // display written line information
    printf("%d lines written to short.txt\n", shortLine);
    printf("%d lines written to long.txt\n", longLine);

}