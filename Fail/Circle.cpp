#include "Circle.h"

using namespace std;

Circle::Circle()
{
	cout << "---Circle---" << endl;
}

void Circle::SetRadius(float radius)
{
	m_radius = radius;
}

float Circle::GetRadius()
{
	return m_radius;
}
