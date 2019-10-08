#include <windows.h>
#include "key_mingle.h"
#include <stdio.h>

void StartMessageLoop(char mode){
    SetHookMode(mode);
    MSG msg;
    while (GetMessage(&msg,NULL,0,0) > 0){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        }
}
