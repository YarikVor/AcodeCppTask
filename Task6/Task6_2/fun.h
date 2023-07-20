#pragma once

#include <string>

struct Student
{
    public:
        std::string name;
        int rating;
};

template <typename T>
struct Array
{
    public:
        int length = 0;
        T *array = nullptr;

        Array(int count): length(count), array(new T[count])
        {
        }
};

void inputStudents(Array<Student> &students);
void sortingStudentsByRating(Array<Student> &studentsArray);
void printStudents(Array<Student> &studentsArray);
