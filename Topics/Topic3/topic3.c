//TOPIC 3


int main (void){

    // C THEORIES

    // VARIABLES AND DATA TYPES
    // memory bucket - holds value that may change thru out program runtime
    // naming rules:
    // - squecne of letters,digits, underscores, doesnt begin w/ digit
    // - max 31 char length
    // -c naming convention: words_sperated_by_this
    //         camel form: variableInCamelForm

    // PRIMITIVE DATA TYPES ----------------------------------------------------------------------------------------------------
    // COUNTING -    int         16 / 32 bit (implentation/hardware dependant)
    //               short int   +16 bits <= int
    //               long int    +32 bits >= int
    // MEASURING -   float       32 / 64 bit         single precision floating point number
    //               double      x2 float            double precision
    // DISPLAYING -  char        1 byte = 8 bits     ASCII 
    // SIGNED -                                      applies to char,int,short,long
    //               unsigned    only + nums         w/ storage size b-bits (value range = [0, 2^b -1])
    //               signed      both +- nums        w/ storage size b-bits (value range = [-2^(b-1), 2^(b-1) -1])


    //FLOATING POINT NUMBERS ----------------------------------------------------------------------------------------------------
    //follows the IEEE 754 standard - they are only APPROXIMATIONS, so check for range instead of equality
    //NUM = Signed: +-bit, Exponent: 8 bits, Mantissa: 23 bits (base)
    //float = 32 bit  --> range: +-3.4 E38  --> precision: 6 decimal digits
    //double = 64 bit --> range: +-1.7 E308 --> precision: 15 decimal digits

    //SPECIFY DATA SIZE FOR CONSTANTS ----------------------------------------------------------------------------------------------------
    //integer nums defaulted as int: 
    //          l/L = long
    //          u/U = unsigned
    //          ul/UL = unsigned long
    //floating pts defaulted as double: 
    //          f/F = float
    //          l/L = long double

    //CHARACTERS ----------------------------------------------------------------------------------------------------
    //signed [-128,127]
    //unsigned [0,255]
    //acsii [0,127]
    printf("%c", 'a'); //prints a
    printf("%d", 'a'); //prints 97

    //TYPE CONVERSIONS ----------------------------------------------------------------------------------------------------
    //auto converts primitive data types to the wider type
    //char --> i forgot
    //eg. 12 / 5.0f = 12.0 / 5.0 = 2.4
    //eg. 10.0 + 1/2 = 10.0 + 0 = 10.0 + 0.0 = 10.0



    //ARITHMETIC OPERATOR ----------------------------------------------------------------------------------------------------

    //BINARY OPERATOR: = + - * / %
    //note: int / int = int --> 5/2 = 2
    //for -ints for %, depends on implementation

    //UNARY OPERATOR: -, ++, --
    //makes value negative num (opposite of absolute value)
    //PRE(IN/DE)CREMENT - in/decrements var's value before evals expression
    //POST(IN/DE)CREMENT - in/decrements var's value after evals expression

    //PRECEDENCE AND ASSOCIATIVITY: unary > binary: * > / > % > + > -
    //BASIC ASSIGNMENT: x = x + 3
    //COMPUND ASSIGNMENT: x += 3        can also += -= *= /= %=

    //RELATIONAL & EQUALITY OPERATORS: for comparing primitive values (not strings).
    //no boolean in C, so outputs int (either 0=false or 1=true)
    int a = 6;
    a >= 2; //relational
    a % 2 == 0; //equality

    //LOGICAL OPERATORS: && || !

    //TERNARY - ?:
    //single line if-else stamtemnet
    //condition? expressionTrue : expressionFalse;



    //C CONTROL STRUCTURES ----------------------------------------------------------------------------------------------------

    //EXPLICIT TYPE CONVERSION - aka casting
    //enforces data type conversion
    //same level of precendence as unary op. ie. higher than binary operator
    int a = 17;
    double m;
    m = a / 3; // = 17/3 = 5
    m = (double)a / 3;  // = 17.0 / 3 = 17.0 / 3.0 = 5.66666....


    //SELECTION - IF / ELSE ----------------------------------------------------------------------------------------------------
    int condition1 = 5<3;
    int condition2 = 5>3;

    if (condition1){
        printf();
        printf();
        }
    else {
        printf("");
        printf();
    }

    //can omit {} only if there is only one statement right after if / else
    if (condition1)
        printf();
    else
        printf();

    //nested 
    //also an enitre if-else thingy is considered ONE STATEMENT, thats why there no {} for the unnested else
    int num;
    if (condition1) 
        printf("");
    else 
        if(condition2)
            num=5;
        else
            num=2;


    //dangling else - the else is associated with the most recent if, not the top if
    if (condition1)
        printf();
    else if (condition2)
        printf();
    else
        printf();



    //SWITCH CASE ----------------------------------------------------------------------------------------------------
    //only for int-based logic
    //if no break, every single case after the first true one will run even if not true
    //default is like the else of an if-else
    int expression = 5; //can also be 'a';
    switch(expression){

        case (2):
            printf();
            break;
        case (3):
            printf();
            break;
        case (5):
            printf();
            break;
        case (8):
            printf();
            break;
        default:
            printf();
            break;

    //good example of when to use not breaks
    
    int grade = 'A';
    switch (grade){
        case ('A'):
            printf("excellent work");
        case ('B'):
            printf("well done");
            break;
        case ('C'):
            printf("you can do better");
        case ('D'):
            printf("invest more time");
            break;   
    }


    //REPITITION----------------------------------------------------------------------------------------------------
    
    //BREAK VS CONTINUE
    //break stop a loop, even if in an if/else, only the innermost loop tho
    //continue: any statement after this will be skipped and the loop will go to the next iteration
    
    //FOR
    //counting controlled
    
    //WHILE
    //condition controlled
    int x = 2;
    while (x!=5)
        x++;
    }
    
    //DO WHILE
    //garaunteed exectuion. ie, goes thru code at least once
    int y=0;
    do {
        print("%d", y);
        y++;
    } while ( y!=5);





    // SYNC AND ASYNC IO ----------------------------------------------------------------------------------------------------

    //CONSOLE INPUT AND OUTPUT
    //examples
    //printf, scanf, putchar (outputs a single char),getchar (reads a single char input)

    //printf (formatControlString, argumentList);
    //number of expressions must match number of arguments

    //scanf (formatControlString, argumentList);
    //eg. scanf("%d%lf%c%c", &v1, &v2, &v3, &v4);
    //numerical conversion specificiers are read upto the first whitespace
    //eg. input -576 20.5 gf --> v1 = -576, v2 = 20.5, v3 = ' ', v4 = 'g'







    return 0;
}