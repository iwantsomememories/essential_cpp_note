#include <vector>
#include <iostream>

using namespace std;

typedef float elemType; 
class Matrix{
    friend Matrix operator+(const Matrix&, const Matrix&);
    friend Matrix operator*(const Matrix&, const Matrix&);

    public:
        Matrix(elemType=0.,elemType=0.,elemType=0.,elemType=0.,
            elemType=0.,elemType=0.,elemType=0.,elemType=0.,
            elemType=0.,elemType=0.,elemType=0.,elemType=0.,
            elemType=0.,elemType=0.,elemType=0.,elemType=0. );
        
        Matrix(const elemType*);

        ostream& print(ostream&) const;

        Matrix& operator+=(const Matrix&);

        elemType& operator() (int row, int column);
        elemType operator() (int row, int column) const;
    
    private:
        elemType _matrix[4][4];
};

inline ostream& operator<<( ostream& os, const Matrix &m )
       { return m.print( os ); }

int main(int argc, char const *argv[])
{
    Matrix m;
    cout << "m: " << endl;
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << m(i, j) << ' ';
    //     }
    //     cout << endl;
    // }

    cout << m << endl;
    // m.print(cout);
    

	elemType ar[16]={
		1., 0., 0., 0., 0., 1., 0., 0.,
		0., 0., 1., 0., 0., 0., 0., 1. };

	Matrix identity( ar );
    cout << "identity: " << endl;
	cout << identity << endl;

	// guarantee default memberwise copy works correctly
	// Matrix m2( identity );
	// m = identity;

	// cout << m2 << endl; cout << m  << endl;

	elemType ar2[16]={
		1.3f, 0.4f, 2.6f, 8.2f, 6.2f, 1.7f, 1.3f, 8.3f,
		4.2f, 7.4f, 2.7f, 1.9f, 6.3f, 8.1f, 5.6f, 6.6f };

	Matrix m3( ar2 );
	cout << m3 << endl;

	Matrix m4 = m3 * identity;
	cout << m4 << endl;

	Matrix m5 = m3 + m4;
	cout << m5 << endl;

	m3 += m4;
	cout << m3 << endl;
    return 0;
}

Matrix operator+(const Matrix &m1, const Matrix &m2){
    Matrix res;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res(i, j) = m1(i, j) + m2(i, j);
        }    
    }
    
    return res;
}

Matrix operator*(const Matrix& m1, const Matrix& m2){
    Matrix res;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                res(i, j) += m1(i, k)*m2(k, j);
            }
        }    
    }
    return res;
}

Matrix::Matrix(elemType a11, elemType a12, elemType a13, elemType a14,
        elemType a21, elemType a22, elemType a23, elemType a24,
        elemType a31, elemType a32, elemType a33, elemType a34,
        elemType a41, elemType a42, elemType a43, elemType a44 )
{
   _matrix[0][0] = a11; _matrix[0][1] = a12;
   _matrix[0][2] = a13; _matrix[0][3] = a14;
   _matrix[1][0] = a21; _matrix[1][1] = a22;
   _matrix[1][2] = a23; _matrix[1][3] = a24;
   _matrix[2][0] = a31; _matrix[2][1] = a32;
   _matrix[2][2] = a33; _matrix[2][3] = a34;
   _matrix[3][0] = a41; _matrix[3][1] = a42;
   _matrix[3][2] = a43; _matrix[3][3] = a44;
}

Matrix::Matrix(const elemType *array){
    int array_index = 0;
    for ( int ix = 0; ix < 4; ++ix )
          for ( int jx = 0; jx < 4; ++jx )
                _matrix[ix][jx] = array[array_index++];
}

ostream& Matrix::print(ostream &os) const {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            os << _matrix[i][j] << ' ';
        }
        os << endl;    
    }
    return os;
}

Matrix& Matrix::operator+=(const Matrix& m){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            (*this)(i, j) += m(i, j);
        }    
    }

    return *this;
}

inline elemType& Matrix::operator() (int row, int column){
    return _matrix[row][column];
}

inline elemType Matrix::operator() (int row, int column) const{
    return _matrix[row][column];
}
