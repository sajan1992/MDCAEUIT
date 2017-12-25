#include"header.h"
#include"declaration.h"
int compression()
{
	int fd,cl;
	char * ma;
	printf("%s : Begins\n",__func__);
	printf("Enter the file name : \n");
	fd = open_file("O_RDONLY");
	printf("file descriptor recieved : %d\n",fd);
	ma = create_Master_Array(fd);
	printf("Master_Array recieved: %s\n",ma);
	cl = clen(ma);
	printf("Count-length of Master Array: %d\n",cl);
	switch(cl)
	{
		case 2:
			compress2(ma,fd);
			break;
		case 3:
			compress3(ma,fd);
			break;
		case 4:
			compress4(ma,fd);
			break;
		case 5:
			compress5(ma,fd);
			break;
		case 6:
			compress6(ma,fd);
			break;
		case 7:
			compress7();
			break;
		
	}
	printf("%s : Ends\n",__func__);
	close(fd);
}

