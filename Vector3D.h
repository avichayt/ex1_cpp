//
// Created by USER on 12/16/2018.
//

#ifndef EX1_VECTOR3D_H
#define EX1_VECTOR3D_H

#define VECTOR_SIZE 3

class Vector3D
{
public:
    Vector3D(double x, double y, double z);

    Vector3D(double array[VECTOR_SIZE]);

    Vector3D();

    Vector3D(Vector3D &copyVector);

    double dist(Vector3D& other);

    double norm();

    Vector3D operator+(const Vector3D &other);

    Vector3D operator-(const Vector3D &other);

    Vector3D &operator+=(const Vector3D &other);

    Vector3D &operator-=(const Vector3D &other);

    Vector3D &operator*=(int other);

    Vector3D &operator/=(int other);

    Vector3D &operator+=(int other);

    Vector3D &operator-=(int other);

    Vector3D operator-();

    Vector3D operator*(int number);

    Vector3D operator/(int number);

    friend Vector3D operator*(int left, const Vector3D& right);



private:
    double _x;
    double _y;
    double _z;
};


#endif //EX1_VECTOR3D_H
