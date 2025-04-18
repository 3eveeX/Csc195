#pragma once
#include <iostream>

using age_t = unsigned short;

class Human {
public:
    enum class Type {
        STUDENT,
        TEACHER
    };
public:
    Human() {
        std::cout << "human constructor\n";
        _count++;
    }
    Human(std::string name, age_t age) {
        m_name = name;
        _age = age;

        
        _count++;
    }
    virtual Type getType() = 0;


    ~Human() {
        std::cout << "destructor\n";
        _count--;
    }
    std::string getName() { return m_name; }
    age_t getAge() {
        return _age;
    }
    void setAge(age_t age);

    static int getCount() {
        return _count;
    }

    virtual void Read();
    virtual void Write();
protected:
    std::string m_name;
    age_t _age = 0;
    static int _count;
    static const float m_tax;

};

void func(); 

