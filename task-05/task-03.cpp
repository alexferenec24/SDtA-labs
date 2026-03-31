#include <iostream>
#include <string>
using namespace std;

struct CarNode
{
    string name;
    int year;
    double price;
    CarNode* next;
};

void addCar(CarNode*& head, string name, int year, double price)
{
    CarNode* temp = new CarNode{ name, year, price, NULL };

    if (!head)
    {
        head = temp;
        return;
    }

    CarNode* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

void printCars(CarNode* head, int currentYear)
{
    while (head)
    {
        if ((currentYear - head->year) > 10 && head->price < 5000)
        {
            cout << head->name << " "
                 << head->year << " "
                 << head->price << endl;
        }
        head = head->next;
    }
}

void clear(CarNode*& head)
{
    while (head)
    {
        CarNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    CarNode* head = NULL;
    int n, yearNow;

    cout << "Enter number of cars: ";
    cin >> n;

    cout << "Enter current year: ";
    cin >> yearNow;

    string name;
    int y;
    double p;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> y >> p;
        addCar(head, name, y, p);
    }

    cout << "Suitable cars:\n";
    printCars(head, yearNow);

    clear(head);
}