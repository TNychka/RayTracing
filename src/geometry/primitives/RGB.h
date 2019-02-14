//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_RBGCOLOUR_H
#define RAYTRACING_RBGCOLOUR_H

#include <istream>

class RGB {
public:
    enum Colour {
      RED = 0,
      GREEN,
      BLUE,
      COUNT
    };

    RGB();
    RGB(float r, float g, float b);

    inline RGB operator+(const RGB& p1) const;
    inline RGB operator+(const float t) const;
    inline RGB operator-() const;
    inline RGB operator-(const RGB& p1) const;
    inline RGB operator-(const float t) const;
    inline RGB operator*(const RGB& p1) const;
    inline RGB operator*(const float t) const;
    inline RGB operator/(const RGB& p1) const;
    inline RGB operator/(const float t) const;

    inline float operator[](Colour i) const;
    inline float& operator[](Colour i);
    inline RGB& operator+=(const RGB& rbg);
    inline RGB& operator-=(const RGB& rbg);
    inline RGB& operator*=(const RGB& rbg);
    inline RGB& operator/=(const RGB& rbg);
    inline RGB& operator*=(const float f);
    inline RGB& operator/=(const float f);

    inline float getR() const;
    inline float getG() const;
    inline float getB() const;
    inline int getR256() const;
    inline int getG256() const;
    inline int getB256() const;

private:
    inline friend std::ostream& operator<<(std::ostream& os, const RGB& rgb);
    float rgb[COUNT];
};

inline RGB RGB::operator+(const RGB& p1) const
{
    return {p1.getR()+getR(), p1.getG()+getG(), p1.getB()+getB()};
}

inline RGB RGB::operator+(float t) const
{
    return {getR()+t, getG()+t, getB()+t};
}

inline RGB RGB::operator-() const
{
    return {-getR(), -getG(), -getB()};
}

inline RGB RGB::operator-(const RGB& p1) const
{
    return {getR()-p1.getR(), getG()-p1.getG(), getB()-p1.getB()};
}

inline RGB RGB::operator-(float t) const
{
    return {getR()-t, getG()-t, getB()-t};
}

inline RGB RGB::operator*(const RGB& p2) const
{
    return {getR()*p2.getR(), getG()*p2.getG(), getB()*p2.getB()};
}

inline RGB RGB::operator*(float t) const
{
    return {getR()*t, getG()*t, getB()*t};
}

inline RGB operator*(float t, const RGB& v1)
{
    return {v1.getR()*t, v1.getG()*t, v1.getB()*t};
}

inline RGB RGB::operator/(const RGB& p2) const
{
    return {getR()/p2.getR(), getG()/p2.getG(), getB()/p2.getB()};
}

inline RGB RGB::operator/(float t) const
{
    return {getR()/t, getG()/t, getB()/t};
}

inline float RGB::getR() const
{
    return rgb[RED];
}

inline float RGB::getG() const
{
    return rgb[GREEN];
}

inline float RGB::getB() const
{
    return rgb[BLUE];
}

inline int RGB::getR256() const
{
    return (static_cast<int>(rgb[RED]*255.99)%256+256)%256;
}

inline int RGB::getG256() const
{
    return (static_cast<int>(rgb[GREEN]*255.99)%256+256)%256;
}

inline int RGB::getB256() const
{
    return (static_cast<int>(rgb[BLUE]*255.99)%256+256)%256;
}

inline float RGB::operator[](RGB::Colour c) const
{
    return rgb[c];
}

inline float& RGB::operator[](RGB::Colour c)
{
    return rgb[c];
}

inline RGB& RGB::operator+=(const RGB& c)
{
    rgb[RED] += c.getR();
    rgb[GREEN] += c.getG();
    rgb[BLUE] += c.getB();
    return *this;
}

inline RGB& RGB::operator-=(const RGB& c)
{
    rgb[RED] -= c.getR();
    rgb[GREEN] -= c.getG();
    rgb[BLUE] -= c.getB();
    return *this;
}

inline RGB& RGB::operator*=(const RGB& c)
{
    rgb[RED] *= c.getR();
    rgb[GREEN] *= c.getG();
    rgb[BLUE] *= c.getB();
    return *this;
}

inline RGB& RGB::operator/=(const RGB& c)
{
    rgb[RED] /= c.getR();
    rgb[GREEN] /= c.getG();
    rgb[BLUE] /= c.getB();
    return *this;
}

inline RGB& RGB::operator*=(const float f)
{
    rgb[RED] *= f;
    rgb[GREEN] *= f;
    rgb[BLUE] *= f;
    return *this;
}

inline RGB& RGB::operator/=(const float f)
{
    rgb[RED] /= f;
    rgb[GREEN] /= f;
    rgb[BLUE] /= f;
    return *this;
}

inline std::ostream& operator<<(std::ostream& os, const RGB& rgb)
{
    os << rgb.getR256() << " " << rgb.getG256() << " " << rgb.getB256();
    return os;
}

#endif //RAYTRACING_RBGCOLOUR_H
