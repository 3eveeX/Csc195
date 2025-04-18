#pragma once
#include <iostream>
#include <string>

class Shape {
public:
    Shape() {}
    ~Shape() {}

    virtual float Area() = 0;
};
