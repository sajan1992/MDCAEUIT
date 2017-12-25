#include"header.h"
#include"declaration.h"

char * create_Master_Array(int fd)
{
	int size,i;
	char * ma;
	char c;
	printf("%s : Begins\n",__func__);
	size = lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	ma = NULL;
	i=0;
	while(size)
	{	
		read(fd,&c,1);
		if(unique(ma,c,i) == 0)
		{	
			ma = realloc(ma,i+1);
			*(ma+i) = c;
			i++;	
		}
		size--;
	}
	ma = realloc(ma,i+1);
	*(ma+i)='\0';
	printf("%s : Ends\n",__func__);
	return ma;

}
