#include"io.h"
#include<errno.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	if(argc != 3){
		fprintf(stderr,"usage: %s srcfile destfile\n",argv[0]);
		exit(1);
	}

	int fin,fout;
	// 打开源文件
	fin = open(argv[1],O_RDONLY);
	if(fin<0){
		fprintf(stderr,"open file error:%s\n",strerror(errno));
		exit(1);
	}
	else{
		printf("open file : %d\n",fin);	
	}

	// 打开新文件
	fout = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0777); // 007 文件的权限
	if(fout<0){
		fprintf(stderr,"open file error:%s\n",strerror(errno));
		exit(1);
	}
	else{
		printf("open file : %d\n",fout);	
	}

	// 完成复制功能
	copy(fin,fout);
	close(fin);
	close(fout);
	return 0;
}

/* 涉及到的知识点
	main函数的参数的作用：argc : 参数的个数
		           argv : 具体的参数

	fprintf() --> 可以将信息写到标准输出  
	stderr --> 标准错误输出
	错误处理：strerror --> 将错误码转换成错误信息
	文件打开的权限：	O_WRONLY  O_RDONLY  O_CREAT O_TRUNC			
*/

/*
 * 一个打开的文件所使用的结构体 在内核中的
 * 		文件描述符表--> 里面是一个数组，每个元素都是一个结构体，结构体里面有两个部分，一个是文件描述符标志，一个是文件表项指针
 * 		文件表项-->这是一个结构体，包括以下内容
 * 			文件状态标志-->读写追加同步和非阻塞等状态
 * 			当前文件的偏移量
 * 			i节点表项指针
 * 			引用计数器
 * 		i节点
 * 			文件类型和对该文件的操作函数指针
 * 			当前文件长度
 * 			文件所有者
 * 			文件所在设备，文件访问权限
 * 			指向文件数据在磁盘块上所在位置的指针等
 *
*/
