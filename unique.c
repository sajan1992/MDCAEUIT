#include"header.h"
#include"declaration.h"

int unique(char * ma,char c,int i)
{
	int k=0;
	if(i == 0)
		return 0;
		
	while(i)
	{	
		if(*(ma+k)==c)
			return 1;
		k++;
		i--;
	}
	return 0;
}
