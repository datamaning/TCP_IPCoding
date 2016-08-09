#include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 30
int main(int argc,char *argv[])
{
	int fds[2],fds1[2];
	char str[]="Who are you";
	char str1[]="Thank you for your message";
	char buf[BUF_SIZE];
	pid_t pid;
	
	pipe(fds);
	pipe(fds1);
	pid=fork();
	if(pid==0)
	{
	write(fds[1],str,sizeof(str));
	read(fds1[0],buf,BUF_SIZE);
	printf("Child proc output%s",buf);
	}
	else{
	read(fds[0],buf,BUF_SIZE);
	printf("Parent proc %s",buf);	
write(fds1[1],str1,sizeof(str1));

	sleep(3);
	}
	return 0;
}
