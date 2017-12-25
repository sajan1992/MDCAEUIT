#include"header.h"
#include"declaration.h"

int decompress5(char * ma)
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
		ch >>=3;
		i=ch;
		printf("%c",*(ma+i));
		
		cc <<=5;
		cc >>=3;
		read(fd,&ch,1);
		noc1--;
		if(noc1 <0)
			break;
		ccc=ch;
		ch >>=6;
		cc |=ch;
		i=cc;
		printf("%c",*(ma+i));
		
		cc=ccc;
		ccc <<=2;
		ccc >>=3;
		i=ccc;
		printf("%c",*(ma+i));
		
		cc <<=7;
		cc >>=3;
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
		ccc >>=3;
		read(fd,&ch,1);
		noc1--;
		if(noc1 <0)
			break;
		cc=ch;
		ch >>=7;

		ccc |=ch;
		i=ccc;
		printf("%c",*(ma+i));
		
		ccc=cc;
		cc <<=1;
		cc >>=3;
		i=cc;
		printf("%c",*(ma+i));

		ccc <<=6;
		ccc >>=3;
		read(fd,&ch,1);
		noc1--;
		if(noc1 <0)
			break;
		cc=ch;
		ch >>=5;
		ccc |=ch;
		i=ccc;
		printf("%c",*(ma+i));

		cc <<=3;
		cc >>=3;
		i=cc;
		printf("%c",*(ma+i));
	}
	printf("\n");
	printf("%s : Ends\n",__func__);
}
