#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	int m= getppid();
	
	printf("Hello World\n");
	printf("%d",m);
	printf("\n");
	return 0;
}
