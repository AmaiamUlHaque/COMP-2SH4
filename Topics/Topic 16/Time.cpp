/*
 * Time.cpp 
 *
 *  Created on: Sep 8, 2022
 *      Author: Dr. Scott Chen
 *	Modified by: Dr. Shahrukh Athar on June 18, 2024
 */

#include <iostream>
#include <iomanip>

#include "Time.h"

using namespace std;

// Default Constructor
Time::Time()
{
	hrs = 0;
	mins = 0;
	secs = 0;
}

Time::Time(int h, int m, int s)
{
	// REALLY preliminary error check
    hrs = h % 24;
    mins = m % 60;
    secs = s % 60;
}

void Time::Set(int h, int m, int s)
{
	// REALLY preliminary error check
    hrs = h % 24;
    mins = m % 60;
    secs = s % 60;
}

// Can you figure out the algorithm?
void Time::Increment()
{
	if(++secs % 60 == 0)
	{
		secs = 0;
		if(++mins % 60 == 0)
		{
			mins = 0;
			if(++hrs % 24 == 0)
			{
				hrs = 0;
			}
		}
	}
}

// You should look up how setfill() and setw() work on your own
// This function has been declared Virtual in the Class Declaration
void Time::Write() const
{
	cout << setfill('0') << setw(2) << hrs << ":"
		 << setfill('0') << setw(2) << mins << ":"
		 << setfill('0') << setw(2) << secs;
}
