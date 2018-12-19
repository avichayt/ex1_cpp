//
// Created by USER on 12/19/2018.
//

#include "Matrix3D.h"

Matrix3D::Matrix3D()
{

}

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

Matrix3D::Matrix3D(Matrix3D &other)
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
    return 0;
}
