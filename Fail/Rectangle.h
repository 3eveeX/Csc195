#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(float w, float h);

    float Area() override {
        return m_width * m_height;
    }
    Type getType() override { return Type::RECTANGLE; }
private:
    float m_width;
    float m_height;
};

