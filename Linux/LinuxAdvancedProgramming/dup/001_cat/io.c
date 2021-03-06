#include"io.h"
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

#define BUFFER_LEN 1024

void copy(int fdin,int fdout)
{
	char buffer[BUFFER_LEN];
	ssize_t size;
	while((size=read(fdin,buffer,BUFFER_LEN))>0){
		if(write(fdout,buffer,size)!=size){
			fprintf(stderr,"write error:%s\n",strerror(errno));
			exit(1);
		}	
	}

	if(size < 0){
		fprintf(stderr,"write error:%s\n",strerror(errno));
		exit(1);
	}
}
