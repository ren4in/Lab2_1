#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Header.h"
int main()
{
	Item* ptr = NULL;
	while (puts("enter string"), getList(&ptr)) {
		putList("Entered string", ptr);
		ptr = newString(ptr);
		putList("Result string", ptr);
		ptr = deleteList(ptr);
	}
	return 0;
}