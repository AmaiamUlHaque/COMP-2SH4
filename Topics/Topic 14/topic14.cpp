//TOPIC 14 - OOD INHERITANCE


int main (void){

    //PLV 14.1

    //protected (#) = public to class and subclasses, but private all elsewhere

    //advantages
        //override - allows reimplementation
        //abstract class - allows creation of incomplete class templates
            //more info coming in polymorphism
    

    //COMPOSITION: class WholeClass {private: PartClass* partClassObj} //whole class now has an instance of the part class
    //INHERITANCE: class SubClass : access-level BaseClass { }
            //acess level - controls scope of inherited members from base class

    //SCOPE OF MEMBERS
        
        //Inheritance scope
            //all common members will be inheritied, just different scope accesses
                //except class-specifc members
                    //constructor, destructor,operator ovveride, etc
        
        //PUBLIC INHERITANCE ACCESS
            //derived class inherits...
                //public --> public
                //protected --> protected
                //private is NOT inherited
        
        //PROTECTED INHERITED ACCESS
            //derived class inherits...
                //public --> protected
                //protected --> protected
                //private NOT inherited

         //PRIVATE INHERITED ACCESS
            //derived class inherits...
                //public --> private
                //protected --> private
                //private NOT inherited


    return 0;
}

class Polygon {
    protected:
        int vertices;
        float *xCoord, *yCoord;
    public:
        void set(float *x, float *y, int vert);
};

class Rectangle : public Polygon {
    public:
        float getArea();
};

//EQUIVALENT to Rectangle
class Rect {
    protected:
        int vertices;
        float *xCoord, *yCoord;
    public:
        void set(float *x, float *y, int vert);
        float getArea();
};
