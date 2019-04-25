#include <stdio.h>
#include <string.h>
#include "record.h"
#include "game.h"

// data structure for record
struct name_time {
	char name [10];
	int time;
} record[4];

// Get the player name and store it
void get_new ()
{
	printf("input your player name:\n");
	scanf("%s",record[3].name);
}

// Read records from a file
void readfile()
{
	FILE *fp;
	fp=fopen("record.txt","r");
	if( fp == NULL ){
		puts("This game has not been recorded");
    }
	else{
	fscanf(fp,"%s",record[0].name);
	fscanf(fp,"%d",&record[0].time);
    fscanf(fp,"%s",record[1].name);
    fscanf(fp,"%d",&record[1].time);
    fscanf(fp,"%s",record[2].name);
    fscanf(fp,"%d",&record[2].time);
	}
	
    
    
	fclose(fp);
}

// Display the results of the game this time .
void print_time (time_t a,time_t b)
{
	// ÏÔÊ¾Ê±¼ä 
	record[3].time = difftime(b,a);
	printf("Name=%s\n",record[3].name);
	printf("Time=%d\n",record[3].time);
}

// Check if the results can be written into the ranking list and adjust the ranking list
void compare()
{
	if (record[3].time>record[0].time)
	{
		printf("You are no. 1 at present!!!\n");
		record[2].time = record[1].time;
		strcpy(record[2].name, record[1].name);
		record[1].time = record[0].time;
		strcpy(record[1].name, record[0].name);
		record[0].time = record[3].time;
		strcpy(record[0].name, record[3].name);
	}
	else if (record[3].time>record[1].time)
	{
		printf("You are no. 2 at present!!!\n");
		record[2].time = record[1].time;
		strcpy(record[2].name, record[1].name);
		record[1].time = record[3].time;
		strcpy(record[1].name, record[3].name);
	}
	else if (record[3].time>record[2].time)
	{
		printf("You are no. 3 at present!!!\n");
		record[2].time = record[3].time;
		strcpy(record[2].name, record[3].name);
	}
	else
	{
		printf("Make persistent efforts!!!\n");
	}
}

// write records to file 
void writefile()
{
	FILE *fp;
	fp=fopen("record.txt","w");
	if( fp == NULL ){
        puts("Fail to open file!");
    }
	else {
		fprintf(fp,"%s\n%d\n",record[0].name, record[0].time);
   		fprintf(fp,"%s\n%d\n",record[1].name, record[1].time);
    	fprintf(fp,"%s\n%d\n",record[2].name, record[2].time);
	}
	fclose(fp);
}

// Display ranking list
void show_record()
{
	int i, k;
	printf("        RANKING LIST\n");
	for (k=0;k<3;k++) {
		printf("%d.  Name:%s", k+1, record[k].name);
		for (i=0;i<12-strlen(record[k].name);i++){
			printf(" ");
		}
		printf("Time:%d\n", record[k].time);
	}
}
