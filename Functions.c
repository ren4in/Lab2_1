#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Header.h"
int getList(Item** pptr)
{
	char buf[21], * str;
	Item head = { '*', NULL };
	Item* last = &head;
	int n, rc = 1;
	do {
		n = scanf("%20[^\n]", buf);
		if (n < 0) {
			deleteList(head.next);
			head.next = NULL;
			rc = 0;
			continue;
		}
		if (n > 0) {
			for (str = buf; *str != '\0'; ++str) {
				last->next = (Item*)malloc(sizeof(Item));
				last = last->next;
				last->symbol = *str;
			}
			last->next = NULL;
		}
		else
			scanf("%*c");
	} while (n > 0);
	*pptr = head.next;
	return rc;
}void putList(const char* msg, Item* ptr)
{
	printf("%s: \"", msg);
	for (; ptr != NULL; ptr = ptr->next)
		printf("%c", ptr->symbol);
	printf("\"\n");
}

Item* deleteList(Item* ptr)
{
	Item* tmp = NULL;
	while (ptr != NULL) {
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	return ptr;
}
Item* delSpace(Item* ptr)
{
	Item* tmp;
	while (ptr && (ptr->symbol == ' ' || ptr->symbol == '\t')) {
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	return ptr;
}
Item* skipWord(Item* ptr)
{
	while (ptr->next && ptr->next->symbol != ' ' && ptr->next->symbol != '\t')
		ptr = ptr->next;
	return ptr;
}
Item* delWord(Item* ptr)
{
	Item* tmp;
	while (ptr && ptr->symbol != ' ' && ptr->symbol != '\t') {
		tmp = ptr;
 		ptr = ptr->next;
		free(tmp);
	}
	return ptr;
}

char lastChar(Item* ptr) //находит последнюю букву в слове
{
	while (ptr->next && ptr->next->symbol != ' ' && ptr->next->symbol != '\t')
		ptr = ptr->next;
	return ptr->symbol;
}

int charsMatch(Item* ptr) //проверяет, совпадают ли буквы в слове
{
	char firstChar = ptr->next->symbol;
	
	if (firstChar == lastChar(ptr))
		return 1;
	else
		return 0;

}

Item* newString(Item* p)
{
	Item head = { '*', p };
	Item* cur = &head, * prev = &head,  * last = &head;
	 while (cur && (cur->next = delSpace(cur->next))) 
	 {
	
 		if (charsMatch(cur)) {
			cur = skipWord(cur->next);
			prev = cur; 
			cur = cur->next; 		
		if (cur)
		{
				cur->symbol = ' ';
		}
	}
else
cur->next = delWord(cur->next);

}
if (prev->next) {
	free(prev->next);
	prev->next = NULL;
}
return head.next;
}
 

/*
*/