#pragma once
#include "Vector2D.h"

namespace GameMath {

// Axis-Aligned Bounding Box
struct AABB {
    Vector2D min;
    Vector2D max;

    AABB(const Vector2D& min, const Vector2D& max) : min(min), max(max) {}

    // Check collision between two AABBs
    static bool intersects(const AABB& a, const AABB& b) {
        return (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
               (a.min.y <= b.max.y && a.max.y >= b.min.y);
    }
};

// Circle collision
struct Circle {
    Vector2D center;
    float radius;

    Circle(const Vector2D& center, float radius) : center(center), radius(radius) {}

    static bool intersects(const Circle& a, const Circle& b) {
        float distance = Vector2D::distance(a.center, b.center);
        return distance < (a.radius + b.radius);
    }
};

} // namespace GameMath
