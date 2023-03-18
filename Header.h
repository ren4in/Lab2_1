#ifndef Header_h
#define Header_h
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Item {
	char symbol;
	struct Item* next;
} Item;
 int getList(Item**);
 void putList(const char*, Item*);
 Item* deleteList(Item*);
 Item* newString(Item*);
 Item* delSpace(Item*);
 Item* skipWord(Item*);
 Item* delWord(Item*);
 char lastChar(Item*);
 int charsMatch(Item*);

#endif