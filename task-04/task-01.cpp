#include <iostream>
#include <cstring>

using namespace std;

struct ABITURIENT
{
    char NAME[50];
    char GENDER[20];
    char SPEC[50];
    int EXAM[3];
};

double averageBall(const ABITURIENT& a)
{
    return (a.EXAM[0] + a.EXAM[1] + a.EXAM[2]) / 3.0;
}

int countVowels(const char s[])
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        if (ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
            count++;
    }

    return count;
}

void inputAbiturients(ABITURIENT a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Abiturient " << i + 1 << endl;
        cout << "Enter surname_and_initials: ";
        cin >> a[i].NAME;
        cout << "Enter gender: ";
        cin >> a[i].GENDER;
        cout << "Enter specialty: ";
        cin >> a[i].SPEC;

        cout << "Enter 3 exam results: ";
        for (int j = 0; j < 3; j++)
            cin >> a[i].EXAM[j];

        cout << endl;
    }
}

void printAbiturients(const ABITURIENT a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Surname and initials: " << a[i].NAME << endl;
        cout << "Gender: " << a[i].GENDER << endl;
        cout << "Specialty: " << a[i].SPEC << endl;
        cout << "Exam results: ";
        for (int j = 0; j < 3; j++)
            cout << a[i].EXAM[j] << " ";
        cout << endl;
        cout << "Average score: " << averageBall(a[i]) << endl;
        cout << endl;
    }
}

void showMoreThan3Vowels(const ABITURIENT a[], int n)
{
    cout << "Abiturients whose surname has more than 3 vowels:" << endl;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (countVowels(a[i].NAME) > 3)
        {
            cout << a[i].NAME << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No such abiturients." << endl;

    cout << endl;
}

void showBelowPassingScore(const ABITURIENT a[], int n, double passingScore)
{
    cout << "Abiturients with score below passing score:" << endl;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (averageBall(a[i]) < passingScore)
        {
            cout << a[i].NAME << " - " << a[i].SPEC << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No such abiturients." << endl;

    cout << endl;
}

void sortBySurname(ABITURIENT a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(a[j].NAME, a[j + 1].NAME) > 0)
            {
                ABITURIENT temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void deleteAverageFive(ABITURIENT a[], int& n)
{
    for (int i = 0; i < n; )
    {
        if (averageBall(a[i]) == 5.0)
        {
            for (int j = i; j < n - 1; j++)
                a[j] = a[j + 1];

            n--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of abiturients: ";
    cin >> n;

    ABITURIENT a[100];

    inputAbiturients(a, n);

    showMoreThan3Vowels(a, n);

    double passingScore;
    cout << "Enter passing score: ";
    cin >> passingScore;
    cout << endl;

    showBelowPassingScore(a, n, passingScore);

    sortBySurname(a, n);
    cout << "Array sorted alphabetically:" << endl;
    printAbiturients(a, n);

    deleteAverageFive(a, n);
    cout << "Array after deleting abiturients with average score 5:" << endl;
    printAbiturients(a, n);

    return 0;
}