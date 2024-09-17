/*
 * Time.h 
 *
 *  Created on: Sep 8, 2022
 *      Author: Scott Chen
 */

#ifndef TIME_H_
#define TIME_H_

class Time
{
	protected:
		int hrs, mins, secs;

	public:

		// Constructors
		Time();
		Time(int h, int m, int s);
		virtual ~Time(){}; // Declare virtual for polymorphic design

		void Set(int h, int m, int s);
		void Increment();
		virtual void Write() const; // Declare virtual for polymorphic design
};


#endif /* TIME_H_ */
