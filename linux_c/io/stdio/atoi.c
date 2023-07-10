/*
int atoi(const char *nptr); 将字符串转换为整形
int sprintf(char *str,const char *format,...)相当于atoi的反向实现,不检查溢出；
int snprintf(char *str,size_t size,const char *format,...)
int fprintf(FILE *stream,const char *format,...)
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
//	char str[] = "1234456";
//	printf("%d\n",atoi(str));

	char buf[1024];
	int year = 2023,month = 4,day = 7;
	sprintf(buf,"%d-%d-%d",year,month,day);

	exit(0);
}




