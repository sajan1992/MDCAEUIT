#include"header.h"
#include"declaration.h"

int compress5(char * ma,int fd)
{
	unsigned char byte,ch,c,cc;
	int i,fdw,fkey;
	int noc;
	printf("Enter the file name to save compress data:\n");
	fdw = open_file("O_WRONLY|O_CREAT");
	
	noc = lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	printf("%s : Begins\n",__func__);
	/*while(noc)
	{
		read(fd,&ch,1);
		printf("%d --> %c\n",(int)ch,ch);
		noc--;


	}*/
	while(noc)
	{
		byte ^= byte;

		read(fd,&ch,1);
		noc--;
		if(noc == 0)
		{
			c=0x1f;
			c <<=3;
			byte |=c;
			write(fdw,&byte,1);
			goto end;
		}
		i = find_index(ma,ch);
		c =(int)i;
		c <<= 3;
		byte |= c;

	/*	if(noc == 0)
		{
			c = 0x0f;
			byte |= c;
			write(fdw,&byte,1);
			goto end;

		}*/
		//reading next character from here
		read(fd,&ch,1);
		noc--;
		if(noc == 0)
		{
			c=0x1f;
			c <<=3;
			c >>=5;
			byte |=c;
			write(fdw,&byte,1);
			byte ^=byte;
			c=0x1f;
			c <<=6;
			byte |=c;
			write(fdw,&byte,1);
			goto end;
		}
		i= find_index(ma,ch);
		cc=c =(int)i;
		c <<=3;
		c >>=5;
		byte |=c;
		write(fdw,&byte,1);

		//reading next character from here
		
		byte ^=byte;
		cc <<=6;
		byte |=cc;
		read(fd,&ch,1);
		noc--;
		if(noc == 0)
		{
			c=0x1f;
			c <<=3;
			c >>=2;
			byte |=c;
			write(fdw,&byte,1);
			goto end;
		
		}
		i= find_index(ma,ch);
		c=(int)i;
		c <<=3;
		c >>=2;
		byte |=c;

		read(fd,&ch,1);
		noc--;
		if(noc == 0)
		{
			c=0x1f;
			c <<=3;
			c >>=7;
			byte |=c;
			write(fdw,&byte,1);
			byte ^=byte;
			c=0x1f;
			c <<=4;
			byte |=c;
			write(fdw,&byte,1);
			goto end;

		}
		i= find_index(ma,ch);
		cc=c=(int)i;
		c <<=3;
		c >>=7;
		byte |=c;
		write(fdw,&byte,1);
		
		byte ^=byte;
		cc <<=4;
		byte |=cc;
		read(fd,&ch,1);
		noc--;
		if(noc == 0)
		{
			c=0x1f;
			c <<=3;
			c >>=4;
			byte |=c;
			write(fdw,&byte,1);
			byte ^=byte;
			c=0x1f;
			c <<=7;
			byte |=c;
			write(fdw,&byte,1);
			goto end;

		}
		i= find_index(ma,ch);
		cc=c=(int)i;
		c <<=3;
		c >>=4;
		byte |=c;
		write(fdw,&byte,1);

		byte ^=byte;
		cc <<=7;
		byte |=cc;
		read(fd,&ch,1);
		noc--;
		if(noc == 0)
		{
			c=0x1f;
			c <<=3;
			c >>=1;
			byte |=c;
			write(fdw,&byte,1);

		}
		i= find_index(ma,ch);
		c=(int)i;
		c <<=3;
		c >>=1;
		byte |=c;

		read(fd,&ch,1);
		noc--;
		if(noc == 0)
		{
			c=0x1f;
			c <<=3;
			c >>=6;
			byte |=c;
			write(fdw,&byte,1);
			byte ^=byte;
			c=0x1f;
			c <<=5;
			byte |=c;
			write(fdw,&byte,1);
			goto end;
		}
		i= find_index(ma,ch);
		cc=c=(int)i;
		c <<=3;
		c >>=6;
		byte |=c;
		write(fdw,&byte,1);
		
		byte ^=byte;
		cc <<=5;
		byte |=cc;
		read(fd,&ch,1);
		noc--;
		if(noc == 0)
		{
			c=0x1f;
			c <<=3;
			c >>=3;
			byte |=c;
			write(fdw,&byte,1);
			goto end;
		}
		i= find_index(ma,ch);
		c=(int)i;
		c <<=3;
		c >>=3;
		byte |=c;
		write(fdw,&byte,1);

	}

end :
	printf("Enter the file-name to store Encrypted key:\n");
	fkey = open_file("O_WRONLY|O_CREAT");
	write(fkey,ma,strlen(ma));
	printf("%s : Ends\n",__func__);
	close(fkey);
	close(fdw);
}
