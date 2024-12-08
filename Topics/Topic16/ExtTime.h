/*
 * ExtTime.h 
 *
 *  Created on: Sep 8, 2022
 *      Author: Scott Chen
 */

#ifndef EXTTIME_H_
#define EXTTIME_H_

#include "Time.h"

enum ZoneType {EST, CST, MST, PST, EDT, CDT, MDT, PDT};

class ExtTime : public Time
{
	private:
		ZoneType zone;

	public:

		// Constructors
		ExtTime();
		ExtTime(int h, int m, int s, ZoneType z);
		virtual ~ExtTime(){}; // Declare virtual for polymorphic design

		void Set(int h, int m, int s, ZoneType z); // Override
		void Write() const; // Override
};


#endif /* EXTTIME_H_ */
