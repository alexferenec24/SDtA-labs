#include <iostream>

using namespace std;

enum Faculty
{
    IT,
    ECONOMICS,
    LAW,
    MANAGEMENT
};

struct Student
{
    char surname[50];
    int course;
    double averageGrade;
    Faculty faculty;
};

int main()
{
    const int studentCount = 5;
    Student students[studentCount];

    for (int i = 0; i < studentCount; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Surname: ";
        cin >> students[i].surname;
        cout << "Course: ";
        cin >> students[i].course;
        cout << "Average grade: ";
        cin >> students[i].averageGrade;
        cout << "Faculty (0-IT, 1-Economics, 2-Law, 3-Management): ";
        int f;
        cin >> f;
        students[i].faculty = (Faculty)f;
    }

    int neededFaculty;
    cout << "Enter faculty number: ";
    cin >> neededFaculty;

    cout << "Students of selected faculty:" << endl;
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].faculty == (Faculty)neededFaculty)
        {
            cout << students[i].surname << " "
                 << students[i].course << " "
                 << students[i].averageGrade << endl;
        }
    }

    double sum = 0;
    for (int i = 0; i < studentCount; i++)
    {
        sum += students[i].averageGrade;
    }

    cout << "Average grade: " << sum / studentCount << endl;

    return 0;
}