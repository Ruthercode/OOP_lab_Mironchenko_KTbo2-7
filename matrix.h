
#ifndef MATRIX_H
#define MATRIX_H
#include <istream>
#include <ostream>


class Matrix
{
    int _colsLen, _rowsLen;
    double** _A;

    double** _buildMatrix(int, int);
    void _destroyMatrix(double** , int);

    public:
        Matrix();
        Matrix(int, int);

        int getColsLen() const;
        int getRowsLen() const;
        double& matrixField(int i, int j);
        
        void matrixSum(const Matrix&);
        void matrixMul(const Matrix&);
        void matrixTransposition();

        friend std::istream& operator>>(std::istream&, const Matrix&);
        friend std::ostream& operator<<(std::ostream&, const Matrix&);

        ~Matrix();
};

#endif 