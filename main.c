#include <stdio.h>
#include "stdioex.h"
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "key_mingle.h"
#include <string.h>

HHOOK keyboardHook;
HWND window;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShhow){
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    if (loadKeys() == 1){
        puts("<key-mingle.dat not found, can't load settings.>");
    }

    SetHook(&keyboardHook);

    //ShowWindow(window,0);
    MainMenu();

    StartMessageLoop(2);

    return 0;
}


