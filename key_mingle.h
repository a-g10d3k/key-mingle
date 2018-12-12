#ifndef KEY_MINGLE_H_INCLUDED
#define KEY_MINGLE_H_INCLUDED
#include <windows.h>

LRESULT __stdcall KeyboardHookCallback(int nCode, WPARAM wParam, LPARAM lParam);
void SetHook(HHOOK* kbh);

int addKeys (int key1, int key2);
char searchKey(char key);
int displayKeyPairs();
int removeKeys(int p);
#endif // KEY_MINGLE_H_INCLUDED
