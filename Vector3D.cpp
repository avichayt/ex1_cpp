//
// Created by USER on 12/16/2018.
//

#include "Vector3D.h"
#include <cmath>
#include <iostream>

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

Vector3D::Vector3D(const Vector3D &copyVector)
{
    _x = copyVector._x;
    _y = copyVector._y;
    _z = copyVector._z;
}

Vector3D Vector3D::operator+(const Vector3D &other) const
{
    Vector3D result(_x + other._x, _y + other._y, _z + other._z);
    return result;
}

Vector3D Vector3D::operator-(const Vector3D &other) const
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

Vector3D &Vector3D::operator+=(const double other)
{
    _x += other;
    _y += other;
    _z += other;

    return *this;
}

Vector3D &Vector3D::operator-=(const double other)
{
    _x -= other;
    _y -= other;
    _z -= other;

    return *this;
}

Vector3D &Vector3D::operator*=(const double other)
{
    _x *= other;
    _y *= other;
    _z *= other;

    return *this;
}

Vector3D &Vector3D::operator/=(const double other)
{
    if (other == 0)
    {
        std::cerr << DIVISION_BY_ZERO_ERROR;
        exit(EXIT_FAILURE);
    }
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

Vector3D Vector3D::operator*(double number)
{
    Vector3D result(_x * number, _y * number, _z * number);
    return result;
}

Vector3D Vector3D::operator/(double number)
{
    Vector3D result(_x / number, _y / number, _z / number);
    return result;
}

Vector3D operator*(double left, const Vector3D &right)
{
    Vector3D result(right._x * left, right._y * left, right._z * left);
    return result;
}

double Vector3D::dist(const Vector3D &other) const
{
    const Vector3D &sub = *this - other;
    return std::sqrt(sub._x * sub._x + sub._y * sub._y + sub._z * sub._z);
}

double Vector3D::norm() const
{
    Vector3D origin(0, 0, 0);
    return dist(origin);
}

double Vector3D::operator|(const Vector3D &other)
{
    return dist(other);
}

double Vector3D::operator*(const Vector3D &other)
{
    return _x * other._x + _y * other._y + _z * other._z;
}

double Vector3D::operator^(const Vector3D &other)
{
    return std::acos(((*this) * other) / norm() / other.norm());
}

std::istream &operator>>(std::istream &stream, Vector3D &vector)
{
    return stream >> vector._x >> vector._y >> vector._z;
}

std::ostream &operator<<(std::ostream &stream, const Vector3D &vector)
{
    return stream << vector._x << ' ' << vector._y << ' ' << vector._z << std::endl;
}

Vector3D &Vector3D::operator=(const Vector3D &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

double Vector3D::operator[](int i) const
{
    switch (i)
    {
        case 0:
            return _x;
        case 1:
            return _y;
        case 2:
            return _z;
        default:
            std::cerr << INDEX_OUT_OF_BOUNDS_ERROR;
            exit(EXIT_FAILURE);
    }
}


double &Vector3D::operator[](int i)
{
    switch (i)
    {
        case 0:
            return _x;
        case 1:
            return _y;
        case 2:
            return _z;
        default:
            std::cerr << INDEX_OUT_OF_BOUNDS_ERROR;
            exit(EXIT_FAILURE);
    }
}








