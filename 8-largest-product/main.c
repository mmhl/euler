/*
 * main.c
 *
 *  Created on: 15-06-2013
 *      Author: mhl
 */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define FILE_NAME "./input"
#define FILE_SIZE 1024
#define DIGITS_NUM 1000
#define ROWS 20
#define COLUMNS 50
#define NUMBERS_TO_MULTIPLY 5
#define THREADS 2

static int multiply5(int table[ROWS][COLUMNS], int row, int column)
{
	int *pointer;
	int result = 1;
	int i;
	pointer = &table[row][column];
	for(i = 0; i < 5; i++)
	{
		result *= *pointer;
		pointer++;
	}
	return result;
}

int main()
{
	int fd;
	int largest = 0;
	//Big table for holding all the digits
	int big_table[ROWS][COLUMNS];
	char *buffer = (char*)malloc(FILE_SIZE*sizeof(int));
	pthread_t threads[THREADS];
	if((fd = open(FILE_NAME, O_RDONLY)) == -1)
	{
		printf("Error while opening the file\n");
		return -1;
	}

	read(fd, buffer, FILE_SIZE);
	int i;
	int row, column;
	row = column = 0;
	for(i = 0; i < FILE_SIZE; i++)
	{
		char c = buffer[i];
		if(c >= '0' && c <= '9')
		{
			big_table[row][column] = c -'0'; // char to int
			column++;
		}
		if(c == '\n') // new row
		{
			row++;
			column = 0;
		}
	}

	int j;
	for(i=0; i < ROWS; i++)
	{
		for(j= 0; j < COLUMNS; j++)
		{
			if(j <= 45)
			{
				int result;
				if((result = multiply5(big_table, i, j)) > largest)
				{
					largest = result;
				}
			}
		}
	}

	printf("%d", largest);
	printf("\n");

}
