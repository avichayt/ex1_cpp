//
// Created by USER on 12/16/2018.
//

//todo warnings check
// todo comments
// todo conventions

#ifndef EX1_VECTOR3D_H
#define EX1_VECTOR3D_H

#include <iosfwd>

#define VECTOR_SIZE 3

#define INDEX_OUT_OF_BOUNDS_ERROR "Error: index out of bounds."

class Vector3D
{
public:
    Vector3D(double x, double y, double z);

    Vector3D(double array[VECTOR_SIZE]);

    Vector3D();

    Vector3D(Vector3D &copyVector);

    double dist(const Vector3D &other) const;

    double norm() const;

    Vector3D operator+(const Vector3D &other) const;

    Vector3D operator-(const Vector3D &other) const;

    Vector3D &operator+=(const Vector3D &other);

    Vector3D &operator-=(const Vector3D &other);

    Vector3D &operator*=(double other);

    Vector3D &operator/=(double other);

    Vector3D &operator+=(double other);

    Vector3D &operator-=(double other);

    Vector3D operator-();

    Vector3D operator*(double number);

    Vector3D operator/(double number);

    double operator|(const Vector3D &other);

    double operator*(const Vector3D &other);

    double operator^(const Vector3D &other);

    friend Vector3D operator*(double left, const Vector3D &right);

    friend std::istream &operator>>(std::istream &stream, Vector3D &vector);

    friend std::ostream &operator<<(std::ostream &stream, const Vector3D &vector);

    Vector3D &operator=(const Vector3D &other);

    double operator[](int i) const;

    double & operator[] (int i);


private:
    double _x;
    double _y;
    double _z;
};


#endif //EX1_VECTOR3D_H
