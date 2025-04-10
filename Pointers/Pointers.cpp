#include <iostream>

using namespace std;

class Animal {

public:
	Animal(string name) {
		m_name = name;
	}

	string getName() {
		return m_name;
	}
private:
	string m_name;
};

void func1() {
	bool b = true;
	int i = 5;
}

void func2(){
	bool b = false;
	float f = 10;
	func1();
}

void func3() {
	int i[100000];
	func3();
}

int main()
{
	int i = 5;
	float f = 4.5f;
	//func2();
	//func3();
	{
	int* p = new int(5);
	cout << *p << endl;
	delete p;
	}

	Animal* fox = new Animal("Fox");
	cout << fox->getName() << endl;
	delete fox;

}