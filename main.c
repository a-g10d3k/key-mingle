#include <stdio.h>
#include "stdioex.h"
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "key_mingle.h"
#include <string.h>

HHOOK keyboardHook;
HWND window;

unsigned char prompt = 0;//prompt to be displayed, biggest bit is 1 if there is already a prompt displayed

int displayPrompt(){
    if ((prompt & 128)){return 1;}
    switch (prompt){
        case 1:
            menuPrompt();
            break;
    }
    return 0;
}

int menuPrompt(){
    prompt += 128;
    puts("a - add keys");
    puts("d - display current keys");
    puts("r - remove keys");
    puts("o - save keys");
    puts("s - start");   
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
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        }

    return 0;
}


