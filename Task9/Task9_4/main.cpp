#include <iostream>

#include "include/FixedFloat.h"

using namespace std;

void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout << (FixedFloat(0.75) + FixedFloat(1.23) == FixedFloat(1.98)) << '\n'; // ��� �������� �������������, �������� ������������
	std::cout << (FixedFloat(0.75) + FixedFloat(1.50) == FixedFloat(2.25)) << '\n'; // ��� �������� �������������, ������������
	std::cout << (FixedFloat(-0.75) + FixedFloat(-1.23) == FixedFloat(-1.98)) << '\n'; // ��� �������� �������������, �������� ������������
	std::cout << (FixedFloat(-0.75) + FixedFloat(-1.50) == FixedFloat(-2.25)) << '\n'; // ��� �������� �������������, ������������
	std::cout << (FixedFloat(0.75) + FixedFloat(-1.23) == FixedFloat(-0.48)) << '\n'; // ������ �������� �������������, �������� ������������
	std::cout << (FixedFloat(0.75) + FixedFloat(-1.50) == FixedFloat(-0.75)) << '\n'; // ������ �������� �������������, �������� ������������
	std::cout << (FixedFloat(-0.75) + FixedFloat(1.23) == FixedFloat(0.48)) << '\n'; // ������ �������� �������������, �������� ������������
	std::cout << (FixedFloat(-0.75) + FixedFloat(1.50) == FixedFloat(0.75)) << '\n'; // ������ �������� �������������, �������� ������������

    FixedFloat a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // ������� 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';
}

int main()
{
	FixedFloat a(37, 58);
	std::cout << a << '\n';

	FixedFloat b(-3, 9);
	std::cout << b << '\n';

	FixedFloat c(4, -7);
	std::cout << c << '\n';

	FixedFloat d(-5, -7);
	std::cout << d << '\n';

	FixedFloat e(0, -3);
	std::cout << e << '\n';

    FixedFloat a1(0.03);
	std::cout << a1 << '\n';

	FixedFloat b1(-0.03);
	std::cout << b1 << '\n';

	FixedFloat c1(4.01); // ����������, ��� 4.0099999..., ������� ��� ����� ��� �� ���������
	std::cout << c1 << '\n';

	FixedFloat d1(-4.01); // ����������, ��� -4.0099999..., ������� ��� ����� ��� �� ���������
	std::cout << d1 << '\n';

    SomeTest();

	return 0;
}
