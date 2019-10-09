#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "key_mingle.h"
#include <stdio.h>
#include "stdioex.h"
#include <stdlib.h>
//This function is called every time a keyboard event is registered
char lastKey;
char mode;
unsigned char keyPairIndex = 0;
char keyInput[2];
LRESULT __stdcall KeyboardHookCallback(int nCode, WPARAM wParam, LPARAM lParam){
    if (nCode >= 0){
    KBDLLHOOKSTRUCT kbdStruct;
    INPUT inputs[1]; //create an array of input structs (actually a single input struct) that will later be fed to the SendInput function
    //set values for the input struct
    inputs[0].type           = INPUT_KEYBOARD;
    inputs[0].ki.wScan       = 0;
    inputs[0].ki.dwFlags     = 0;
    if (wParam == WM_KEYUP){inputs[0].ki.dwFlags += 2;}//add the keyup flag if the keyboard event was a keyup event
    inputs[0].ki.time        = 0;
    inputs[0].ki.dwExtraInfo = 0;
            switch (mode){
                case 0:
                    if(wParam == WM_KEYDOWN || wParam == WM_KEYUP){//check if the keyboad event is a keydown event
                            kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
                            lastKey = kbdStruct.vkCode;
                            inputs[0].ki.wVk = searchKey(lastKey);
                            if (inputs[0].ki.wVk != 0){
                                SendInput(1, inputs, sizeof(INPUT));//send input from the input struct
                                return 1;//here we return one in order to prevent the keyboard event from being processed by any other process
                            }
                    }
                    break;
                case 1:
                    if(wParam == WM_KEYDOWN){
                            kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
                        if(keyInput[0] == 0){
                            keyInput[0] = kbdStruct.vkCode;
                            system("cls");
                            puts("Press key 2 (The one you want to map key 1 to).");
                        }
                        else{
                            keyInput[1] = kbdStruct.vkCode;
                            addKeys(keyInput[0],keyInput[1]);
                            MainMenu();
                        }
                    }
                    break;
                case 2:
                    if (wParam == WM_KEYDOWN){
                        kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
                        switch (kbdStruct.vkCode){
                            case 0x41:
                                puts("a");
                                AddKeysMenu();
                                break;
                            case 0x44:
                                displayKeyPairs();
                                break;
                            case 0x52:
                                RemoveKeysMenu(0);
                                break;
                            case 0x4f:
                                saveKeys();
                                break;
                            case 0x53:
                                system("cls");
                                SetHookMode(0);
                                break;
                        }
                    }
                    break;
                case 3:
                    if(wParam == WM_KEYDOWN){
                        kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
                        switch (kbdStruct.vkCode){
                            case VK_UP:
                                RemoveKeysMenu(++keyPairIndex);
                                break;
                            case VK_DOWN:
                                RemoveKeysMenu(--keyPairIndex);
                                break;
                            case VK_RETURN:
                                removeKeys(keyPairIndex);
                                MainMenu();
                                keyPairIndex = 0;
                                break;
                            case VK_ESCAPE:
                                MainMenu();
                                keyPairIndex = 0;
                                break;
                        }
                    }
                    break;
                case 4:
                    if(wParam == WM_KEYDOWN){
                        kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
                        if (kbdStruct.vkCode == VK_ESCAPE){
                            MainMenu();
                        }
                    }
                    break;
                    }
            }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void SetHook(HHOOK* kbh){ //this creates the keyboard hook
    *kbh = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHookCallback, NULL, 0);
}

void SetHookMode(char hookMode){
    mode = hookMode;

    switch (mode){
        case 1:
        keyInput[0] = 0;
        keyInput[1] = 0;
        break;
    }
}
