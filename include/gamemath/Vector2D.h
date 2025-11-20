#pragma once
#include <cmath>

namespace GameMath {

struct Vector2D {
    float x;
    float y;

    constexpr Vector2D() : x(0.0f), y(0.0f) {}
    constexpr Vector2D(float x_, float y_) : x(x_), y(y_) {}

    // Basic arithmetic
    constexpr Vector2D operator+(const Vector2D& rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    constexpr Vector2D operator-(const Vector2D& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    constexpr Vector2D operator*(float scalar) const {
        return {x * scalar, y * scalar};
    }

    constexpr Vector2D operator/(float scalar) const {
        return {x / scalar, y / scalar};
    }

    Vector2D& operator+=(const Vector2D& rhs) {
        x += rhs.x; y += rhs.y;
        return *this;
    }

    Vector2D& operator-=(const Vector2D& rhs) {
        x -= rhs.x; y -= rhs.y;
        return *this;
    }

    Vector2D& operator*=(float scalar) {
        x *= scalar; y *= scalar;
        return *this;
    }

    Vector2D& operator/=(float scalar) {
        x /= scalar; y /= scalar;
        return *this;
    }

    // Length / normalization
    float length() const {
        return std::sqrt(x * x + y * y);
    }

    float lengthSquared() const {
        return x * x + y * y;
    }

    Vector2D normalize() const {
        float len = length();
        if (len == 0.0f) return Vector2D(0.0f, 0.0f);
        return Vector2D(x / len, y / len);
    }

    // Dot product
    float dot(const Vector2D& rhs) const {
        return x * rhs.x + y * rhs.y;
    }

    // Static helpers
    static float distance(const Vector2D& a, const Vector2D& b) {
        return (a - b).length();
    }
};

inline constexpr Vector2D operator*(float scalar, const Vector2D& v) {
    return {v.x * scalar, v.y * scalar};
}

}
