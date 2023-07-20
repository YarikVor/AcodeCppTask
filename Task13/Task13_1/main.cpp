#include <iostream>

#include "SamePair.h"

using namespace std;

int main()
{
	SamePair<int> p1(6, 9);
	std::cout << "SamePair: " << p1.first() << ' ' << p1.second() << '\n';

	const SamePair<double> p2(3.4, 7.8);
	std::cout << "SamePair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
