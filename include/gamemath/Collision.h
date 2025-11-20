#pragma once
#include "Vector2D.h"
#include <cmath>

namespace GameMath {

struct AABB {
    Vector2D min;
    Vector2D max;

    AABB() = default;
    AABB(const Vector2D& min_, const Vector2D& max_) : min(min_), max(max_) {}

    static bool intersects(const AABB& a, const AABB& b) {
        // Separating Axis Theorem for AABBs
        if (a.max.x < b.min.x || a.min.x > b.max.x) return false;
        if (a.max.y < b.min.y || a.min.y > b.max.y) return false;
        return true;
    }
};

struct Circle {
    Vector2D center;
    float radius;

    Circle() : center(0.0f, 0.0f), radius(0.0f) {}
    Circle(const Vector2D& c, float r) : center(c), radius(r) {}

    static bool intersects(const Circle& a, const Circle& b) {
        float distSq = (a.center.x - b.center.x) * (a.center.x - b.center.x) +
                       (a.center.y - b.center.y) * (a.center.y - b.center.y);
        float radSum = a.radius + b.radius;
        return distSq <= radSum * radSum;
    }
};

} // namespace GameMath

