#include"header.h"
#include"declaration.h"

int decompression()
{
	int fdr,noc2,ch;
	char * ma;
	printf("%s : Begins\n",__func__);
	//opening key file
	printf("Enter the key-file name:\n");
	fdr = open_file("O_RDONLY");
	noc2=lseek(fdr,0,SEEK_END);//determining the length
	lseek(fdr,0,SEEK_SET);
	ma = (char *) malloc(sizeof(char)*noc2);
	read(fdr,ma,noc2);//fetching the value in ma array
	ch = clen(ma);
	switch(ch)
	{

		case 2:
			decompress2(ma);
			break;
		case 3:
			decompress3(ma);
			break;
		case 4:
			decompress4(ma);
			break;
		case 5:
			decompress5(ma);
			break;
		case 6:
			decompress6(ma);
			break;

	}
	
	close(fdr);
	printf("%s : Ends\n",__func__);
}
