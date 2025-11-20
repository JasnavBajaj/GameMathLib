#pragma once
#include <cmath>

namespace GameMath {

struct Vector3D {
    float x;
    float y;
    float z;

    constexpr Vector3D() : x(0.0f), y(0.0f), z(0.0f) {}
    constexpr Vector3D(float x_, float y_, float z_)
        : x(x_), y(y_), z(z_) {}

    // Basic arithmetic
    constexpr Vector3D operator+(const Vector3D& rhs) const {
        return {x + rhs.x, y + rhs.y, z + rhs.z};
    }

    constexpr Vector3D operator-(const Vector3D& rhs) const {
        return {x - rhs.x, y - rhs.y, z - rhs.z};
    }

    constexpr Vector3D operator*(float scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    constexpr Vector3D operator/(float scalar) const {
        return {x / scalar, y / scalar, z / scalar};
    }

    Vector3D& operator+=(const Vector3D& rhs) {
        x += rhs.x; y += rhs.y; z += rhs.z;
        return *this;
    }

    Vector3D& operator-=(const Vector3D& rhs) {
        x -= rhs.x; y -= rhs.y; z -= rhs.z;
        return *this;
    }

    Vector3D& operator*=(float scalar) {
        x *= scalar; y *= scalar; z *= scalar;
        return *this;
    }

    Vector3D& operator/=(float scalar) {
        x /= scalar; y /= scalar; z /= scalar;
        return *this;
    }

    // Length / normalization
    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    float lengthSquared() const {
        return x * x + y * y + z * z;
    }

    Vector3D normalize() const {
        float len = length();
        if (len == 0.0f) return Vector3D(0.0f, 0.0f, 0.0f);
        return Vector3D(x / len, y / len, z / len);
    }

    // Dot / cross
    float dot(const Vector3D& rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    Vector3D cross(const Vector3D& rhs) const {
        return Vector3D(
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x
        );
    }
};

inline constexpr Vector3D operator*(float scalar, const Vector3D& v) {
    return {v.x * scalar, v.y * scalar, v.z * scalar};
}

} // namespace GameMath

