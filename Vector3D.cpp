//
// Created by USER on 12/16/2018.
//

#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

Vector3D::Vector3D() : Vector3D(0, 0, 0)
{}

Vector3D::Vector3D(double array[VECTOR_SIZE]) : Vector3D(array[0], array[1], array[2])
{}

Vector3D::Vector3D(Vector3D &copyVector)
{
    _x = copyVector._x;
    _y = copyVector._y;
    _z = copyVector._z;
}

Vector3D Vector3D::operator+(const Vector3D &other)
{
    Vector3D result(_x + other._x, _y + other._y, _z + other._z);
    return result;
}

Vector3D Vector3D::operator-(const Vector3D &other)
{
    Vector3D result(_x - other._x, _y - other._y, _z - other._z);
    return result;
}

Vector3D &Vector3D::operator+=(const Vector3D &other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;

    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;

    return *this;
}

Vector3D &Vector3D::operator+=(const int other)
{
    _x += other;
    _y += other;
    _z += other;

    return *this;
}

Vector3D &Vector3D::operator-=(const int other)
{
    _x -= other;
    _y -= other;
    _z -= other;

    return *this;
}

Vector3D &Vector3D::operator*=(const int other)
{
    _x *= other;
    _y *= other;
    _z *= other;

    return *this;
}

Vector3D &Vector3D::operator/=(const int other)
{
    _x /= other;
    _y /= other;
    _z /= other;

    return *this;
}

Vector3D Vector3D::operator-()
{
    Vector3D result(-_x, -_y, -_z);
    return result;
}

Vector3D Vector3D::operator*(int number)
{
    Vector3D result(_x * number, _y * number, _z * number);
    return result;
}

Vector3D Vector3D::operator/(int number)
{
    Vector3D result(_x / number, _y / number, _z / number);
    return result;
}

Vector3D operator*(int left, const Vector3D &right)
{
    Vector3D result(right._x * left, right._y * left, right._z * left);
    return result;
}

double Vector3D::dist(Vector3D &other)
{
    Vector3D sub(*this - other);
    return sqrt(())
}



