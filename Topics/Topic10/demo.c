#include <stdio.h>


    typedef struct{
        float coeff;
        int power;
    } Monom;

    void printMonom (Monom* thisMonom){
        printf("Monomial is: %.2fx^%d\n", (*thisMonom).coeff, thisMonom ->power);
    }

    Monom* allocateMonomArray(int size){
        Monom* mPtr;
        mPtr = (Monom*)malloc(size*sizeof(Monom));
        return mPtr;
    }

    void deallocateMonomArray (Monom* target){
        free(target);
    }

    initMonom(Monom* thisMonom, float c, int p){

        thisMonom ->coeff = c;
        thisMonom ->power = p;

    }

    void addMonom (Monom* op1, const Monom* op2){
        if (op1 ->power != op2 -> power){
            printf("power of monomials must be the same. addition failed");
        }
        else {
            op1->coeff += op2 ->coeff;
        }
    }


int main (void){

    Monom mono1 = {3.2, 4};
    printMonom(&mono1);

    Monom* myMonomArray = allocateMonomArray(5);

    int i;
    for (i=0; i<5; i++){
        initMonom((&myMonomArray), 1.5*(i+1), (i+2));
    }

    for (i=0; i<5; i++){
        printMonom(&myMonomArray[i]);
    }

    addMonom(&myMonomArray[1], &myMonomArray[2]);
    addMonom(&myMonomArray[1], &mono1);




    deallocateMonomArray(myMonomArray);
    
    return 0;
}