#ifndef VEC2D_H_INCLUDED
#define VEC2D_H_INCLUDED

struct Vec2D
{
    double x, y;
    double length();
};

Vec2D operator+(const Vec2D& u, const Vec2D& v);
Vec2D operator-(const Vec2D& u, const Vec2D& v);
Vec2D operator-(const Vec2D& u);
Vec2D operator*(const Vec2D& u, double a);
Vec2D operator*(double a, const Vec2D& u);
Vec2D operator/(const Vec2D& u, double a);
Vec2D& operator+=(Vec2D& u, const Vec2D& v);
Vec2D& operator-=(Vec2D& u, const Vec2D& v);
Vec2D& operator*=(Vec2D& u, double a);
Vec2D& operator/=(Vec2D& u, double a);

#endif // VEC2D_H_INCLUDED
