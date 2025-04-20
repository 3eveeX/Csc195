#pragma once
#include <iostream>
#include <vector>

class Shape {
public:
    enum class Type {
        CIRCLE,
        RECTANGLE,
        SHAPE
    };

    Shape() {}
    ~Shape();
    virtual Type getType() { return Type::SHAPE; }
    virtual float Area() { return 0; }
    void Add(Type type);
    std::vector<Shape*> getShapes() { return shapes; }
    void Write();
private: 
    std::vector<Shape*> shapes;
};
