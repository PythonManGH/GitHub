#include<errno.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	char* buffer = "0123456789";

	if(argc != 2){
		fprintf(stderr,"usage: %s srcfile destfile\n",argv[0]);
		exit(1);
	}

	int fin;
	// 打开源文件
	fin = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0777); // 007 文件的权限
	if(fin<0){
		perror("open error\n");
		exit(1);
	}
	
	size_t size = strlen(buffer)*sizeof(char);	
	if(write(fin,buffer,size)!=size)
	{
		perror("write error");
		exit(1);
	}
	
	// 打印当前文件的偏移量
	size_t offset = lseek(fin,0L,SEEK_CUR);
	printf("cur offset:%d\n",offset);
	//
	close(fin);
	return 0;
}

/* 涉及到的知识点
 * perror --> 里面封装的就是stderr
 * off_t lseek(int fd,off_t offset,int whence);
 *           offset--> 要设置的偏移量的值
 *           whence--> 设置是相对文件初始位置还是相对位置
 *					SEEK_SET:将该文件的位移量设置为距文件开始处offset个字节
 *					SEEK_CUR:将该文件的位移量设置为当前值加offset,offset可为正或负
 *					SEEK_END:将文件的位移量设置为文件长度加offset,offset可为正或负
			
*/
