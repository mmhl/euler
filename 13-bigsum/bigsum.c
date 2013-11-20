/*
 * =====================================================================================
 *
 *       Filename:  bigsum.c
 *
 *    Description:  Bigsum Euler problem no. 13
 *
 *        Version:  1.0
 *        Created:  28.06.2013 10:11:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	mpz_t sum, x;
	int flag, fd;
	char buffer[52] = {0,};  // Buffer for number
	ssize_t bytes;

	/* Init mpz_t bignumber */
	mpz_init(sum);
	mpz_init(x);
	mpz_set_ui(sum, 0);
	mpz_set_ui(x, 0);

	fd = open("input.txt", O_RDONLY);
	if(fd < 0)
	{
		printf("Error while opening the file\n");
		return -1;
	}

	while((bytes = read(fd, buffer, 51)) > 0) // plus \n
	{
		mpz_set_str(x, buffer, 10);
		mpz_add(sum, sum, x);
	}

	printf("\n");
	mpz_out_str(stdout,10, sum);
	printf("\n");
	

	return 0;
}
