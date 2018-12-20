//
// Created by USER on 12/19/2018.
//

#ifndef EX1_MATRIX3D_H
#define EX1_MATRIX3D_H

#include <iostream>
#include "Vector3D.h"

#define MATRIX_SIZE 3

class Matrix3D
{
public:
    Matrix3D();

    void initialize_from_array(double array[MATRIX_SIZE][MATRIX_SIZE]);

    Matrix3D(double number);

    Matrix3D(double n11, double n12, double n13, double n21, double n22, double n23, double n31, double n32,
             double n33);

    Matrix3D(double array[MATRIX_SIZE][MATRIX_SIZE]);

    Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3);

    Matrix3D(const Matrix3D &other);

    Vector3D row(short i);

    Vector3D column(short i);

    double trace();

    double determinant();
    
    Matrix3D operator+(const Matrix3D &other);

    Matrix3D operator-(const Matrix3D &other);

    Matrix3D operator*(const Matrix3D &other);

    Matrix3D &operator+=(const Matrix3D &other);

    Matrix3D &operator-=(const Matrix3D &other);

    Matrix3D &operator*=(double other);

    Matrix3D &operator/=(double other);

    Vector3D operator*(Vector3D &other);

    friend std::istream &operator>>(std::istream &stream, Matrix3D &matrix);

    friend std::ostream &operator<<(std::ostream &stream, const Matrix3D &matrix);

    Matrix3D &operator=(const Matrix3D &other);

    Vector3D operator[](int i) const;

    Vector3D &operator[](int i);

private:
    Vector3D vectors[MATRIX_SIZE];
};


#endif //EX1_MATRIX3D_H
