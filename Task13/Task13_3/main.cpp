#include <iostream>
#include <string>

using namespace std;

template <typename T>
class StringValuePair
{
public:
    StringValuePair(const std::string &first, const T &second)
        : m_first(first), m_second(second){};
    string first() const {return m_first;}
    T second() const {return m_second;}

private:
    string m_first;
    T m_second;

};

int main()
{
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
