#include <iostream>

namespace program
{
    template<typename T>
    void swap(T &elem1, T &elem2)
    {
        auto temp = elem1;
        elem1 = elem2;
        elem2 = temp;
    }
}

int main()
{
    int a = 1;
    int b = 300;

    program::swap(a, b);

    std::cout << "a: "
        << a
        << ", b: "
        << b
        << std::endl;

    return 0;
}
