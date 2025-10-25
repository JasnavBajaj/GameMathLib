#pragma once
#include <cmath>

namespace GameMath {

class Vector2D {
public:
    float x, y;

    // Constructors
    Vector2D() : x(0.0f), y(0.0f) {}
    Vector2D(float x, float y) : x(x), y(y) {}

    // Basic operations
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D operator/(float scalar) const {
        return Vector2D(x / scalar, y / scalar);
    }

    // Dot product
    float dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    // Length (magnitude)
    float length() const {
        return std::sqrt(x * x + y * y);
    }

    // Normalize
    Vector2D normalize() const {
        float len = length();
        if (len > 0.0f) {
            return Vector2D(x / len, y / len);
        }
        return Vector2D(0.0f, 0.0f);
    }

    // Distance between two vectors
    static float distance(const Vector2D& a, const Vector2D& b) {
        return (b - a).length();
    }
};

} // namespace GameMath
