#include <stdio.h>
#include "record.h"
#include "game.h"
void readfile()
{
	// ����������� 
	int i;
	char name[10]={0};
	printf("input your player name:");
    scanf ("%s",&name);
}
void print_time (time_t a,time_t b)
{
	// ��ʾʱ�� 
	printf("time=%d\n",difftime(a,b));
}
void writefile()
{
	
}
