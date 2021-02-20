#include "../headers/vec2d.h"
#include "../headers/my_math.h"

const Vec2D zero2D = Vec2D(0, 0);

Vec2D::Vec2D() {}
Vec2D::Vec2D(double angle):
    x(cos(angle)),
    y(sin(angle))
{}
Vec2D::Vec2D(double x, double y):
    x(x),
    y(y)
{}

double Vec2D::length() const
{
    return sqrt(x * x + y * y);
}
double dot(const Vec2D& u, const Vec2D& v)
{
    return u.x * v.x + u.y * v.y;
}
Vec2D operator+(const Vec2D& u, const Vec2D& v)
{
    return Vec2D(u.x + v.x, u.y + v.y);
}
Vec2D operator-(const Vec2D& u, const Vec2D& v)
{
    return Vec2D(u.x - v.x, u.y - v.y);
}
Vec2D operator-(const Vec2D& u)
{
    return Vec2D(-u.x, -u.y);
}
Vec2D operator*(const Vec2D& u, double a)
{
    return Vec2D(u.x * a, u.y * a);
}
Vec2D operator*(double a, const Vec2D& u)
{
    return Vec2D(u.x * a, u.y * a);
}
Vec2D operator/(const Vec2D& u, double a)
{
    return Vec2D(u.x / a, u.y / a);
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
