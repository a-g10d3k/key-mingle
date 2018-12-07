#ifndef KEY_MINGLE_H_INCLUDED
#define KEY_MINGLE_H_INCLUDED
LRESULT __stdcall KeyboardHookCallback(int nCode, WPARAM wParam, LPARAM lParam);

void SetHook(HHOOK* kbh);


#endif // KEY_MINGLE_H_INCLUDED
