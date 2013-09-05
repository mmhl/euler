#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "./digits"
#define FILE_SIZE 1024



int main()
{
	int fd;
	fd = open(FILE_NAME, O_RDONLY);
	void *buffer;
	int bread;
	if(fd == -1)
	{
		printf("error while opening file\n");
		return -1;
	}
	buffer = calloc(FILE_SIZE, sizeof(char));

	bread= read(fd, buffer, FILE_SIZE);
		
	//TODO: This big_table contains everything, chars digits, newlines, etc
	char *big_table = (char *)buffer;
	int i;
	for(i = 0; i < FILE_SIZE; i++)
	{
		//TODO: Here we filter out digits from the rest.
		//We should put them in the table. 
		if(big_table[i] >= '1' && big_table[i] <= '9')
			printf("%d", big_table[i]-'0');
		else
			printf("%c", big_table[i]);
	}
	printf("\n");
	
}

