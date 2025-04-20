#include "Person.h"
#include <iostream>
#include <string>


using namespace std;

struct Person
{
float weight;
int age;
};

int main()
{

    Student student;
    student.setName("Dia");

    Person person;
    person.age = 17;

    unsigned int i = 88;
    //printf("%d\n", i);
    cout << &i << endl;

    cout << sizeof(int) << endl;
    cout << sizeof(Person) << endl;
    i++;
    i += 5;
    cout << i << endl;


    char c = 'A';
    cout << (int)c << endl;

    

    cout << "Hello World!" << endl;
    cout << "Git is now tracking this project!" << endl;
    return 0;
}

