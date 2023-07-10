#include <stdio.h>
#include <stdlib.h>
#include <termios.h>


int main()
{
	int ch;
	struct termios new;
	
	tcgetattr(0,&new);
	new.c_lflag & ~(ECANON | ECHO)     //去掉回显功能

	tcsetattr(0,TCSANOW);

	while(1)
	{
		ch = getchar();
		printf("%x ",ch);
	}


	return 0;
}







