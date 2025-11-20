#include <gtest/gtest.h>
#include <cmath>

#include <gamemath/Vector2D.h>
#include <gamemath/Vector3D.h>
#include <gamemath/Matrix3x3.h>
#include <gamemath/Collision.h>

using namespace GameMath;

TEST(Vector2DTests, BasicOperations) {
    Vector2D v1(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v1.x, 3.0f);
    EXPECT_FLOAT_EQ(v1.y, 4.0f);

    Vector2D v2(1.0f, 2.0f);
    Vector2D v3 = v1 + v2;
    EXPECT_FLOAT_EQ(v3.x, 4.0f);
    EXPECT_FLOAT_EQ(v3.y, 6.0f);

    Vector2D v4 = v1 - v2;
    EXPECT_FLOAT_EQ(v4.x, 2.0f);
    EXPECT_FLOAT_EQ(v4.y, 2.0f);

    Vector2D v5 = v1 * 2.0f;
    EXPECT_FLOAT_EQ(v5.x, 6.0f);
    EXPECT_FLOAT_EQ(v5.y, 8.0f);

    Vector2D v6 = v1 / 2.0f;
    EXPECT_FLOAT_EQ(v6.x, 1.5f);
    EXPECT_FLOAT_EQ(v6.y, 2.0f);
}

TEST(Vector2DTests, LengthAndDot) {
    Vector2D v1(3.0f, 4.0f);
    EXPECT_NEAR(v1.length(), 5.0f, 1e-3);

    Vector2D norm = v1.normalize();
    EXPECT_NEAR(norm.length(), 1.0f, 1e-3);

    Vector2D v2(1.0f, 2.0f);
    float dot = v1.dot(v2);
    EXPECT_FLOAT_EQ(dot, 11.0f); // 3*1 + 4*2

    float dist = Vector2D::distance(v1, v2);
    EXPECT_NEAR(dist, std::sqrt(8.0f), 1e-3);
}

TEST(Vector3DTests, CrossAndLength) {
    Vector3D v1(1.0f, 0.0f, 0.0f);
    Vector3D v2(0.0f, 1.0f, 0.0f);

    Vector3D v3 = v1.cross(v2);
    EXPECT_NEAR(v3.x, 0.0f, 1e-3);
    EXPECT_NEAR(v3.y, 0.0f, 1e-3);
    EXPECT_NEAR(v3.z, 1.0f, 1e-3);

    Vector3D v4 = v1 + v2;
    EXPECT_FLOAT_EQ(v4.x, 1.0f);
    EXPECT_FLOAT_EQ(v4.y, 1.0f);
    EXPECT_FLOAT_EQ(v4.z, 0.0f);

    Vector3D v5(3.0f, 4.0f, 0.0f);
    EXPECT_NEAR(v5.length(), 5.0f, 1e-3);
}

TEST(Matrix3x3Tests, IdentityScaleRotation) {
    Matrix3x3 identity;
    EXPECT_FLOAT_EQ(identity.m[0][0], 1.0f);
    EXPECT_FLOAT_EQ(identity.m[1][1], 1.0f);

    Matrix3x3 scale = Matrix3x3::scale(2.0f, 3.0f);
    EXPECT_FLOAT_EQ(scale.m[0][0], 2.0f);
    EXPECT_FLOAT_EQ(scale.m[1][1], 3.0f);

    Matrix3x3 rot = Matrix3x3::rotation(static_cast<float>(M_PI) / 2.0f);
    EXPECT_NEAR(rot.m[0][0], 0.0f, 1e-3); // cos(90°) ≈ 0
    EXPECT_NEAR(rot.m[1][1], 0.0f, 1e-3);
}

TEST(CollisionTests, AABBAndCircle) {
    AABB box1(Vector2D(0, 0), Vector2D(10, 10));
    AABB box2(Vector2D(5, 5), Vector2D(15, 15));
    AABB box3(Vector2D(20, 20), Vector2D(30, 30));

    EXPECT_TRUE(AABB::intersects(box1, box2));
    EXPECT_FALSE(AABB::intersects(box1, box3));

    Circle c1(Vector2D(0, 0), 5.0f);
    Circle c2(Vector2D(8, 0), 5.0f);
    Circle c3(Vector2D(20, 0), 5.0f);

    EXPECT_TRUE(Circle::intersects(c1, c2));
    EXPECT_FALSE(Circle::intersects(c1, c3));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

