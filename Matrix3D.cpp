//
// Created by USER on 12/19/2018.
//

#include "Matrix3D.h"

Matrix3D::Matrix3D() : Matrix3D(0, 0, 0, 0, 0, 0, 0, 0, 0)
{}

Matrix3D::Matrix3D(double number) : Matrix3D(number, 0, 0, 0, number, 0, 0, 0, number)
{}

void Matrix3D::initialize_from_array(double array[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        vectors[i] = Vector3D(array[i]);
    }
}

Matrix3D::Matrix3D(double n11, double n12, double n13, double n21, double n22, double n23, double n31, double n32,
                   double n33)
{
    double array[MATRIX_SIZE][MATRIX_SIZE] = {n11, n12, n13, n21, n22, n23, n31, n32, n33};
    initialize_from_array(array);
}

Matrix3D::Matrix3D(const Matrix3D &other)
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        vectors[i] = other.vectors[i];
    }
}

Matrix3D::Matrix3D(double array[MATRIX_SIZE][MATRIX_SIZE])
{
    initialize_from_array(array);
}

Matrix3D::Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3)
{
    vectors[0] = v1;
    vectors[1] = v2;
    vectors[2] = v3;
}

void checkIndex(short i)
{
    if (i <= 0 || i >= 2)
    {
        std::cerr << INDEX_OUT_OF_BOUNDS_ERROR;
        exit(EXIT_FAILURE);
    }
}

Vector3D Matrix3D::row(short i)
{
    checkIndex(i);
    return vectors[i];
}

Vector3D Matrix3D::column(short i)
{
    checkIndex(i);
    Vector3D columnVector(vectors[0][i], vectors[1][i], vectors[2][i]);
    return columnVector;
}

double Matrix3D::trace()
{
    double trace = 0;
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        trace += vectors[i][i];
    }
    return trace;
}

double Matrix3D::determinant()
{
    return vectors[0][0] * ((vectors[1][1] * vectors[2][2]) - (vectors[2][1] * vectors[1][2])) -
           vectors[0][1] * (vectors[1][0] * vectors[2][2] - vectors[2][0] * vectors[1][2]) +
           vectors[0][2] * (vectors[1][0] * vectors[2][1] - vectors[2][0] * vectors[1][1]);
}

Matrix3D &Matrix3D::operator+=(const Matrix3D &other)
{
    return (*this = *this + other);
}

Matrix3D &Matrix3D::operator-=(const Matrix3D &other)
{
    Matrix3D minusMatrix = other;
    minusMatrix *= -1;
    return ((*this) = *this + minusMatrix);
}

Matrix3D &Matrix3D::operator*=(double other)
{
    for (auto &vector : vectors)
    {
        vector *= other;
    }
    return *this;
}

Matrix3D &Matrix3D::operator/=(double other)
{
    for (auto &vector : vectors)
    {
        vector /= other;
    }
    return *this;
}

Matrix3D Matrix3D::operator+(const Matrix3D &other)
{
    Matrix3D newMatrix;
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        newMatrix.vectors[i] += other.vectors[i];
    }
    return newMatrix;
}

Matrix3D Matrix3D::operator-(const Matrix3D &other)
{
    Matrix3D minusMatrix = other;
    minusMatrix *= -1;
    return *this + minusMatrix;
}

Matrix3D Matrix3D::operator*(const Matrix3D &other)
{
    Matrix3D result;
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int j = 0; j < MATRIX_SIZE; ++j)
        {
            result[i][j] = vectors[i] * other.vectors[j];
        }
    }
    return result;
}

Vector3D Matrix3D::operator*(Vector3D &other)
{
    Vector3D result;
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        result[i] = vectors[i] * other;
    }
    return result;
}

std::ostream &operator<<(std::ostream &stream, const Matrix3D &matrix)
{
    for (const auto &vector : matrix.vectors)
    {
        stream << vector;
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, Matrix3D &matrix)
{
    for (auto &vector : matrix.vectors)
    {
        stream >> vector;
    }
    return stream;
}

Matrix3D &Matrix3D::operator=(const Matrix3D &other)
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        vectors[i] = other.vectors[i];
    }
    return *this;
}

Vector3D &Matrix3D::operator[](int i)
{
    return vectors[i];
}

Vector3D Matrix3D::operator[](int i) const
{
    Vector3D result;
    result = vectors[i];
    return result;
}
