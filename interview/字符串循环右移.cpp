/*
1）先翻转前段“gfedcba hi”,

（2）再翻转后段“gfedcba ih”

（3）最后翻转整个“hi abcdefg”，得到想要的结果。

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reserve(char *p, char *q)
{
	while(p < q)
	{
		*p ^= *q;  //利用异或运算得到两字符交换
		*q ^= *p;
		*p ^= *q;
		p++;
		q--;
	}
}
void loopMove(char *str, int steps)
{
	char *p = str;
	int len = strlen(str);
	char *q = p + len - 1 - steps;
	//printf("%s\n", q);

	reserve(p, q);   //先翻转前一段
	p = q + 1;
	q = str + len - 1;
	reserve(p, q);   //翻转后一段
	p = str;
	reserve(p, q);   //翻转整个字符串
	//printf("%s\n", str);
}

int main()
{
	char string[] = "123456789";
	int steps = 0;

	printf("string: %s\n", string);
	printf("input step: ");
	scanf("%d", &steps);
	loopMove(string, steps);
	printf("after loopMove %d: %s\n", steps, string);

	return 0;
}