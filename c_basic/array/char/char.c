#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  STRSIZE  32

/*strlen & sizeof
**strcpy & strncpy
**strcat & strncat
**strcmp & strncmp
**/

int main(void)
{
/*	char str[N];
	scanf("%s", str);
	printf("%s\n", str);
*/

/*	char str[] = "hello\0abc";
	printf("%d\n", strlen(str)); //strlen以\0为结束标志
	printf("%d\n", sizeof(str)); //sizeof包含\0大小
*/

/*	char str[3] = "hel";
//	strcpy(str, "abcde");   //不检查越界
	strncpy(str, "abcde", 3);
	printf("%s\n", str);   
*/

/*	char str[9] = "hello";
//	strcat(str, " world!");   //会越界
	strncat(str, " world!", 9-strlen(str));
	puts(str);
*/

	char str[STRSIZE] = "hello";
	char str1[STRSIZE] = "helloa";
	printf("%d\n", strcmp(str,str1)); //strcmp比较的是字符的asc码大小，str-str1的值
	printf("%d\n", strncmp(str, str1, 5)); //比较前n个字符串的大小

	exit(0);
}

















