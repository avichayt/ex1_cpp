// Matrix3D.h

#ifndef EX1_MATRIX3D_H
#define EX1_MATRIX3D_H

#include <iostream>
#include "Vector3D.h"

#define MATRIX_SIZE 3


/**
 *  A Matrix3D class.
 *  This class represents a Matrix of 3X3.
 */
class Matrix3D
{
public:
    /**
     * default constructor
     */
    Matrix3D();

    /**
     * method to initialize vector from array of numbers.
     * @param array
     */
    void initialize_from_array(double array[MATRIX_SIZE * MATRIX_SIZE]);

    /**
     * constructor from diagonal value
     * @param number number to be put in the diagonal
     */
    Matrix3D(double number);

    /**
     * constructor from 9 number
     * @param n11 1st number
     * @param n12 2nd number
     * @param n13 3rd number
     * @param n21 4th number
     * @param n22 5th number
     * @param n23 6th number
     * @param n31 7th number
     * @param n32 8th number
     * @param n33 9th number
     */
    Matrix3D(double n11, double n12, double n13, double n21, double n22, double n23, double n31, double n32,
             double n33);

    /**
     * constructor from array
     * @param array
     */
    Matrix3D(double array[MATRIX_SIZE * MATRIX_SIZE]);

    /**
     * constructor from 2D array
     * @param array
     */
    Matrix3D(double array[MATRIX_SIZE][MATRIX_SIZE]);

    /**
     * constructor from 3 vectors
     * @param v1 first vector
     * @param v2 second vector
     * @param v3 third vector
     */
    Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3);

    /**
     * copy constructor
     * @param other other vector
     */
    Matrix3D(const Matrix3D &other);

    /**
     * get row from matrix
     * @param i row index
     * @return the row
     */
    Vector3D row(short i);

    /**
     * get column from matrix
     * @param i column index
     * @return the column
     */
    Vector3D column(short i) const;

    /**
     * get trace from the matrix
     * @return the trace
     */
    double trace();

    /**
     * get determinant of matrix
     * @return the determinant
     */
    double determinant();

    /**
     * overload + operator
     * @param other the other matrix
     * @return result
     */
    Matrix3D operator+(const Matrix3D &other);

    /**
     * overload - operator
     * @param other the other matrix
     * @return result
     */
    Matrix3D operator-(const Matrix3D &other);

    /**
     * overload * operator
     * @param other the other matrix
     * @return result
     */
    Matrix3D operator*(const Matrix3D &other);

    /**
     * overload *= operator
     * @param other the other matrix
     * @return this.
     */
    Matrix3D &operator*=(const Matrix3D &other);

    /**
     * overload += operator
     * @param other the other matrix
     * @return this
     */
    Matrix3D &operator+=(const Matrix3D &other);

    /**
     * overload -= operator
     * @param other the other matrix
     * @return this
     */
    Matrix3D &operator-=(const Matrix3D &other);

    /**
     * overload *= operator
     * @param other the other number
     * @return this
     */
    Matrix3D &operator*=(double other);

    /**
     * overload /= operator
     * @param other the other number
     * @return this
     */
    Matrix3D &operator/=(double other);

    /**
     * mult matrix by vector
     * @param other vector to multiply
     * @return result as vector
     */
    Vector3D operator*(Vector3D &other);

    /**
     * overload >> operator
     * @param stream stream to print
     * @param matrix vector to print
     * @return the stream
     */
    friend std::istream &operator>>(std::istream &stream, Matrix3D &matrix);

    /**
     * overload << operator
     * @param stream stream to get input from
     * @param matrix vector to get
     * @return the stream
     */
    friend std::ostream &operator<<(std::ostream &stream, const Matrix3D &matrix);

    /**
     * overload = operator
     * @param other other matrix
     * @return this
     */
    Matrix3D &operator=(const Matrix3D &other);

    /**
     * overload [] operator - get row
     * @param i row index
     * @return row
     */
    Vector3D operator[](int i) const;

    /**
     * set row in the matrix
     * @param i row index
     * @return row as vector reference
     */
    Vector3D &operator[](int i);

private:
    /**
     * the built in vector that make the matrix
     * represent lines.
     */
    Vector3D vectors[MATRIX_SIZE];
};


#endif //EX1_MATRIX3D_H
