#include"header.h"
#include"declaration.h"
int main()
{	
	int choice; 
	init();
	printf("%s : Begins\n",__func__);
	while(1)
	{
		choice = main_choice();
		switch(choice)
		{
			case 1:
				printf("Initiating compression....\n");
				compression();
				break;
			case 2:
				printf("Initiating De-compression\n");
				decompression();
				break;
			case 0:
				printf("Exit success...\n");
				printf("%s : Ends\n",__func__);
				return (EXIT_SUCCESS);

		}
	}
	return 0;
}
