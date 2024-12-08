/*
 * ExtTime.cpp
 *
 *  Created on: Sep 8, 2022
 *      Author: Scott Chen
 */

#include <iostream>
#include "ExtTime.h"

using namespace std;

// Remember, this default constructor will call the base class Time() constructor
//  before executing its own implementation
ExtTime::ExtTime()
{
	zone = EST;
}

// This additional constructor is specified to call the Time(int, int, int) constructor in the base class
//  before executing its own implementation
ExtTime::ExtTime(int h, int m, int s, ZoneType z) : Time(h, m, s)
{
	zone = z;
}

// This version of Set() overrides the inherited Set() function from the base class with a slightly different signature
//  In the implementation, the base class Set() is invoked.
//  NOTE: NOT OVERLOAD!!!
void ExtTime::Set(int h, int m, int s, ZoneType z)
{
	Time::Set(h, m, s);  // Base Class Version
	zone = z;
}

// This version of Write() overrides the inherited Write() function from the base class
//  In the implementation, the base class Write() is invoked
void ExtTime::Write() const
{
	string ZoneStr[8] = {"EST", "CST", "MST", "PST", "EDT", "CDT", "MDT", "PDT"};
	Time::Write();
	cout << ' ' << ZoneStr[zone] << endl;
}
