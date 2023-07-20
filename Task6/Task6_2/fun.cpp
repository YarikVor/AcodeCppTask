#pragma once

#include <iostream>
#include <string>
#include "fun.h"

using namespace std;

void inputStudents(Array<Student> &students)
{
    auto arr = students.array;
    for(int i = 0, len = students.length; i < len; ++i)
    {
        Student &studentLink = arr[i];
        cin >> studentLink.name;
        cin >> studentLink.rating;
    }
}

void sortingStudentsByRating(Array<Student> &studentsArray)
{
    auto students = studentsArray.array;
    auto len = studentsArray.length;
    auto decLen = len - 1;

    for(int start = 0; start < len; ++start)
    {
        for(int offset = start; offset < decLen; ++offset)
        {
            if(students[offset].rating < students[offset + 1].rating)
            {
                swap(students[offset], students[offset + 1]);
            }
        }
    }
}

void printStudents(Array<Student> &studentsArray)
{
    auto students = studentsArray.array;
    auto len = studentsArray.length;

    for(int i = 0; i < len; ++i)
    {
        Student &studentLink = students[i];

        cout << studentLink.name
            << " got a grade of "
            << studentLink.rating
            << endl;
    }
}
