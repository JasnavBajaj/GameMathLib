#include <iostream>
#include <cassert>
#include <cmath>
#include "../include/gamemath/Vector2D.h"
#include "../include/gamemath/Vector3D.h"
#include "../include/gamemath/Matrix3x3.h"
#include "../include/gamemath/Collision.h"

using namespace GameMath;

void test_vector2d() {
    // Test construction
    Vector2D v1(3.0f, 4.0f);
    assert(v1.x == 3.0f && v1.y == 4.0f);

    // Test addition
    Vector2D v2(1.0f, 2.0f);
    Vector2D v3 = v1 + v2;
    assert(v3.x == 4.0f && v3.y == 6.0f);

    // Test subtraction
    Vector2D v4 = v1 - v2;
    assert(v4.x == 2.0f && v4.y == 2.0f);

    // Test scalar multiplication
    Vector2D v5 = v1 * 2.0f;
    assert(v5.x == 6.0f && v5.y == 8.0f);

    // Test length
    assert(std::abs(v1.length() - 5.0f) < 0.001f);

    // Test normalize
    Vector2D v6 = v1.normalize();
    assert(std::abs(v6.length() - 1.0f) < 0.001f);

    // Test dot product
    float dot = v1.dot(v2);
    assert(dot == 11.0f); // 3*1 + 4*2

    // Test distance
    float dist = Vector2D::distance(v1, v2);
    assert(std::abs(dist - std::sqrt(8.0f)) < 0.001f);

    std::cout << "✓ Vector2D tests passed\n";
}

void test_vector3d() {
    Vector3D v1(1.0f, 0.0f, 0.0f);
    Vector3D v2(0.0f, 1.0f, 0.0f);

    // Test cross product
    Vector3D v3 = v1.cross(v2);
    assert(std::abs(v3.x - 0.0f) < 0.001f);
    assert(std::abs(v3.y - 0.0f) < 0.001f);
    assert(std::abs(v3.z - 1.0f) < 0.001f);

    // Test addition
    Vector3D v4 = v1 + v2;
    assert(v4.x == 1.0f && v4.y == 1.0f && v4.z == 0.0f);

    // Test length
    Vector3D v5(3.0f, 4.0f, 0.0f);
    assert(std::abs(v5.length() - 5.0f) < 0.001f);

    std::cout << "✓ Vector3D tests passed\n";
}

void test_matrix() {
    // Test identity
    Matrix3x3 identity;
    assert(identity.m[0][0] == 1.0f && identity.m[1][1] == 1.0f);

    // Test scale
    Matrix3x3 scale = Matrix3x3::scale(2.0f, 3.0f);
    assert(scale.m[0][0] == 2.0f && scale.m[1][1] == 3.0f);

    // Test rotation (90 degrees)
    Matrix3x3 rot = Matrix3x3::rotation(M_PI / 2.0f);
    assert(std::abs(rot.m[0][0]) < 0.001f); // cos(90°) ≈ 0
    assert(std::abs(rot.m[1][1]) < 0.001f);

    std::cout << "✓ Matrix3x3 tests passed\n";
}

void test_collision() {
    // Test AABB collision
    AABB box1(Vector2D(0, 0), Vector2D(10, 10));
    AABB box2(Vector2D(5, 5), Vector2D(15, 15));
    AABB box3(Vector2D(20, 20), Vector2D(30, 30));

    assert(AABB::intersects(box1, box2) == true);
    assert(AABB::intersects(box1, box3) == false);

    // Test circle collision
    Circle c1(Vector2D(0, 0), 5.0f);
    Circle c2(Vector2D(8, 0), 5.0f);
    Circle c3(Vector2D(20, 0), 5.0f);

    assert(Circle::intersects(c1, c2) == true);
    assert(Circle::intersects(c1, c3) == false);

    std::cout << "✓ Collision tests passed\n";
}

int main() {
    std::cout << "Running GameMathLib tests...\n\n";
    
    test_vector2d();
    test_vector3d();
    test_matrix();
    test_collision();
    
    std::cout << "\n✅ All tests passed!\n";
    return 0;
}
