#include"header.h"
#include"declaration.h"

int decompress2(char * ma)
{
	int fd,noc1,i;
	unsigned char ch,c,cc,ccc;
	printf("%s : Begins\n",__func__);
	printf("Master array fetched : %s\n",ma);
	printf("Enter the compressed file-name:\n");
        fd = open_file("O_RDONLY");
        noc1=lseek(fd,0,SEEK_END);
        lseek(fd,0,SEEK_SET);
        printf("compressd file length = %d\n",noc1);
        printf("Compressed data fetched: ");
	while(noc1 > 0)
	{

		read(fd,&ch,1);
		noc1--;
		if(noc1 <0)
			break;
		ccc=cc=c=ch;
		ch >>=6;
		i=ch;
		if(i == 3)
		break;
		printf("%c",*(ma+i));
		
		c <<=2;
		c >>=6;
		i=c;
		if(i == 3)
		break;
		printf("%c",*(ma+i));
		
		cc <<=4;
		cc >>=6;
		i=cc;
		if(i == 3)
		break;
		printf("%c",*(ma+3));

		ccc <<=6;
		ccc >>=6;
		i=ccc;
		if(i == 3)
		break;
		printf("\n%c\n",*(ma+i));

	}
	printf("\n");
	printf("%s : Ends\n",__func__);
}
