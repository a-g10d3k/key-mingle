#include "key_mingle.h"
#include <stdio.h>

char keyCodes[256][2] = {0}; //array of keys to swap

//this function adds a pair of keys to the array
int addKeys (char key1, char key2){
    for (int i = 0; i < sizeof(keyCodes)/2; i++){
        if (keyCodes[i][0] == 0){
            keyCodes[i][0] = key1;
            keyCodes[i][1] = key2;
            return 0;
        }
    }
    return 1;//there is no free space in the array
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
    for (int i = 0; i < sizeof(keyCodes)/2; i++){
        if (keyCodes[i][0] != 0){
             puts("------");
             printf("%c (%d)", keyCodes[i][0], keyCodes[i][0]);
             putc('\n', stdout);
             printf("%c (%d)", keyCodes[i][1], keyCodes[i][1]);
             putc('\n', stdout);
        }
    }
    puts("-----");
    return 0;
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
