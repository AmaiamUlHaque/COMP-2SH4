//TOPIC 4
//C ARRAYS

//DEFINITION - datatype arrayNAme [elements];
//arrayNAme refers to base address of the array
//if array is int of 4 elements ---> each int needs 4 bytes, so itll look for a spot w/ consecutive 16 bytes of memory

//ACCESS
//arrayName [index] 
//index is an lvalue ie. lvalue = left hand value = the value inside the storage spot. rvalue = right side value = the location in memory


//INITILIASATION
//method 1: intiiliser list - for known values / 0's
//eg. int c[4] = {100,60,30,90}; --> {100,60,30,90}
//eg. int c[4] = {100, 60} --> {100, 60, 0, 0}
//eg. int c[] = {10, 50, 51} --> c[3]
//method 2: for loop - program convineience
//cant a = {5.5, 2.3} since thats trying to change the location in memory
//cant a[3] = {1,2,3,4,5} --> syntax error

//ERRORS - SEGMENTATION FAULT
//c has no boundary checking
//semantic errors - access out of bounds
//c[3] = {100,30,20};
//int a  = c[3]
//wont give runtime error but instead will put whatever garbage is in that spot
//if that spot is "reserved", the OS thinks youre a menance and will yeet the code away



//ARRAYS AND FUNCTIONS
//function cant return an array, only one value
//but arrays can be passed to function and their genuine values will be modified, unlike pass-by-value which only copies values, since the address of array is passed
//which is PASS BY REFERENCE 

//MULTI DIMENSIONAL ARRAYS
// 2D: arrayName [i][j]
// 3D: arrayName [i][j][k]
// # of elements = the product of all the dimensions        eg. 2D=i*j, 3D = i*j*k
// can go thru each element via nested for loops
// can also just go from 0 to total # of elements and itll scale autoamtically
// when passing arrays into functions, the first dimension is not necessary