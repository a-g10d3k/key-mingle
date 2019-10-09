#include "key_mingle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char keyCodes[256][2] = {0}; //array of keys to swap

//this function adds a pair of keys to the array
int addKeys (int key1, int key2){
    for (int i = 0; i < sizeof(keyCodes)/2; i++){
        if (keyCodes[i][0] == 0){
            keyCodes[i][0] = (char)key1;
            keyCodes[i][1] = (char)key2;
            //printf("<added 0x%x and 0x%x at index %d>",keyCodes[i][0],keyCodes[i][1],i);
            return 0;
        }
    }
    return 1;//there is no free space in the array
}

void TranslateVkCode(unsigned int code, char* str, int strLength){
    code = MapVirtualKey(code, 0);

    long longCode = (long)code << 16;
    if (GetKeyNameTextA(longCode, str, strLength) == 0){
        sprintf(str, "0x%x", code);
    }
}

void GetKeyCodes(KeyCodeArray* array){
    array = &keyCodes;
}

char searchKey(char key){
    for (int i=0; i<sizeof(keyCodes)/2; i++){
        if (keyCodes[i][0] == key){
            return keyCodes[i][1];
        }
    }
    return 0;
}
//displays all the key pairs from the keyCodes array
int displayKeyPairs(){
    SetHookMode(4);
    system("cls");
    puts("ESC - Main menu.");
    for (int i = 0; i < sizeof(keyCodes)/2; i++){
        if (keyCodes[i][0] != 0){
             printf("***%d***\n", i);
             char keyString[30];
             TranslateVkCode(keyCodes[i][0], &keyString, 30);
             printf("%s\n", keyString);
             TranslateVkCode(keyCodes[i][1], &keyString, 30);
             printf("%s\n", keyString);
        }
    }
    return 0;
}

int displayKeyPair(int i){
     printf("***%d***\n", i);
     char keyString[30];
     TranslateVkCode(keyCodes[i][0], &keyString, 30);
     printf("%s\n", keyString);
     TranslateVkCode(keyCodes[i][1], &keyString, 30);
     printf("%s\n", keyString);
}

//this function removes a pair of keys from the array
int removeKeys(int p){
    if (p < sizeof(keyCodes)){
        keyCodes[p][0] = 0;
        keyCodes[p][1] = 0;
        return 0;
    }
    return 1;//int pair is greater than the length of the array
}

//this function saves the keyCodes array to a file
int saveKeys(){
    FILE * dataFile;
    char keyCodes_buffer[sizeof(keyCodes)];

    if ((dataFile = fopen("./key-mingle.dat","wb")) == NULL){
        return 1;
    }

    for(int i = 0; i < sizeof(keyCodes_buffer); i+=2){
        keyCodes_buffer[i] = keyCodes[i/2][0];
        keyCodes_buffer[i+1] = keyCodes[i/2][1];
    }

    fwrite(keyCodes_buffer, sizeof(char), sizeof(keyCodes_buffer), dataFile);
    fclose(dataFile);
    return 0;
}
//this function loads the keyCodes array from a file
int loadKeys(){
    FILE * dataFile;
    char keyCodes_buffer[sizeof(keyCodes)];
    if ((dataFile = fopen("./key-mingle.dat","rb")) == NULL){
        return 1;
    }

    fread(keyCodes_buffer,sizeof(char), sizeof(keyCodes_buffer), dataFile);

    for(int i = 0; i < sizeof(keyCodes_buffer); i+=2){
       keyCodes[i/2][0] = keyCodes_buffer[i];
       keyCodes[i/2][1] = keyCodes_buffer[i+1];
    }

    fclose(dataFile);
    return 0;
}
