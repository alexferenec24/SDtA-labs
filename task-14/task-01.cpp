#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 10> marks;
    int sum = 0;

    cout << "Enter 10 marks:\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> marks[i];
        sum += marks[i];
    }

    double average = (double)sum / 10;

    int minMark = marks[0];
    int maxMark = marks[0];

    for (int i = 1; i < 10; i++)
    {
        if (marks[i] < minMark)
            minMark = marks[i];

        if (marks[i] > maxMark)
            maxMark = marks[i];
    }

    int countAboveAverage = 0;
    for (int i = 0; i < 10; i++)
    {
        if (marks[i] > average)
            countAboveAverage++;
    }

    array<int, 10> ascMarks = marks;
    array<int, 10> descMarks = marks;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (ascMarks[j] > ascMarks[j + 1])
            {
                int temp = ascMarks[j];
                ascMarks[j] = ascMarks[j + 1];
                ascMarks[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (descMarks[j] < descMarks[j + 1])
            {
                int temp = descMarks[j];
                descMarks[j] = descMarks[j + 1];
                descMarks[j + 1] = temp;
            }
        }
    }

    cout << "Average mark: " << average << endl;
    cout << "Minimum mark: " << minMark << endl;
    cout << "Maximum mark: " << maxMark << endl;
    cout << "Count of marks above average: " << countAboveAverage << endl;

    cout << "Marks in ascending order: ";
    for (int i = 0; i < 10; i++)
        cout << ascMarks[i] << " ";
    cout << endl;

    cout << "Marks in descending order: ";
    for (int i = 0; i < 10; i++)
        cout << descMarks[i] << " ";
    cout << endl;

    return 0;
}