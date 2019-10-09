#include <stdio.h>
#include <windows.h>
#include "key_mingle.h"
#include <string.h>

void MainMenu(){
    system("cls");
    puts("a - add keys");
    puts("d - display current keys");
    puts("r - remove keys");
    puts("o - save keys");
    puts("s - start");
    SetHookMode(2);
}

void AddKeysMenu(){
    system("cls");
    puts("Press key 1 (The one you want to bind to key 2)");
    SetHookMode(1);
}

void RemoveKeysMenu(unsigned char index){
    system("cls");
    SetHookMode(3);
    puts("UP/DOWN - Select pair.");
    puts("RETURN - Remove pair.");
    puts("ESCAPE - Return to main menu.\n");
    displayKeyPair(index);
    return index;
}
