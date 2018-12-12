#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "key_mingle.h"
#include <stdio.h>
#include "stdioex.h"
//This function is called every time a keyboard event is registered
char lastKey;
LRESULT __stdcall KeyboardHookCallback(int nCode, WPARAM wParam, LPARAM lParam){
    if (nCode >= 0){

    KBDLLHOOKSTRUCT kbdStruct;
    INPUT inputs[1]; //create an array of input structs (actually a single input struct) that will later be fed to the SendInput function
    //set values for the input struct
    inputs[0].type           = INPUT_KEYBOARD;
    inputs[0].ki.wScan       = 0;
    inputs[0].ki.dwFlags     = 0;
    inputs[0].ki.time        = 0;
    inputs[0].ki.dwExtraInfo = 0;

            if(wParam == WM_KEYDOWN){//check if the keyboad event is a keydown event
                    kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
                    lastKey = kbdStruct.vkCode;
                    inputs[0].ki.wVk = searchKey(lastKey);
                    if (inputs[0].ki.wVk != 0){
                        SendInput(1, inputs, sizeof(INPUT));//send input from the input struct
                        return 1;//here we return one in order to prevent the keyboard event from being processed by any other process
                    }


            }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void SetHook(HHOOK* kbh){ //this creates the keyboard hook
*kbh = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHookCallback, NULL, 0);
}
