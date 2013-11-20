/*
 * main.c
 *
 *  Created on: 23-08-2013
 *      Author: mhl
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>

#define MAX_ARRAY_SIZE 20
#define WINDOW_SIZE 4
#define INPUT_FILE "input.txt"
static unsigned int main_array[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

enum direction {
	ROW,
	COLUMN,
	LEFT_RIGHT_DIAGONAL,
	RIGHT_LEFT_DIAGONAL,
};

struct largest_point
{
	enum direction dir;
	int x; // beginning coordinates of largest product in global array
	int y;
	unsigned int largest_val;
};

/*
 * return largest product in 4x4 window starting at x,y
 */
static unsigned int largest_in_window(int y, int x)
{
	int i,j;
	unsigned int largest = 1;
	unsigned int result_row = 1;
	unsigned int result_column = 1;
	unsigned int result_lr_diag = 1;
	unsigned int result_rl_diag = 1;
	unsigned int window[WINDOW_SIZE][WINDOW_SIZE];
	for(i = 0; i < WINDOW_SIZE; i++)
	{
		for(j = 0; j < WINDOW_SIZE; j++)
		{
			window[i][j] = main_array[y+i][x+j];
		}
	}

	printf("Current window\n");
	for(i = 0; i < WINDOW_SIZE; i++)
	{
		for(j = 0; j < WINDOW_SIZE; j++)
		{
			printf("%2d ", window[i][j]);
		}
		printf("\n");
	}
	result_row = 1;
	for(i = 0; i < WINDOW_SIZE; i++)
	{
		for(j = 0; j < WINDOW_SIZE; j++)
		{
			result_row *= window[i][j];
			result_column *= window[j][i];
		}
//		printf("Line result: %d\n", result_row);
//		printf("Column result: %d\n", result_column);
		if((result_row > result_column ? result_row : result_column) > largest)
			largest = (result_row > result_column ? result_row : result_column);
		result_row = 1;
		result_column = 1;
	}
	/*Now diagonal */
	result_lr_diag = 1;
	result_rl_diag = 1;
	for(i= 0, j = 0; i < WINDOW_SIZE, j < WINDOW_SIZE; i++, j++)
	{
		result_lr_diag *= window[i][j];
	}
//	printf("Left right diagonal is %d\n", result_lr_diag);
	if(result_lr_diag > largest)
				largest = result_lr_diag;

	for(i= WINDOW_SIZE-1, j=0; j < WINDOW_SIZE, i >= 0; j++, i--)
	{
		result_rl_diag *= window[i][j];
	}

//	printf("Right left diagonal is %d\n", result_rl_diag);
	if(result_rl_diag > largest)
		largest = result_rl_diag;

	printf("Largest product in subwindow is %d\n", largest);
	return largest;
}

/*
 * Convert string in file to number in main_array
 */
static int to_array()
{
	int fd;
	int x,y;
	char *token;
	x = y = 0;
	ssize_t rb;
	char buff[2048] = {0};
	void *p;
	fd = open(INPUT_FILE, O_RDONLY);
	if(fd < 0)
	{
		return -1;
	}
	rb = read(fd, buff, 2048);
	token = strtok(buff, " \n"); // First strtok
	main_array[y][x] = strtol(token, NULL, 10);
	x++;
	while((token = strtok(NULL, " \n")) != NULL)
	{
		main_array[y][x] = strtol(token, NULL, 10);
		if(++x == MAX_ARRAY_SIZE)
		{
			y++;
			x = 0;
		}
	}

	int i, j;
	for(i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		for(j = 0; j < MAX_ARRAY_SIZE; j++)
		{
			printf("%2d ", main_array[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int main(int argc, char *argv[])
{
	to_array();
	int i,j;
	unsigned int largest_window;
	unsigned int largest_total = 1;
	for(i = 0; i < 17; i++)
	{
		for(j = 0; j < 17; j++)
		{
			largest_window = largest_in_window(i,j);
			if(largest_window > largest_total)
			{
				largest_total = largest_window;
				printf("New largest product %d in subwindow %d, %d\n", largest_window, i, j);
			}
		}
	}

	printf("%d\n", largest_total);
	return 0;
}
