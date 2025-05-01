#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Point.h"

#define NAME "Harold"
#define PI 3.1415926535897f
//#define DEBUG 


using names_t = std::vector<std::string>;

namespace math
{
    template<typename T1, typename T2>
    T1 max(T1 a, T2 b) {
        if (a > b) {
            return a;
        }
        else if (a < b) {
            return (T2)b;
        }
        else if (a == b) {
            return a, b;
        }
    }
    template<typename T>
    class C
    {
    protected:
        T v;
    };
}

void print(const names_t& names) {
    for (std::string name : names) {
        std::cout << name << std::endl;
    }
}

//template<typename T>
void streamIn(std::istream& istream, std::string& value) {
    std::getline(istream, value);
}

template<typename T>
void streamOut(std::ostream& ostream, const T& value) {
    ostream << value << std::endl;

}

int main()
{
    /*streamOut(std::cout, NAME);

    math::ipoint_t p(4, 5);
    std::cin >> p;

    std::cout << PI << std::endl;

    std::ofstream fstream("text.txt");
    streamOut(fstream, p);
    streamOut(fstream, 3.5f);
    streamOut(fstream, 2);
    streamOut(fstream, "F u (n)");
    fstream.close();*/

    std::string text;
    

    //streamIn(std::cin, text);
    
    std::ifstream ifstream("text.txt");
    if (ifstream.is_open()) {
        while (std::getline(ifstream, text)) {
            std::cout << text << std::endl;
        }
    }

    math::ipoint_t p1(23, 34);
    math::ipoint_t p2(12, 10);
    math::ipoint_t p3;
    p3 = p2 - p1;

    std::cout << p3 << std::endl;
    std::cout << p1.getX() << " " << p1.getY() << std::endl;


    /*std::cout << std::max(5, 10) << std::endl;
    std::cout << math::max(1.35f, 6) << std::endl;
    names_t names{ "Bubbles", "Tomato", "Boi" };
    names.push_back("Alec");
    print(names);*/
}


