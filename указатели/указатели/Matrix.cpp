#include "Matrix.h"
#include "arrays.h"
#include <iostream>
#include "MAAArrix.h"
using namespace std;

using namespace WorkingWithArrays;

int** WorkingWithMatrix::lowTriangleMatrix(int size)
{
    if (size <= 0)
    {
        throw std::out_of_range("Array length must be more than 0");
    }

    int** matrix = new int* [size];
    for (size_t i = 0; i < size; i++)
    {
        int k = i + 1;
        matrix[i] = WorkingWithArrays::allocateMemory(k);

        WorkingWithArrays::randomValues(matrix[i], k);
    }
    return matrix;
}

void WorkingWithMatrix::displayMatrixLow(int** matrix, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        WorkingWithArrays::displayArray(matrix[i], i + 1);
        for (size_t j = i + 1; j < size; j++)
        {
            std::cout.width(5);
            std::cout << 0;
        }

        std::cout << std::endl;
    }
}

int** WorkingWithMatrix::convertToHighTriangleMatrix(int** matrix, int size)
{
    if (matrix == nullptr)
    {
        throw std::invalid_argument("Nullptr pointer");
    }
    if (size <= 0)
    {
        throw std::out_of_range("Array length must be more than 0");
    }

    int** copy = new int* [size];
    for (size_t i = 0; i < size; i++)
    {
        copy[i] = WorkingWithArrays::allocateMemory(size - i);
        for (size_t j = 0; j < size - i; j++)
        {
            copy[i][j] = matrix[j + i][i];
        }
    }
    return copy;
}

int** WorkingWithMatrix::Summarikc(int** MatrixLow, int** MatrixHight, int size)
{
    if (size <= 0)
    {
        throw std::out_of_range("Array length must be more than 0");
    }
    int** resultmatrixs = new int* [size];
    int i = 0;
    for (;i < size; i++)
    {
        resultmatrixs [i] = new int[size];
        for (size_t j = 0; j < i + 1; j++)
            if (i == j)
            {
                int resultmatrixs[i][j] = MatrixLow[i][j] + MatrixHight[i][j];
                resultmatrixs[i][j] = resultmatrixs[j][i];
            }
    }
    return resultmatrixs;

}


int **  WorkingWithMatrix::displayMatrixHigh(int** matrix, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            std::cout.width(5);
            std::cout << 0;
        }

        WorkingWithArrays::displayArray(matrix[i], size - i);

        std::cout << std::endl;
    }
}
int** convertTo(int* array, int rows, int columns) 
{
    if (rows <= 0)
    {
        throw std::out_of_range("Matrix width must be more than 0");
    }

    if (columns <= 0)
    {
        throw std::out_of_range("Matrix lenghtt must be more than 0");
    }

    int** matrix= allocateMemory(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            matrix[i][j] = array[columns * i + j];
        }
    }

    return matrix;
}
int* convertTo(int** matrix, int rows, int columns) 
{
    if (rows <= 0)
    {
        throw std::out_of_range("Matrix width must be more than 0");
    }

    if (columns <= 0)
    {
        throw std::out_of_range("Matrix lenghtt must be more than 0");
    }

    int* array = allocateMemory(rows * columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            array[columns * i + j] = matrix[i][j];
        }
    }
}

int** allocateMemory(int rows, int columns)
{
    if (rows <= 0)
    {
        throw std::out_of_range("Matrix width must be more than 0");
    }

    if (columns <= 0)
    {
        throw std::out_of_range("Matrix lenghtt must be more than 0");
    }
    int** matrix = new int* [rows];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = WorkingWithArrays::allocateMemory(columns);
    }

    return matrix;
}

void WorkingWithMatrix::sortMatrix(int** matrix, int rows, int columns ,key func )
{
    long long* array = new long long[rows];
    for (size_t i = 0; i < rows; i++)
    {
        array[i] = func (matrix[i], columns);
    }
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t i = ; j > i; j--)
        {
            if (array[j] < array[j - 1]) 
            {
                swap(array[j], array[j - 1]);
                swap(matrix[j], matrix[j - 1]);
            }
        }
    }
    //int using comparer = int (*)(int*, int*,int )
void WorkingWithMatrix::initMatrix(int** matrix, int rows , int columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t i = 0; i < columns; i++)
        {
            cout << "[" << (i + 1) << "," << (j + 1) << "] = ";
            cin >> matrix[i][j];
        }
    }
    system("cls");
}

void WorkingWithMatrix::displayMatrix(int** matrix, int rows, int columns,int width)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t i = 0; i < columns; i++)
        {
            cout.width(width);
            cout << matrix[i][j];
        }
    }
    system("cls");
}

void WorkingWithMatrix::swap(int*& a, int*& b)
{
    int* temp = a;
    a = b;
    b = temp;

}
long long  WorkingWithMatrix::sumOfElement(int* array, int size)
{
    long sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}
long long WorkingWithMatrix::productOfElement(int* array, int size)
{
    long long sum = 1;
    for (size_t i = 0; i < size; i++)
    {
        sum *= array;
    }
    return sum;
}
void WorkingWithMatrix::swap(int*& a, int*& b)
{
    int* temp = a;
    a = b;
    b = temp;
}

