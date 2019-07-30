#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	printf("hello iobuffer");
	printf("hello iobuffer\n");//在这之前的会输出，因为碰到了换行符了
	printf("hello iobuffer");
	printf("hello iobuffer");
	printf("hello iobuffer");
	printf("hello iobuffer");
	printf("hello iobuffer");
	printf("hello iobuffer");
	printf("hello iobuffer");
	printf("hello iobuffer");
	// 这里是不会输出的，因为printf会使用行缓存，而行缓存输出的条件是行缓存满或者碰到换行符号
	while(1)
	{
		sleep(1);	
	}
	return 0;
}
