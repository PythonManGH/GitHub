#include"io.h"
#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int fd_in = STDIN_FILENO;
	int fd_out = STDOUT_FILENO;
	// STDIN_FILENO --> 是unistd.h头文件中的宏，其值是0，表示的是标准输入
	// STDOUT_FILENO --> 是unistd.h头文件中的宏，其值是1，表示的是标准输出
	
	int i = 1;
	for(i;i<argc;i++)
	{
		fd_in = open(argv[1],O_RDONLY);
		if(fd_in < 0){
			perror("wenjianduqucuowu\n");
			continue;
		}

		copy(fd_in,fd_out);
		close(fd_in);
	}

	if(argc == 1){
		copy(fd_in,fd_out);	
	}

	return 0;
}

/*
*/
