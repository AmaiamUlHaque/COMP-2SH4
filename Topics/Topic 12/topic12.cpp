//TOPIC 12 - OBJECT ORIENTATED DESIGN



//PLV 12.1 - C Library to C++ Class

    // C library
        //c is procedural language i has no syntax support for classes and objects
        //actually doesnt have classes or objects
        //closest thing is stuff like struct and then dedicating functions to it
        //ie manipulating data structures and dedicating a library to it

    // C++ Class
        // Class - a template (ie a compound data type)
        // Objects / Instances of Class - variables declared under this compound type
        //class:
            //defines new compound data type
            //encapsulates internal behaviours
            //exposes only external interactions
            //strict control over scope
                //accessing private members and functions will cause syntax error unlike in C
            //member functions have strong associativity with its parent class



//PLV 12.2 - C++ Class and UML Class Diagram

    //UML CLASS DIAGRAM

        //basically defines everything of a class
        //like function prototype but even more simplified
            //scope
                //private = -
                //public = +

            //member/function name : data type
                //function's data type = its return type
            //paramters. also in this^ form

            //static members = _ (underline them)
            //constant members = const (add behind data type)


        //format: 
            // +- name : dataType
            // +- name (paramterName : parameterDataType)
            //NOTE: datatype not needed for structors


            //example for Monom Class:
            // - coeff: float
            // - power: int
            // - setCoeff (coe: float): void
            // - setPower (pow: int): void
            // + Monom()
            // + Monom(coe: float, pow: int)
            // + GetCoeff(): float const
            // + GetPower(): int const
            // + Product(op: Monom): Monom
            // + print(): void


    //BASIC CLASS RELATIONSHIPS

        //special blocks used for enumeration, union
        //comments inserted via rectangle dialogue bubble

        //ASSOCIATION - line
            //describes general relationship between classes
            //add ratio number to describe # of instances involved
            //arrow head used if relationship unidirectional

        //AGGREGATION - hollow diamond
            //basically whole-part relation
            //hollow diamond head on the 'whole' class
            //if 'whole' class removed, the 'part' still remains
            //eg. 
                //fruits in a basket
                //fruits are a 'part' of basket
                //once basket removed, fruit doesnt just vanish
        
        //COMPOSITION - solid diamond
            //strong collection relation
            //solid diamond head on the 'collector' class
            //if 'collector' removed, 'property' also removed
            //eg.
                //body class composes of the classes heart, lung, kidney
                //human body composed of 1 heart, 2 lungs, 2 kidneys
                //human passes away, so do the organs
        
        //INHERITANCE - hollow triangle
            //derivation relation
            //hollow arrowhead on 'original' class
            //the classes are 'the same kind of object'
            //original class has basic properties and variations that are passed along to derivees
            //derivees can have additional specialised properties and variations
            //eg.
                //shape is 'parent'
                //circle and rectangle are its 'children'
                //square can even be a 'child' to rectangle




// PLV 12.3 - C++ Object Instantiation

    //Object Instantiation
        
        //upon compilation...
            //member functions and static data is complied
            //data members compiled into struct template
            //all access controls syntactically checked
            // ^ all binary codes stored in 'program' sector

        //upon instantiation...
            //non static data members allocated to 'heap' or 'stack' for every instance
            //member functions invoked from 'program' sector to operate on data members

        //DMA
            //C : malloc() and free()
            //C++ : new and delete




//PLV 12.4 - Make Objects Behave like Primitive Data Types

    //all of the operators can be applied to primitive data types
        // assignment ops: = += -= *= /= %=
        //arithmetic ops: + - * / %
        //logic ops: == != > >= < <= || !
        //etc.

    //in c, most (if not all) complex data types dont support them

    //OPERATOR OVERLOAD
        //allows for operators to be directly used and redefine to how it should behave
        //eg. NOT obj3 = obj1.Multiply(obj2);
        //    THIS INSTEAD: obj3 = obj1*obj2;

        //format to implement...
            //Object operator* (Object const &obj);
            //Object operator/ (Object const &obj);


    //RULE OF SIX (minimum four)
        //certain operators and special member functions MUST BE OVERLOADED to keep memory safe
        //1 constructor
        //2 destructor
        //3 copy contructors
        //4 copy assignment operator
        //5 move constructors
        //6 move assignment operators





//12.0 - OBJECT ORIENTATED DESIGN - CLASS

    //4 PRINCIPLES

        //Encapsulation
            //code and data pertaining to implentation should be hidden from external objects
        
        //Inheritance
            //exisiting definition of a class should be easily and safely reused to derive the definition of another class

        //Polymorphism
            //a base class can be used to mandate many related derived classes to share certain identical behaviours
        
        //Abstraction
            //classes should be designed such that external programmers can focus on how to interact w/ the objects 
            //rather than their implementation


    //TERMINOLOGY
        //class - 
        //object/instance - 
        //field/member variable - to track object states and attributes
        //method/member function - to implement object behavious
        //encapsulation - 
        //message/method invocation - exchange of info between the external interfaces of objects
        //interface - the external-facing methods and fields for facilitating interactions
        //sub/child class - 
        //super/parent/base class -


    //IDK SOMETHING
        //helper functions - private member functions
        //non static data memebrs - each object instantiated gets its own copies
        //static data members - acts as class-levek global var thats shared among all objects of the same class
        //implemenotr - perform operations on data members
    
    //CLASS ACCESS CONTROL
        //private - 
        //public - class interface
        //protected - public members to derived classes only (not part of class interface)
    
    //CONSTRUCTORS
        //to initialise values
        //allows for constructor overload (multiple constructor flavours)

            //default constructor
                //format:
                    // Object();
                    // Object::Object(){ }

            //copy constructor
                //format:
                    // Object(const Object &obj);
                    // Object::Object(const Object &obj) { }

            //others w/ parameters
        

        //c++ supplies...
            //most basic default constructor...that initialises absolutely nothing.
            //basic copy constructor...that shallow copies (both objs point to same place in memory)
            //NOTE: if you supplied only constructors w/ parameters, c++ wont supply a default constructor (copy one still supplied)


    //DESTRUCTORS
        //must remove off the heap
        //automatically called at the very end of program to deallocate if constructor was called
        //format:
            // ~Object();
            // Object::~Object() { }

    
    //ASSIGNMENT OPERATOR
        //so = sign can be used between objects
        //
        //format:
            // Object& operator=(const Object& other);
            // Object::Object& operator=(const Object& other) { }


    //CLASS MODULARIZATION
        //header file (.h) has...
            //class declaration (c struct and funtion prototypes)
            //required libraries
            //same name as class
        //source file(.cpp) has...
            //class implementation (function definitions, static data member inti, etc)
            //required libraries
            //same name as class
        //main file
            //#include required header file to use the class features
    
        