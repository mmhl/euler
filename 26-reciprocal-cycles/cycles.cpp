/*
 * =====================================================================================
 *
 *       Filename:  cycles.cpp
 *
 *    Description:  26-reciprocal-cycles 
 *
 *        Version:  1.0
 *        Created:  21.11.2013 11:51:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <math.h>

int main(int argc, char *argv[])
{
	int num;
	int n;
	for(int i = 999; i > 1; i--) 
	{
		int num = i;
		for(n = 1; n <= num; n++)
		{
			if((int)(pow(10,n)-1)%num == 0)
			{
				std::cout << "1/" << i << ": " << n << std::endl;
				break;
			}
		}	
	}
}
