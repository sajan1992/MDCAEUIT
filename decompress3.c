#include"header.h"
#include"declaration.h"

int decompress3(char * ma)
{
	int fd,noc1,i,len;
	unsigned char ch,c,cc,ccc;
	printf("%s : Begins\n",__func__);
	printf("Master array fetched : %s\n",ma);
	len = strlen(ma);
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
		ccc=cc=ch;
		ch >>=5;
		i=ch;
		printf("%c",*(ma+i));
		
		cc <<=3;
		cc >>=5;
		i=cc;
		printf("%c",*(ma+i));
		
		ccc <<=6;
		ccc >>=5;
		read(fd,&ch,1);
		noc1--;
		if(noc1 <0)
			break;
		cc=ch;
		ch >>=7;
		ccc |=ch;
		i=ccc;
		printf("%c",*(ma+i));

		ccc=ch=cc;
		cc <<=1;
		cc >>=5;
		i=cc;
		printf("%c",*(ma+i));

		ch <<=4;
		ch >>=5;
		i=ch;
		printf("%c",*(ma+i));

		ccc <<=7;
		ccc >>=5;
		read(fd,&ch,1);
		noc1--;
		if(noc1 <0)
			break;
		cc=ch;
		ch >>=6;
		ccc |=ch;
		i=ccc;
		printf("%c",*(ma+i));
		
		ccc=cc;
		cc <<=2;
		cc >>=5;
		i=cc;
		printf("%c",*(ma+i));

		ccc <<=5;
		ccc >>=5;
		i=ccc;
		printf("%c",*(ma+i));

	}
	printf("\n");
	printf("%s : Ends\n",__func__);
}
