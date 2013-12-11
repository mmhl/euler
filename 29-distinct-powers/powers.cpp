/*
 * =====================================================================================
 *
 *       Filename:  powers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11.12.2013 14:10:17
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
	int x,n;
	x = n = 4;
	for(int i = 2; i <= 100; i += 2)
	{
		std::cout << std::endl;
		x = n = i;
		while(x >= 2 && n >= 2)
		{
			std::cout << x << "^" << n << "= " << pow(x,n) << std::endl;
			x *= x;
			n = n >> 1;
			if(x > 100 || n > 100)
				break;
		}
	}

	
}

