#include <iostream>
#include <string>

#include "fun.h"

using namespace std;


int main()
{
    cout << "Input count students: ";
    int count;
    cin >> count;

    Array<Student> students(count);
    inputStudents(students);
    sortingStudentsByRating(students);
    printStudents(students);

    system("pause");

    return 0;
}
