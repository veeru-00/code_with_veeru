#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE *fd;
	fd=fopen("execute.txt","r");
	if(fd==NULL)
	{
		printf("File open failed");
		return 1;
	}
	char cmd[256];
	while(fgets(cmd,sizeof(cmd),fd))
	{
		system(cmd);
	}
	fclose(fd);
	return 0;
}
