#pragma once
using namespace std;
#include <iostream>

template <class S> class Vector3Dx;

typedef Vector3Dx<float> Vector3D;

typedef Vector3Dx<float> Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int> Vector3Di;


template <class S> class Vector3Dx
{
    private:
        S x, y, z;
    public:
        Vector3Dx() :x(0), y(0), z(0) {}
        Vector3Dx(S x, S y,S z) :x(x), y(y), z(z) {}

        inline S getX() const { return this->x; }
        inline S getY() const { return this->y; }
        inline S getZ() const { return this->z; }


        inline void setX(S x) { this->x = x; }
        inline void setY(S y) { this->y = y; }
        inline void setZ(S z) { this->z = z; }

        /*Vector3D Add(const Vector3D& vector);
        Vector3D Substract(const Vector3D& vector);
        Vector3D Product(const float& value);
        Vector3D Division(const float& value);
        float DotProduct(const Vector3D& vector);*/

        Vector3Dx<S> operator-(const Vector3Dx<S>& vector);
        Vector3Dx<S> operator+(const Vector3Dx<S>& vector);
        Vector3Dx<S> operator*(const S& value);
        Vector3Dx<S> operator/(const S& value);
        S operator*(const Vector3Dx<S>& vector);     
};

template <class S> Vector3Dx<S> Vector3Dx<S>::operator+(const Vector3Dx<S>& vector)
{
    return Vector3Dx<S>(this->getX() + vector.getX(), this->getY() + vector.getY(), this->getZ() + vector.getZ());

}

template <class S> Vector3Dx<S> Vector3Dx<S>::operator-(const Vector3Dx<S>& vector)
{
    return Vector3Dx<S>(this->getX() - vector.getX(), this->getY() - vector.getY(), this->getZ() - vector.getZ());

}

template <class S> Vector3Dx<S> Vector3Dx<S>::operator*(const S& value)
{
    return Vector3Dx<S>(this->getX() * value, this->getY() * value, this->getZ() * value);

}

template <class S> Vector3Dx<S> Vector3Dx<S>::operator/(const S& value)
{
    return Vector3Dx<S>(this->getX() / value, this->getY() / value, this->getZ() / value);
}

template <class S> S Vector3Dx<S>::operator*(const Vector3Dx<S>& vector)
{
    return ((this->getX() * vector.getX()) + (this->getY() * vector.getY()) + (this->getZ() * vector.getZ()));
}