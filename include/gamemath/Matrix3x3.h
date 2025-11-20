#pragma once
#include <cmath>
#include "Vector2D.h"

namespace GameMath {

// 3x3 matrix for 2D affine transforms (column-major or row-major – here row-major)
struct Matrix3x3 {
    float m[3][3];

    Matrix3x3() {
        // Identity by default
        m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
        m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f;
    }

    static Matrix3x3 identity() {
        return Matrix3x3();
    }

    static Matrix3x3 translation(float tx, float ty) {
        Matrix3x3 mat;
        mat.m[0][2] = tx;
        mat.m[1][2] = ty;
        return mat;
    }

    static Matrix3x3 scale(float sx, float sy) {
        Matrix3x3 mat;
        mat.m[0][0] = sx;
        mat.m[1][1] = sy;
        return mat;
    }

    static Matrix3x3 rotation(float radians) {
        Matrix3x3 mat;
        float c = std::cos(radians);
        float s = std::sin(radians);

        mat.m[0][0] = c;  mat.m[0][1] = -s;
        mat.m[1][0] = s;  mat.m[1][1] =  c;
        return mat;
    }

    Matrix3x3 operator*(const Matrix3x3& rhs) const {
        Matrix3x3 result;

        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                result.m[r][c] =
                    m[r][0] * rhs.m[0][c] +
                    m[r][1] * rhs.m[1][c] +
                    m[r][2] * rhs.m[2][c];
            }
        }

        return result;
    }

    // Transform a 2D point (x, y, 1)
    Vector2D operator*(const Vector2D& v) const {
        float xNew = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * 1.0f;
        float yNew = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * 1.0f;
        return Vector2D(xNew, yNew);
    }
};

} // namespace GameMath

