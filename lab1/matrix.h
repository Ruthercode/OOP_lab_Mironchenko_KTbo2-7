
#ifndef MATRIX_H
#define MATRIX_H
#include <istream>
#include <ostream>


class Matrix
{
    private:
        int _colsLen, _rowsLen;
        double** _A;

        double** _buildMatrix(const int& n, const int& m);
        void _destroyMatrix(double** matrix, const int& n);

    public:
        Matrix();
        Matrix(const int& n, const int& m);

        bool isEmpty() const;

        int getColsLen() const;
        int getRowsLen() const;
        double& matrixField(const int& i, const int& j);
        
        void matrixSum(const Matrix& term);
        void matrixMul(const Matrix& factor);
        void matrixTransposition();

        friend std::istream& operator>>(std::istream& in, const Matrix& object);
        friend std::ostream& operator<<(std::ostream& out, const Matrix& object);

        ~Matrix();
};

#endif 