#include <stdio.h>
#include "stdioex.h"
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "key_mingle.h"
#include <string.h>

HHOOK keyboardHook;
HWND window;

unsigned char prompt = 1;//prompt to be displayed, highest bit is 1 if there is already a prompt displayed
unsigned char inputFunction = 0;

int menuPrompt(){
    prompt = 129;
    inputFunction = 1
    puts("a - add keys");
    puts("d - display current keys");
    puts("r - remove keys");
    puts("o - save keys");
    puts("s - start");   
}

int displayPrompt(){
    if ((prompt & 128)){return 1;}
    switch (prompt){
        case 1:
            menuPrompt();
            break;
        case 10:
            
            break;
    }
    return 0;
}

int mainMenuInput(char keyPress){
    switch (keyPress){
        case 0x41:
            inputFunction = 10;
            break;
        case 0x44:
            //display keys
            break;
        case 0x52:
            //remove keys
            break;
        case 0x4F:
            //save settings
            break;
        case 0x53:
            //start
            break;
    }
    return 0;   
}

int addKeyInput(){
    if (inputFunction == 10){
           prompt = 10;
            
    }
    else if (inputFunction
}

int readInput(){
    char keyPress = getLastKey();
    switch (inputFunciton){
        case 1:
            mainMenuInput(keyPress);
            break;
        case 10:
        case 11:
            addKeyInput(keyPress);
            break;
            
    }
    return 1;
}

//asks the user to input two keys and calls the addKeys function to add them to the keyCodes array
int inputKeys(){
    int key1, key2;
    puts("key 1:");
    scanf("%i", &key1);
    puts("key 2:");
    scanf("%i", &key2);
    return addKeys (key1, key2);
}

//asks the user to input the index of a key pair and then removes it
int inputRemoveKeys(){
    int index;
    puts("index of the pair to be removed:");
    scanf("%i", &index);
    return removeKeys(index);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShhow){
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    if (loadKeys() == 1){
        puts("<key-mingle.dat not found, can't load settings.>");
    }
    //ShowWindow(window,0);
/*
    for (;;){
        char cliInput = get1char();
        switch (cliInput){
            case 'a':
                inputKeys();
                break;
            case 'd':
                displayKeyPairs();
                break;
            case 'r':
                inputRemoveKeys();
                break;
            case 'o':
                if (saveKeys() != 0){printf("saving error");}
                break;
            case 's':
                goto msgloop;
        }
    }
    msgloop:
*/
    SetHook(&keyboardHook);
    MSG msg;

    while (GetMessage(&msg,NULL,0,0) > 0){
        displayPrompt();
        readInput();
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        }

    return 0;
}


