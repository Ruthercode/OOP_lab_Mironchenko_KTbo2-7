#include <istream>
#include <ostream>
#include "matrix.h"

double** Matrix::_buildMatrix(int n, int m)
{
    double** array = new double*[n];

    for (int i = 0; i < n; ++i)
    {
        array[i] = new double[m];

        for (int j = 0; j < m; ++j)
        {
            array[i][j] = 0;
        }
    }

    return array;
}

void Matrix::_destroyMatrix(double** matrix, int n)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }

    if (matrix != nullptr)
    {
        delete[] matrix;
    }
}

Matrix::Matrix()  
{
    _colsLen = 0;
    _rowsLen = 0;
    _A = nullptr;
}

Matrix::Matrix(int n, int m)
{
    _colsLen = n;
    _rowsLen = m;
    _A = _buildMatrix(n,m);
}

int Matrix::getColsLen() const 
{
    return _colsLen;
}

int Matrix::getRowsLen() const 
{
    return _rowsLen;
}

double& Matrix::matrixField(int i, int j) 
{
    return _A[i][j];
}


void Matrix::matrixSum(const Matrix& term)
{
    if (_colsLen != term.getColsLen() || _rowsLen != term.getRowsLen())
    {
        throw std::logic_error("Another matrix has a different shape\n");
    }
    
    if (_rowsLen == 0 || _rowsLen == 0 || term.getColsLen() == 0 || term.getRowsLen() == 0)
    {
        throw std::length_error("Empty matrix\n");
    }

    for (int i = 0; i < _colsLen; ++i)
    {
        for (int j = 0; j < _rowsLen; ++j)
        {
            _A[i][j] += term._A[i][j];
        }
    }
}

void Matrix::matrixMul(const Matrix& factor)
{
    if (_rowsLen != factor.getColsLen())
    {
        throw std::logic_error("Rows of one matrix are not equal to columns of another\n");
    }
    
    if (_rowsLen == 0 || _rowsLen == 0 || factor.getColsLen() == 0 || factor.getRowsLen() == 0)
    {
        throw std::length_error("Empty matrix\n");
    }
    
    double** A_new = _buildMatrix(_colsLen, factor.getRowsLen());

    for (int i = 0; i < _colsLen; ++i)
    {
        for (int j = 0; j < factor.getRowsLen(); ++j)
        {
            A_new[i][j] = 0;

            for (int k = 0; k < _rowsLen; ++k)
            {
                A_new[i][j] += _A[i][k]*factor._A[k][j];
            }
        }
    }

    _destroyMatrix(_A, _colsLen);
    _A = A_new;
    _rowsLen = factor.getRowsLen();
}

void Matrix::matrixTransposition()
{
    if (_rowsLen == 0 || _rowsLen == 0)
    {
        throw std::length_error("Empty matrix\n");
    }
    
    double** A_new = _buildMatrix(_rowsLen,_colsLen);

    for (int i = 0; i < _rowsLen; ++i)
    {
        for (int j = 0; j < _colsLen; ++j)
        {
            A_new[i][j] = _A[j][i];
        }
    }

    _destroyMatrix(_A, _colsLen);
    _A = A_new;
    
    std::swap(_rowsLen,_colsLen);
}



std::istream& operator>>(std::istream& in, const Matrix& object)
{
    for (int i = 0; i < object._colsLen;++i)
    {
        for (int j = 0; j < object._rowsLen; ++j)
        {
            in >> object._A[i][j];
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& object)
{
    out << "-----------------------------\n";

    out << "Matrix has " 
        << object._colsLen 
        << " rows and " 
        << object._rowsLen 
        << " cols\n";
    
    for (int i = 0; i < object._colsLen;++i)
    {
        for (int j = 0; j < object._rowsLen; ++j)
        {
            out << object._A[i][j] << ' ';
        }
        out << '\n';
    }
    out << "-----------------------------\n";
    return out;
}

Matrix::~Matrix() 
{
    _destroyMatrix(_A, _colsLen);
}