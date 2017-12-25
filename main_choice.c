#include"header.h"
#include"declaration.h"

int main_choice()
{
	int ch;
	printf("%s : Begins\n",__func__);
	printf("Enter the choice:\n1.Compression\n2.De-Compression\n0.Exit\n");
	scanf("%d",&ch);
	printf("%s : Ends\n",__func__);
	return ch;
}
