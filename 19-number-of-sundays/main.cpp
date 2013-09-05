/*
 * main.cpp
 *
 *  Created on: 1 wrz 2013
 *      Author: mhl
 */

#include <iostream>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;


int main()
{
	cout << "Start";
	int start_date = 1901;
	int end_date = 2000;
	int current_month = Jan;
	int num_sundays= 0;
	for(int year = start_date; year <= end_date; year++)
	{
		date d;
		while(current_month != NotAMonth)
		{
		first_day_of_the_week_in_month fdm(Sunday, current_month);
		d = fdm.get_date(year);
		if(d.day() == 1)
		{
			cout << d << endl;
			num_sundays++;
		}
		current_month++;
		}
		current_month = Jan;
	}
	cout << num_sundays << endl;

}

