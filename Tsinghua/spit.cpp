#include<iostream>
#include<string>
using namespace std;
#include <stdio.h>
#include <string.h>
char s[35] = { 0 };
char s2[35] = { 0 };

int len = 0;
char e[35] = { 0 };

void Push(int pos, char led[]);

int main3()
{
	//这两个f是干嘛的，我写的时候应该知道，但是现在只有上帝知道
	int f1 = 0;
	int f2 = 0;
	int i = 0;
	int r1 = 0;
	int r2 = 0;
	scanf_s("%s", &s);
	len = strlen(s);

	for (i = 0; i<len; i++)
		s2[i] = s[i];
	s2[i] = '\0';

	scanf_s("%s", &e);

	r1 = 1;
	Push(0, s);
	for (i = 1; i < len; i++)
	{
		if (s[i - 1] != e[i - 1])
		{
			Push(i, s);
			r1++;
		}
	}

	if (strcmp(s, e) != 0)
		f1 = 1;

	r2 = 0;
	for (i = 1; i < len; i++)
	{
		if (s2[i - 1] != e[i - 1])
		{
			Push(i, s2);
			r2++;
		}
	}
	if (strcmp(s2, e) != 0)
		f2 = 1;

	if (f1 == 1 && f2 == 1)
	{
		printf("impossible");
		return 0;
	}

	if (f1 == 1 && f2 == 0)
	{
		printf("%d", r2);
		return 0;
	}


	if (f1 == 0 && f2 == 1)
	{
		printf("%d", r1);
		return 0;
	}

	if (r1 < r2)
		printf("%d", r1);
	else
		printf("%d", r2);


	return 0;
}

void Push(int pos, char led[])
{
	if (pos>0)
		led[pos - 1] -= 48;

	led[pos] -= 48;

	if (pos<len - 1)
		led[pos + 1] -= 48;


	if (pos == 0)
	{
		led[pos] = 1 - led[pos];
		led[pos + 1] = 1 - led[pos + 1];
	}
	else if (pos == len - 1)
	{

		led[len - 1] = 1 - led[len - 1];
		led[len - 2] = 1 - led[len - 2];
	}
	if (pos > 0 && pos < len - 1)
	{

		led[pos] = 1 - led[pos];
		led[pos + 1] = 1 - led[pos + 1];
		led[pos - 1] = 1 - led[pos - 1];
	}

	if (pos>0)
		led[pos - 1] += 48;

	led[pos] += 48;

	if (pos<len - 1)
		led[pos + 1] += 48;
}