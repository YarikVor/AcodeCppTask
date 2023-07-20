#ifndef INTARRAY_H
#define INTARRAY_H

#include <cstdint>
#include <iostream>

class IntArray
{
    public:
        IntArray(int m_length);
        IntArray(int m_length, const int *array);
        IntArray(const IntArray &array);

        virtual ~IntArray();

        int& operator[] (const int index);
        const int& operator[] (const int index) const;

        int getLength() const {return m_length; }
        friend std::ostream& operator<<(std::ostream& out, const IntArray& average);

        IntArray& operator=(const IntArray &array);

    protected:

    private:
        int m_length = 0;
        int *m_array = nullptr;
};

#endif // INTARRAY_H
