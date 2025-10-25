#pragma once
#include <cmath>

namespace GameMath {

class Vector3D {
public:
    float x, y, z;

    Vector3D() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D operator*(float scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    float dot(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Cross product (important for 3D)
    Vector3D cross(const Vector3D& other) const {
        return Vector3D(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3D normalize() const {
        float len = length();
        if (len > 0.0f) {
            return Vector3D(x / len, y / len, z / len);
        }
        return Vector3D(0.0f, 0.0f, 0.0f);
    }

    static float distance(const Vector3D& a, const Vector3D& b) {
        return (b - a).length();
    }
};

} // namespace GameMath
