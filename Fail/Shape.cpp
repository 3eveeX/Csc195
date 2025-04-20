#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;




Shape::~Shape()
{
	for (Shape* shape : shapes) {
		delete shape;
	}
	shapes.clear();
}

void Shape::Add(Type type)
{
	float r;
	float w;
	float l;
	Shape* shape = nullptr;
	switch (type)
	{
	case Shape::Type::CIRCLE:
		shape = new Circle;
		cout << "Radius: ";
		cin >> r;
		dynamic_cast<Circle*>(shape)->SetRadius((float)r);
		break;
	case Shape::Type::RECTANGLE:
		cout << "---Rectangle---" << endl;
		cout << "Width: ";
		cin >> w;
		cout << "Length: ";
		cin >> l;
		shape = new Rectangle(w, l);
		break;
	default:
		break;
	}
	shapes.push_back(shape);
}

void Shape::Write() 
{
	cout << "---Areas--" << endl;
	for (int i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->getType() == Shape::Type::CIRCLE) {
			cout << "Circle ";
		}
		else if (shapes[i]->getType() == Shape::Type::RECTANGLE) {
			cout << "Rectangle ";
		}
		cout << "Area: " << shapes[i]->Area() << endl;
		if (shapes[i]->getType() == Shape::Type::CIRCLE) {
			cout << "Radius: " << dynamic_cast<Circle*>(shapes[i])->GetRadius() << endl;
		}
	}
}
