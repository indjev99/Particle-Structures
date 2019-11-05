#ifndef VEC2D_H_INCLUDED
#define VEC2D_H_INCLUDED

struct Vec2D
{
    Vec2D();
    Vec2D(double angle);
    Vec2D(double x, double y);

    double length() const;

    double x, y;
<<<<<<< HEAD
=======
    double length() const;
>>>>>>> 66ade8357150f8989747cf9112c63a0008b1786b
};

extern const Vec2D zero2D;

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
