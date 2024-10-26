
#include <string>
using namespace std;

class Matrix {

	private:

		// Stack Data Members
		int    rowsNum;
		int    colsNum;

		// Heap Data Members - Do you need to release them?  Where, when, and how?
		int    **matrixData;
	

	public:

		//STRUCTORS
		// Default Constructor
		Matrix();		

		// Additional Constructors
		Matrix( int row, int col );
		Matrix( int row, int col, int **table );

		// minimum of 4
		~Matrix();
		Matrix(const Matrix &sMatrix);
		Matrix& operator=(const Matrix &sMatrix);

		
		//MEMBERS
		// Getters
		int getElement(int i, int j);
		int getsizeofrows();
		int getsizeofcols();

		// Setters
		bool setElement(int x, int i, int j);

		// Other Member Functions
		Matrix copy();						// Create a Copy of This Matrix
		void addTo(Matrix m);				// Add Matrix m to this matrix
		Matrix subMatrix(int i, int j);     // Obtain the upper-left submatrix of this matrix
		string toString();					// String Conversion Method
};
