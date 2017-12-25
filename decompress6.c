#include"header.h"
#include"declaration.h"

int decompress6(char * ma)
{
	int fd,noc1,i;
	unsigned char ch,c,cc,ccc;
	printf("%s : Begins\n",__func__);
	printf("Master array fetched : %s\n",ma);
	printf("Enter the compressed file-name:\n");
        fd = open_file("O_RDONLY");
        noc1=lseek(fd,0,SEEK_END);
	noc1=noc1-1;
        lseek(fd,0,SEEK_SET);
        printf("compressd file length = %d\n",noc1);
        printf("Compressed data fetched: ");
	while(noc1 > 0)
	{

		read(fd,&ch,1);
		noc1--;
		if(noc1 <0)
			break;
		cc=ch;
		ch >>=2;
		i=ch;
		printf("%c",*(ma+i));
		
		cc <<=6;
		cc >>=2;
		read(fd,&ch,1);
		noc1--;
		if(noc1 <0)
			break;
		ccc=ch;
		ch >>=4;
		cc |=ch;
		i=cc;
		printf("%c",*(ma+i));
		
		ccc <<=4;
		ccc >>=2;
		read(fd,&ch,1);
		noc1--;
		if(noc1 <0)
			break;
		cc=ch;
		ch >>=6;
		ccc |=ch;
		i=ccc;
		printf("%c",*(ma+i));

		cc <<=2;
		cc >>=2;
		i=cc;
		printf("%c",*(ma+i));
				
	}
	printf("\n");
	printf("%s : Ends\n",__func__);
}
