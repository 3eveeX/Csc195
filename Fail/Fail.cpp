#include <iostream>
#include <vector>
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"


using namespace std;


int main() {
    Shape shape;
    
    shape.Add(Shape::Type::CIRCLE);
    shape.Add(Shape::Type::RECTANGLE);

    shape.Write();

   

    return 0;
};
