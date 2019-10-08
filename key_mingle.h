#ifndef KEY_MINGLE_H_INCLUDED
#define KEY_MINGLE_H_INCLUDED
#define _WIN32_WINNT 0x0500
#include <windows.h>
typedef char KeyCodeArray[256][2];

LRESULT __stdcall KeyboardHookCallback(int nCode, WPARAM wParam, LPARAM lParam);
void SetHook(HHOOK* kbh);
void SetHookMode(char mode);
void StartMessageLoop(char mode);

int addKeys (int key1, int key2);
char searchKey(char key);
int displayKeyPairs();
int displayKeyPair();
int removeKeys(int p);
int saveKeys();
int loadKeys();
void GetKeyCodes( KeyCodeArray* );
void TranslateVkCode(unsigned int, char*, int);

void MainMenu();
void AddKeysMenu();
void RemoveKeysMenu(unsigned char i);
#endif // KEY_MINGLE_H_INCLUDED
