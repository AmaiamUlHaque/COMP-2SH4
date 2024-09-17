/*
 * Monom.h
 *
 *  Created on: Sep 8, 2022
 *      Author: Dr. Scott Chen
 *  Modified by: Dr. Shahrukh Athar on June 3, 2024
 */

#ifndef MONOM_H_
#define MONOM_H_

class Monom  // like struct on steroids
{
    // Syntax Protected for Internal Use Only!
    private:
        float coeff;
        int power;

        //Setters
        void SetCoeff( float coe );
        void SetPower( int pow );

    // Syntax Protected for External AND Internal Use
    public:
        // Object Initializers (Overloaded)
        Monom(void); // default
        Monom(float coe, int pow);

        // Getters
        float GetCoeff();
        int GetPower();

        // Other External Interactions
        Monom Product( Monom op );
        Monom Quotient( Monom op );
        void print();
};


#endif /* MONOM_H_ */
