#include <iostream>
#include <gamemath/Vector2D.h>
#include <gamemath/Vector3D.h>
#include <gamemath/Matrix3x3.h>
#include <gamemath/Collision.h>

using namespace GameMath;

int main() {
    Vector2D pos(3.0f, 4.0f);
    std::cout << "pos = (" << pos.x << ", " << pos.y << ")\n";
    std::cout << "length(pos) = " << pos.length() << "\n\n";

    Matrix3x3 rot = Matrix3x3::rotation(3.14159f / 2.0f); // ~90°
    Vector2D rotated = rot * pos;
    std::cout << "Rotated pos ≈ (" << rotated.x << ", " << rotated.y << ")\n\n";

    // Simple collision
    AABB box1(Vector2D(0, 0), Vector2D(10, 10));
    AABB box2(Vector2D(5, 5), Vector2D(15, 15));

    std::cout << "AABB intersection: "
              << (AABB::intersects(box1, box2) ? "true" : "false") << "\n";

    Circle c1(Vector2D(0, 0), 5.0f);
    Circle c2(Vector2D(8, 0), 5.0f);

    std::cout << "Circle intersection: "
              << (Circle::intersects(c1, c2) ? "true" : "false") << "\n";

    return 0;
}

