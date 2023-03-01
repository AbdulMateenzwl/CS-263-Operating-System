#include <stdio.h>
#include <dirent.h>
int main(void)
{
	struct dirent *de;
	// opendir() returns a pointer of DIR type.
	DIR *dr = opendir("/home/kali/Lab_3");
	// returns NULL if ther is no such directory or it is unable to open it
	if (dr == NULL) 	{
		printf("There is no such directory.");
		return 0;
	}
	// for readdir()
	while ((de = readdir(dr)) != NULL)
 	{
		printf("%s\n", de->d_name);
	}
	closedir(dr);	
	return 0;
}

