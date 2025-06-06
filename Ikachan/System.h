#pragma once
//#include <windows.h>
#include <SDL2/SDL.h>

//Keys
#define MOUSE_RIGHT (0x00000001)
#define MOUSE_LEFT  (0x00000002)

#define KEY_LEFT  (0x00000001)
#define KEY_RIGHT (0x00000002)
#define KEY_UP    (0x00000004)
#define KEY_DOWN  (0x00000008)
#define KEY_SPACE (0x00000010)
#define KEY_X     (0x00000020)
#define KEY_Z     (0x00000040)
#define KEY_S     (0x00000080)

extern unsigned long gKey, gKeyTrg;
extern unsigned long gMouse, gMouseTrg, gMouseTrg2;

//Window size
enum WND_SIZE
{
	WS_FULLSCREEN,
	WS_320x240,
	WS_640x480
};
extern WND_SIZE gWndSize;

//Windows objects
//extern HWND ghWnd;

//Filepath
#ifndef MAX_PATH
#define MAX_PATH 260
#endif

extern char gModulePath[MAX_PATH];

int Random(int min, int max);
bool SystemTask();
void ProcessSystemEvent(SDL_Event *e);
