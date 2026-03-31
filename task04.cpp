#include <iostream>
#include <string>
using namespace std;

struct ABITURIENT
{
    string name;
    string gender;
    string spec;
    int exam[3];
};

int countVowels(string s)
{
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char Vowels = tolower(s[i]);
        if (Vowels == 'a' || Vowels == 'e' || Vowels == 'i' || Vowels == 'o' || Vowels == 'u' || Vowels == 'y')
            c++;
    }
    return c;
}

void showVowelNames(ABITURIENT a[], int n)
{
    cout << "Applicants with no more than 3 vowels in the name:\n";
    for (int i = 0; i < n; i++)
        if (countVowels(a[i].name) <= 3)
            cout << a[i].name << endl;
}

double average(ABITURIENT a)
{
    return (a.exam[0] + a.exam[1] + a.exam[2]) / 3.0;
}

void showBelowPass(ABITURIENT a[], int n, int pass)
{
    bool found = false;

    for (int i = 0; i < n; i++)
        if (average(a[i]) < pass)
        {
            cout << a[i].name << " " << a[i].spec << endl;
            found = true;
        }

    if (!found)
        cout << "No such students\n";
}

void sortByName(ABITURIENT a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].name > a[j].name)
                swap(a[i], a[j]);
}

void printArray(ABITURIENT a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i].name << " "
            << a[i].gender << " "
            << a[i].spec << " "
            << a[i].exam[0] << " "
            << a[i].exam[1] << " "
            << a[i].exam[2] << endl;
    }
}

void deleteAvgFive(ABITURIENT a[], int& n)
{
    for (int i = 0; i < n; i++)
    {
        if (average(a[i]) == 5)
        {
            for (int j = i; j < n - 1; j++)
                a[j] = a[j + 1];
            n--;
            i--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of applicants: ";
    cin >> n;

    ABITURIENT a[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        cin >> a[i].name;

        cout << "Enter gender: ";
        cin >> a[i].gender;

        cout << "Enter specialty: ";
        cin >> a[i].spec;

        cout << "Enter 3 exam scores: ";
        cin >> a[i].exam[0] >> a[i].exam[1] >> a[i].exam[2];
    }

    showVowelNames(a, n);

    int pass;
    cout << "Enter passing score: ";
    cin >> pass;

    showBelowPass(a, n, pass);

    sortByName(a, n);

    cout << "\nSorted array:\n";
    printArray(a, n);

    deleteAvgFive(a, n);

    cout << "\nArray after deleting students with average score = 5:\n";
    printArray(a, n);

    return 0;
}