#include"header.h"
#include"declaration.h"

int decompress4(char * ma)
{
	int fd,noc1,i;
	unsigned char ch,c;
	printf("%s : Begins\n",__func__);
	printf("Master array fetched: %s\n",ma);

	//now opening compressed file
	printf("Enter the compressed file-name:\n");
	fd = open_file("O_RDONLY");
	noc1=lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	printf("compressd file length = %d\n",noc1);
	printf("Compressed data fetched: ");
	
	//fetching data from the compressed file
	while(noc1)
	{
		read(fd,&ch,1);
		c=ch;
		c >>= 4;
		i=(int)c;
		printf("%c",*(ma+i));
		ch <<=4;
		ch >>=4;
		i=(int)ch;
		printf("%c",*(ma+i));
		noc1--;

	}
	printf("\n");
	close(fd);
	printf("%s : Ends\n",__func__);
}
