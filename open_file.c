#include"header.h"
#include"declaration.h"

int open_file(char * mode)
{
	int fd;
	char fname[20];
	scanf("%s",fname);
	printf("%s : Begins\n",__func__);
	if((strncmp(mode,"O_RDONLY", 8)) == 0)
		fd = open (fname,O_RDONLY);

	else if((strncmp(mode,"O_WRONLY|O_CREAT", 16)) == 0)
		fd = open (fname,O_WRONLY|O_CREAT);
	
	if(fd == -1)
	{
		perror ("OPEN:");
		exit(EXIT_FAILURE);

	}
	printf("file opened successfully...\n");
	printf("%s : Ends\n",__func__);
	return fd;
}
