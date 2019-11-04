#include "../headers/vec2d.h"

#include <math.h>

const Vec2D zero2D = {0, 0};

double Vec2D::length() const
{
    return sqrt(x * x + y * y);
}
Vec2D operator+(const Vec2D& u, const Vec2D& v)
{
    return {u.x + v.x, u.y + v.y};
}
Vec2D operator-(const Vec2D& u, const Vec2D& v)
{
    return {u.x - v.x, u.y - v.y};
}
Vec2D operator-(const Vec2D& u)
{
    return {-u.x, -u.y};
}
Vec2D operator*(const Vec2D& u, double a)
{
    return {u.x * a, u.y * a};
}
Vec2D operator*(double a, const Vec2D& u)
{
    return {u.x * a, u.y * a};
}
Vec2D operator/(const Vec2D& u, double a)
{
    return {u.x / a, u.y / a};
}
Vec2D& operator+=(Vec2D& u, const Vec2D& v)
{
    u.x += v.x;
    u.y += v.y;
    return u;
}
Vec2D& operator-=(Vec2D& u, const Vec2D& v)
{
    u.x -= v.x;
    u.y -= v.y;
    return u;
}
Vec2D& operator*=(Vec2D& u, double a)
{
    u.x *= a;
    u.y *= a;
    return u;
}
Vec2D& operator/=(Vec2D& u, double a)
{
    u.x /= a;
    u.y /= a;
    return u;
}
