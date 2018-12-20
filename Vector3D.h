// Vector3D.h

//todo warnings check
// todo comments
// todo conventions

#ifndef EX1_VECTOR3D_H
#define EX1_VECTOR3D_H


#include <iosfwd>

#define VECTOR_SIZE 3

#define INDEX_OUT_OF_BOUNDS_ERROR "Error: index out of bounds."

#define DIVISION_BY_ZERO_ERROR "Error: Division by zero."

/**
 *  A 3D vector class.
 *  This class represents a vector with (x,y,z) coordinates.
 */
class Vector3D
{
public:
    /**
     * constructor for the vector.
     * @param x x coordinate
     * @param y y coordinate
     * @param z z coordinate
     */
    Vector3D(double x, double y, double z);

    /**
     * Constructor that takes an array.
     * @param array array to construct from
     */
    Vector3D(double array[VECTOR_SIZE]);

    /**
     * default constructor for the vector.
     */
    Vector3D();

    /**
     * copy constructor
     * @param copyVector vector to copy
     */
    Vector3D(const Vector3D &copyVector);

    /**
     * get distance from other vector
     * @param other the other vector
     * @return the distance
     */
    double dist(const Vector3D &other) const;

    /**
     * get the norm of the vector
     * @return the norm
     */
    double norm() const;

    /**
     * overload for plus operator
     * @param other the other vector
     * @return the result
     */
    Vector3D operator+(const Vector3D &other) const;

    /**
     * overload for minus operator
     * @param other the other vector
     * @return the result
     */
    Vector3D operator-(const Vector3D &other) const;

    /**
     * overload for plus equals operator
     * @param other the other vector
     * @return this vector
     */
    Vector3D &operator+=(const Vector3D &other);

    /**
     * overload for minus equals operator
     * @param other the other vector
     * @return this vector
     */
    Vector3D &operator-=(const Vector3D &other);

    /**
     * overload for * equals operator
     * @param other a number
     * @return this vector after calc
     */
    Vector3D &operator*=(double other);

    /**
     * overload for / equals operator
     * @param other a number
     * @return this vector after calc
     */
    Vector3D &operator/=(double other);

    /**
     * overload for + equals operator
     * @param other a number
     * @return this vector after calc
     */
    Vector3D &operator+=(double other);

    /**
     * overload for - equals operator
     * @param other a number
     * @return this vector after calc
     */
    Vector3D &operator-=(double other);

    /**
     * unary minus operator overload
     * @return result
     */
    Vector3D operator-();

    /**
     * multiply vecotr by number
     * @param number num to mult
     * @return result
     */
    Vector3D operator*(double number);

    /**
     * divide vector by num
     * @param number num to divide
     * @return result
     */
    Vector3D operator/(double number);

    /**
     * get distance to other vector
     * @param other the other vector
     * @return distance
     */
    double operator|(const Vector3D &other);

    /**
     * dot product of two vectors
     * @param other the other vectors
     * @return result
     */
    double operator*(const Vector3D &other);

    double operator^(const Vector3D &other);

    friend Vector3D operator*(double left, const Vector3D &right);

    friend std::istream &operator>>(std::istream &stream, Vector3D &vector);

    friend std::ostream &operator<<(std::ostream &stream, const Vector3D &vector);

    Vector3D &operator=(const Vector3D &other);

    double operator[](int i) const;

    double &operator[](int i);

private:
    double _x;
    double _y;
    double _z;
};


#endif //EX1_VECTOR3D_H
