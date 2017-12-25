#include"header.h"
#include"declaration.h"

int count_length(char * ma)
{
	double i=0;
	double len = strlen(ma);
	while(1)
	{
		if(pow(2,i)>len)
		{
			return i;
			break;
		}
		i++;

	}


}
