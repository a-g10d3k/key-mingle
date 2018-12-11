#ifndef KEY_MINGLE_H_INCLUDED
#define KEY_MINGLE_H_INCLUDED
#include <windows.h>

LRESULT __stdcall KeyboardHookCallback(int nCode, WPARAM wParam, LPARAM lParam);
void SetHook(HHOOK* kbh);

int addKeys (char key1, char key2);
int removeKeys(int p);
#endif // KEY_MINGLE_H_INCLUDED
