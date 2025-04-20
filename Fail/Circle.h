#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
    Circle();

    float Area() override {
        return 3.14f * m_radius * m_radius;
    }

    void SetRadius(float radius);
    float GetRadius();
    Type getType() override { return Type::CIRCLE; }
private:
    float m_radius;
};
