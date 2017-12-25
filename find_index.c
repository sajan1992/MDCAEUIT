#include "declaration.h"
#include "header.h"

int find_index(char * ma, char c)
{
	int i = strlen(ma);
	int k=0;
	while(i)
	{
		if(*(ma +k) == c)
		{
			return k;
			break;
		}
	k++;	
	i--;
	}


}
