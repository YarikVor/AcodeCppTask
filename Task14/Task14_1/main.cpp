#include <iostream>
#include <stdexcept>

class Fraction
{
public:
    Fraction(int numerator, int denominator)
    : m_numerator(numerator), m_denominator(denominator)
    {
        if(denominator == 0)
        {
            throw std::runtime_error("Error: denominator < 0");
        }

    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);


private:
    int m_numerator;
    int m_denominator;
};

std::ostream& operator<<(std::ostream& out, const Fraction &f1)
{
	out << f1.m_numerator << "/" << f1.m_denominator;
	return out;
}

using namespace std;

int main()
{
    int numerator;
    int denominator;

    std::cout << "Enter the numerator: ";
    std::cin >> numerator;

    std::cout << "Enter the denominator: ";
    std::cin >> denominator;

    try
    {
        Fraction fraction(numerator, denominator);
        std::cout << "Your fraction is: " << fraction << '\n';
    }
    catch (std::exception&)
    {
        std::cout << "Your fraction has an invalid denominator."
            << std::endl;
    }

}
