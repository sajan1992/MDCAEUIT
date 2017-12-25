#include"header.h"
#include"declaration.h"

int compress2(char * ma, int fd)
{
	if(fd < 0)
	{
		perror("Reading FD Error:\n");
	}
	unsigned char byte,ch,c;
	int i,fdw,fkey,noc;
	printf("Enter the file name to save compress data:\n");
	fdw = open_file("O_WRONLY|O_CREAT");
	if(fdw < 0)
	{
		perror("Writing FD Error");
	}
	noc = lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	printf("%s : Begins\n",__func__);
	while(noc)
	{
		byte ^=byte;
		read(fd,&ch,1);
		noc--;
		if(noc ==0)
		{
			c=0x03;
			c <<=6;
			byte |=c;
			write(fdw,&byte,1);
			goto end;

		}
		i= find_index(ma,ch);
		c=(int)i;
		c <<=6;
		byte |=c;

		read(fd,&ch,1);
		noc--;
		if(noc ==0)
		{
			c=0x03;
			c <<=6;
			c >>=2;
			byte |=c;
			write(fdw,&byte,1);
			goto end;
		}
		i= find_index(ma,ch);
		c=(int)i;
		c <<=6;
		c >>=2;
		byte |=c;
		
		read(fd,&ch,1);
		noc--;
		if(noc ==0)
		{
			c=0x03;
			c <<=6;
			c >>=4;
			byte |=c;
			write(fdw,&byte,1);
			goto end;
		}
		i= find_index(ma,ch);
		c=(int)i;
		c <<=6;
		c >>=4;
		byte |=c;

		read(fd,&ch,1);
		noc--;
		if(noc ==0)
		{
			c=0x03;
			c <<=6;
			c >>=6;
			byte |=c;
			write(fdw,&byte,1);
			goto end;
		}
		i= find_index(ma,ch);
		c=(int)i;
		c <<=6;
		c >>=6;
		byte |=c;

	}

end :  
	    printf("Enter the file-name to store Encrypted key:    \n");
            fkey = open_file("O_WRONLY|O_CREAT");
            write(fkey,ma,strlen(ma));
            printf("%s : Ends\n",__func__);
            close(fkey);
            close(fdw);
 

}
