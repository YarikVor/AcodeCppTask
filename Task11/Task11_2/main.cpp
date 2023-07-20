#include <iostream>
#include <string>

using namespace std;

class Fruit {
private:
    string m_color;
    string m_name;

public:
    Fruit(string name, string color): m_name(name), m_color(color) { }
    const string getName() const { return m_name; }
    const string getColor() const { return m_color; }
};

class Banana: public Fruit
{
public:
    Banana(): Fruit("banana", "yellow") { }
};

class Apple: public Fruit
{
public:
    Apple(string color): Apple("apple", color) { }
    Apple(string name, string color) : Fruit(name, color) { }
};

class GrannySmith: public Apple
{
public:
    GrannySmith(): Apple("Granny Smith apple", "green") {}
};

int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
