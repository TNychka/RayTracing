//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_VEC3_H
#define RAYTRACING_VEC3_H

#include <math.h>
#include <fstream>

class Vector3D {
public:
    enum Colour {
      X = 0,
      Y,
      Z,
      COUNT
    };

    Vector3D();
    Vector3D(float x, float y, float z);
    inline float getX() const;
    inline float getY() const;
    inline float getZ() const;

    // Operator overloads
    inline Vector3D operator+(const Vector3D& p1) const;
    inline Vector3D operator+(const float t) const;
    inline Vector3D operator-() const;
    inline Vector3D operator-(const Vector3D& p1) const;
    inline Vector3D operator-(const float t) const;
    inline Vector3D operator*(const Vector3D& p1) const;
    inline Vector3D operator*(const float t) const;
    inline Vector3D operator/(const Vector3D& p1) const;
    inline Vector3D operator/(const float t) const;

    inline float operator[](Colour i) const;
    inline float& operator[](Colour i);
    inline Vector3D& operator+=(const Vector3D& c);
    inline Vector3D& operator-=(const Vector3D& c);
    inline Vector3D& operator*=(const Vector3D& c);
    inline Vector3D& operator/=(const Vector3D& c);
    inline Vector3D& operator*=(const float f);
    inline Vector3D& operator/=(const float f);

    // Operations
    inline float length() const;
    inline float squaredLength() const;
    inline Vector3D& toUnitVector();
    static inline float dot(const Vector3D& p1, const Vector3D& p2);
    static inline Vector3D cross(const Vector3D& p1, const Vector3D& p2);

    static Vector3D makeUnitVector(const Vector3D v);
private:
    inline friend std::ostream& operator<<(std::ostream& os, const Vector3D& v1);
    inline friend std::istream& operator>>(std::istream& is, Vector3D& v1);

    float values[COUNT];
};

inline Vector3D Vector3D::operator+(const Vector3D& p1) const
{
    return {p1.getX()+getX(), p1.getY()+getY(), p1.getZ()+getZ()};
}

inline Vector3D Vector3D::operator+(float t) const
{
    return {getX()+t, getY()+t, getZ()+t};
}

inline Vector3D Vector3D::operator-() const
{
    return {-getX(), -getY(), -getZ()};
}

inline Vector3D Vector3D::operator-(const Vector3D& p1) const
{
    return {getX()-p1.getX(), getY()-p1.getY(), getZ()-p1.getZ()};
}

inline Vector3D Vector3D::operator-(float t) const
{
    return {getX()-t, getY()-t, getZ()-t};
}

inline Vector3D Vector3D::operator*(const Vector3D& p2) const
{
    return {getX()*p2.getX(), getY()*p2.getY(), getZ()*p2.getZ()};
}

inline Vector3D Vector3D::operator*(float t) const
{
    return {getX()*t, getY()*t, getZ()*t};
}

inline Vector3D operator*(float t, const Vector3D& v1)
{
    return {v1.getX()*t, v1.getY()*t, v1.getZ()*t};
}

inline Vector3D Vector3D::operator/(const Vector3D& p2) const
{
    return {getX()/p2.getX(), getY()/p2.getY(), getZ()/p2.getZ()};
}

inline Vector3D Vector3D::operator/(float t) const
{
    return {getX()/t, getY()/t, getZ()/t};
}

inline float Vector3D::getX() const
{
    return values[X];
}

inline float Vector3D::getY() const
{
    return values[Y];
}

inline float Vector3D::getZ() const
{
    return values[Z];
}

inline float Vector3D::operator[](Vector3D::Colour c) const
{
    return values[c];
}

inline float& Vector3D::operator[](Vector3D::Colour c)
{
    return values[c];
}

inline Vector3D& Vector3D::operator+=(const Vector3D& c)
{
    values[X] += c.getX();
    values[Y] += c.getY();
    values[Z] += c.getZ();
    return *this;
}

inline Vector3D& Vector3D::operator-=(const Vector3D& c)
{
    values[X] -= c.getX();
    values[Y] -= c.getY();
    values[Z] -= c.getZ();
    return *this;
}

inline Vector3D& Vector3D::operator*=(const Vector3D& c)
{
    values[X] *= c.getX();
    values[Y] *= c.getY();
    values[Z] *= c.getZ();
    return *this;
}

inline Vector3D& Vector3D::operator/=(const Vector3D& c)
{
    values[X] /= c.getX();
    values[Y] /= c.getY();
    values[Z] /= c.getZ();
    return *this;
}

inline Vector3D& Vector3D::operator*=(const float f)
{
    values[X] *= f;
    values[Y] *= f;
    values[Z] *= f;
    return *this;
}

inline Vector3D& Vector3D::operator/=(const float f)
{
    values[X] /= f;
    values[Y] /= f;
    values[Z] /= f;
    return *this;
}

inline float Vector3D::length() const
{
    return sqrt(squaredLength());
}

inline float Vector3D::squaredLength() const
{
    return values[X]*values[X]+values[Y]*values[Y]+values[Z]*values[Z];
}

inline Vector3D& Vector3D::toUnitVector()
{
    auto k = static_cast<float>(1.0/length());
    values[X] = getX()/k;
    values[Y] = getY()/k;
    values[Z] = getZ()/k;
    return *this;
}

inline float Vector3D::dot(const Vector3D& p1, const Vector3D& p2)
{
    return p1.getX()*p2.getX()+p1.getY()*p2.getY()+p1.getZ()*p2.getZ();
}

inline Vector3D Vector3D::cross(const Vector3D& p1, const Vector3D& p2)
{
    return Vector3D(
            (p1.getY()*p2.getZ()-p1.getZ()*p2.getY()),
            -(p1.getX()*p2.getZ()-p1.getZ()*p2.getX()),
            (p1.getX()*p2.getY()-p1.getY()*p2.getX())
    );
}

inline std::istream& operator>>(std::istream& is, Vector3D& v1)
{
    is >> v1.values[Vector3D::X] >> v1.values[Vector3D::Y] >> v1.values[Vector3D::Z];
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Vector3D& v1)
{
    os << v1.values[Vector3D::X] << " " << v1.values[Vector3D::Y] << " " << v1.values[Vector3D::Z];
    return os;
}

#endif //RAYTRACING_VEC3_H
