#include "IntArray.h"
#include <cassert>

IntArray::IntArray(int length)
    : m_length(length), m_array(new int[length]{ 0 })
{
    assert(length >= 0);
}

IntArray::IntArray(int length, const int* array): IntArray(length)
{
    for(int i = 0; i < length; ++i)
        m_array[i] = array[i];
}

IntArray::IntArray(const IntArray &array)
    : IntArray(array.m_length, array.m_array)
{
}

IntArray& IntArray::operator=(const IntArray& intArray)
{
    if(this == &intArray)
        return *this;

    delete[] m_array;

    m_length = intArray.m_length;

    m_array = new int[m_length];

    for(int i = 0; i < m_length; ++i)
        m_array[i] = intArray.m_array[i];
}

IntArray::~IntArray()
{
    delete[] m_array;
}

int& IntArray::operator[](const int index)
{
    assert(0 <= index && index < m_length);
    return m_array[index];
}

const int& IntArray::operator[](const int index) const
{
    return (*this)[index];
}

std::ostream& operator<<(std::ostream& out, const IntArray &average)
{
    const int len = average.m_length;
    const int *arr = average.m_array;

    for(int i = 0; i < len; ++i)
    {
        out << arr[i] << " ";
    }

    return out;
}


