#include <stdio.h>
#include "record.h"
#include "game.h"
void readfile()
{
	// 输入玩家名字 
	int i;
	char name[10]={0};
	printf("input your player name:");
    scanf ("%s",&name);
}
void print_time (time_t a,time_t b)
{
	// 显示时间 
	printf("time=%d\n",difftime(a,b));
}
void writefile()
{
	
}
