#pragma once
//#include <windows.h>

#define MAX_CARETS (120)
#define MAX_CARET_SPAWNERS (10)

#define NO_CARET (0xFFFFFF)

struct CARET
{
  bool cond;
  unsigned char type;
  int x;
  int y;
  int xm;
  int ym;
  char ani_no;
  unsigned short x16;
  int ani_wait;
};

struct CARET_SPAWNER
{
	bool cond;
	unsigned char type;
	char ani_no;
	char num;
	int x;
	int y;
	int rand_moveright;
	int rand_moveleft;
	int rand_movedown;
	int rand_moveup;
	int rand_x;
	int rand_y;
};

struct MAP; //prototype;
struct FRAME; //prototype

int FindCaret(CARET *caret);
void ProcCaret(CARET *caret, MAP *map, FRAME *frame);
int FindCaretSpawner(CARET_SPAWNER *caret_spawner);
void ProcCaretSpawner(CARET_SPAWNER *caret_spawner, CARET *caret);
