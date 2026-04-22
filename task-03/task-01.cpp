#include <iostream>

using namespace std;

struct Worker
{
    char surnameAndInitials[50];
    char position[50];
    int startYear;
    double salary;
};

int experience(const Worker& w, int currentYear)
{
    return currentYear - w.startYear;
}

double salaryWithTax(const Worker& w)
{
    return w.salary * 0.67;
}

int main()
{
    int n, currentYear;

    cout << "Enter number of workers: ";
    cin >> n;

    Worker workers[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Worker " << i + 1 << endl;
        cout << "Surname_and_initials: ";
        cin >> workers[i].surnameAndInitials;
        cout << "Position: ";
        cin >> workers[i].position;
        cout << "Start_year: ";
        cin >> workers[i].startYear;
        cout << "Salary: ";
        cin >> workers[i].salary;
    }

    cout << "Enter current year: ";
    cin >> currentYear;

    for (int i = 0; i < n; i++)
    {
        cout << "Worker: " << workers[i].surnameAndInitials << endl;
        cout << "Experience: " << experience(workers[i], currentYear) << " years" << endl;
        cout << "Salary after tax: " << salaryWithTax(workers[i]) << endl;
        cout << endl;
    }

    return 0;
}