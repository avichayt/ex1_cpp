// Vector3D.h

//todo warnings check
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

    /**
     * get angle in radian from other vector
     * @param other other vector
     * @return the angle in radians
     */
    double operator^(const Vector3D &other);

    /**
     * mult vector by number (from left)
     * @param left the number
     * @param right the vector
     * @return the result
     */
    friend Vector3D operator*(double left, const Vector3D &right);

    /**
     * overload >> operator
     * @param stream stream to print
     * @param vector vector to print
     * @return the stream
     */
    friend std::istream &operator>>(std::istream &stream, Vector3D &vector);

    /**
     * overload << operator
     * @param stream stream to get input from
     * @param vector vector to get
     * @return the stream
     */
    friend std::ostream &operator<<(std::ostream &stream, const Vector3D &vector);

    /**
     * overload = operator
     * @param other the other vector
     * @return this vector
     */
    Vector3D &operator=(const Vector3D &other);

    /**
     * get the i'th coordinate
     * @param i the coordinate
     * @return result
     */
    double operator[](int i) const;

    /**
     * set the i'th coordinate
     * @param i the coordinate
     * @return result
     */
    double &operator[](int i);

private:
    /**
     * x value of the vector
     */
    double _x;
    /**
    * y value of the vector
    */
    double _y;
    /**
    * z value of the vector
    */
    double _z;
};


#endif //EX1_VECTOR3D_H
