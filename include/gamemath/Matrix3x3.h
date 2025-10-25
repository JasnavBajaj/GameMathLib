#pragma once
#include "Vector2D.h"
#include <cmath>

namespace GameMath {

class Matrix3x3 {
public:
    float m[3][3];

    // Identity matrix
    Matrix3x3() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] = (i == j) ? 1.0f : 0.0f;
            }
        }
    }

    // Create rotation matrix
    static Matrix3x3 rotation(float angleRadians) {
        Matrix3x3 mat;
        float c = std::cos(angleRadians);
        float s = std::sin(angleRadians);
        
        mat.m[0][0] = c;  mat.m[0][1] = -s; mat.m[0][2] = 0;
        mat.m[1][0] = s;  mat.m[1][1] = c;  mat.m[1][2] = 0;
        mat.m[2][0] = 0;  mat.m[2][1] = 0;  mat.m[2][2] = 1;
        
        return mat;
    }

    // Create scale matrix
    static Matrix3x3 scale(float sx, float sy) {
        Matrix3x3 mat;
        mat.m[0][0] = sx;
        mat.m[1][1] = sy;
        return mat;
    }

    // Matrix multiplication
    Matrix3x3 operator*(const Matrix3x3& other) const {
        Matrix3x3 result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.m[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    result.m[i][j] += m[i][k] * other.m[k][j];
                }
            }
        }
        return result;
    }
};

} // namespace GameMath
