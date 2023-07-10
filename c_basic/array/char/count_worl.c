#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  STRSIZE 128

int main(void)
{
	char str[STRSIZE];
	int count = 0;
	gets(str);
	for(int i = 0; str[i] != '\0'; i++)
	{
		int flag;
		if(str[i] == ' ')    //小bug，只能检测空格，如tab键的情况无法检测
			flag = 0;
		else
			if(flag == 0)   //str[i] is a char.
			{
				count++;
				flag = 1;
			}
	}
	printf("count = %d\n", count);
	
	exit(0);
}














