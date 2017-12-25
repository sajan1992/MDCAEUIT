#include"header.h"
#include"declaration.h"

int compress4(char * ma,int fd)
{
	unsigned char byte,ch,c;
	int i,fdw,fkey;
	int noc;
	printf("Enter the file name to save compress data:\n");
	fdw = open_file("O_WRONLY|O_CREAT");
	
	noc = lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	printf("%s : Begins\n",__func__);
	while(noc)
	{
		byte ^= byte;
		read(fd,&ch,1);
		i = find_index(ma,ch);
		c =(int)i;
		//sprintf(&c,"%d",i);
		c <<= 4;
		byte |= c;
		noc --;

		if(noc == 0)
		{
			c = 0x0f;
			byte |= c;
			write(fdw,&byte,1);
			goto end;

		}
		//reading next character from here
		read(fd,&ch,1);
		i= find_index(ma,ch);
		//printf("i= %d-->\n",i);
		//sprintf(&c,"%d",i);
		c =(int)i;
		c <<=4;
		c >>= 4;
		byte |=c;
		write(fdw,&byte,1);
		noc --;
	}

end :
	printf("Enter the file-name to store Encrypted key:\n");
	fkey = open_file("O_WRONLY|O_CREAT");
	write(fkey,ma,strlen(ma));
	printf("%s : Ends\n",__func__);
	close(fkey);
	close(fdw);
}
