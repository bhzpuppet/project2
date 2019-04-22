#include <stdio.h>
#include <string.h>
#include "record.h"
#include "game.h"
struct name_time {
	char name [10];
	int time;
} record[4];
// 获取玩家名字并存储 
void get_new ()
{
	printf("input your player name:\n");
	gets(record[3].name);
}
// 读取记录文件 
void readfile()
{
	FILE *fp;
	fp=fopen("q.txt","r");
//    fscanf(fp,"%s,%d",record[0].name, record[0].time);
//    fscanf(fp,"%s,%d",record[1].name, record[1].time);
//    fscanf(fp,"%s,%d",record[2].name, record[2].time);
	fscanf(fp,"%s",record[0].name);
	fscanf(fp,"%d",&record[0].time);
    fscanf(fp,"%s",record[1].name);
    fscanf(fp,"%d",&record[1].time);
    fscanf(fp,"%s",record[2].name);
    fscanf(fp,"%d",&record[2].time);
    
    
	fclose(fp);
	printf("%s,%d,",record[0].name,record[0].time);
	printf("%s,%d,",record[1].name,record[1].time);
	printf("%s,%d\n",record[2].name,record[2].time);
}

void print_time (time_t a,time_t b)
{
	// 显示时间 
	record[3].time = difftime(b,a);
	printf("time=%d\n",record[3].time);
}

void compare()
{
	if (record[3].time>record[0].time)
	{
		record[2].time = record[1].time;
		strcpy(record[2].name, record[1].name);
		record[1].time = record[0].time;
		strcpy(record[1].name, record[0].name);
		record[0].time = record[3].time;
		strcpy(record[0].name, record[3].name);
	}
	else if (record[3].time>record[1].time)
	{
		record[2].time = record[1].time;
		strcpy(record[2].name, record[1].name);
		record[1].time = record[3].time;
		strcpy(record[1].name, record[3].name);
	}
	else if (record[3].time>record[2].time)
	{
		record[2].time = record[3].time;
		strcpy(record[2].name, record[3].name);
	}
}

void writefile()
{
	FILE *fp;
	fp=fopen("q.txt","w");
    fprintf(fp,"%s\n%d\n",record[0].name, record[0].time);
    fprintf(fp,"%s\n%d\n",record[1].name, record[1].time);
    fprintf(fp,"%s\n%d\n",record[2].name, record[2].time);
	fclose(fp);
}

void show_record(){
	int i = 0;
	int k = 0;
	for (k=0;k<3;k++) {
		printf("name:%s", record[k].name);
		for (i=0;i<12-strlen(record[k].name);i++){
			printf(" ");
		}
		printf("time:%d\n", record[k].time);
	}
}
