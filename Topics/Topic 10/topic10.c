

#include <stdio.h>




//ideal for one variable definition
struct {
    float coeff;
    int pow;
} mono0 = {7.5, 2};


//ideal for multiple instances
struct monomial1 {
    float coeff;
    int pow;
};




union {
    int dateNum;
    char dateStr[11];
} myDate;
//since it can only be one of the declared members, initialistion is seperate from declaration

union date {
    int dateNum;
    char dateStr[11];
};





enum {
    LEFT1,
    RIGHT1
} dir;

enum Dir {
    LEFT2,
    RIGHT2
};

typedef struct Monomial1 Mono;



int main (void){

    //STRUCT, UNION, ENUMERATION

        // STRUCT
            //consists of all data types
            //composite variable type
            //components of variables are called members

            //examples
            //a monomial has two parts: float coefficient and int power
            //definition is at top
            struct monomial1 mono1 = {3.2, 5};
            struct monomial1 mono2 = {5.2, 8};

            printf("%f", mono1.coeff); //3.2;
            printf("%d", mono1.pow); //4




        // UNION
            //consists of only one data type
            //a single variable supporting multiple data types
            //info can switch between different data types (ie. float, int, char)
            //honestly dw about this one, we dont go into depths

            //example
            //date can switch between different formats

            myDate.dateNum = 20230901;
            //OR
            Strcpy(myDate.dateStr, "2023-09-01");

            union date date1;
            date1.dateNum = 20230901;
            union date date2;
            strcpy(date2.dateNum, "2023-09-01");

            printf("%s", date1.dateStr); //2023-09-01
            printf("%d", date1.dateNum); //??? --> most likely garbage






        //ENUMERATION
            //collection of constants
            //collection of  int constants w/ functional names
            //mostly used to prevent spamming in programs
            //improves code readability and maintainably

            //example
            dir = LEFT1;
            dir = RIGHT1;

            if(dir == LEFT1); //do some code stuff and make stuff got left
            if (dir == RIGHT1); //go right

            enum Dir myDir;
            myDir = LEFT2;
            myDir = 3; //works but idk



            // FINISHED THE PLVs




    // ROAD TO C++

        // C STRUCTURE

            //alaising using 'typedef'
            //typedef -  creates synonym for previously defined data types for improved readabiltiy 
            
        //ACCESSING MEMBERS
        //the rest of this is on my puter



    


    






    
    
    return 0;
}


