// #include <windows.h>
//#include <winuser.h>

/*
typedef struct tagWNDCLASSA {
  UINT      style;
  WNDPROC   lpfnWndProc;
  int       cbClsExtra;
  int       cbWndExtra;
  HINSTANCE hInstance;
  HICON     hIcon;
  HCURSOR   hCursor;
  HBRUSH    hbrBackground;
  LPCSTR    lpszMenuName;
  LPCSTR    lpszClassName;
} WNDCLASSA, *PWNDCLASSA, *NPWNDCLASSA, *LPWNDCLASSA;
*/

#include <stdio.h>

int
main()
{
    // if (MessageBox(nullptr, "Hello, from cpp for win32", "Hello cpp win32", MB_OK | MB_ICONINFORMATION) != IDOK) {
    //     return 1;
    // }

    // WNDCLASS windowClass = {0};

    printf("Hello, World!\n");
    return 0;
}
