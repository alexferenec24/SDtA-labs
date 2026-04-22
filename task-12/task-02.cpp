#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Car
{
    string name;
    int year{};
    double mileage{};
};

void showCars(const list<Car>& cars)
{
    if (cars.empty())
    {
        cout << "List is empty.\n";
        return;
    }

    int i = 1;
    for (const auto & car : cars)
    {
        cout << i << ". " << car.name << " | " << car.year << " | " << car.mileage << " km\n";
        i++;
    }
}

Car inputCar()
{
    Car c;
    cin.ignore();

    cout << "Enter car name: ";
    getline(cin, c.name);

    cout << "Enter year: ";
    cin >> c.year;

    cout << "Enter mileage: ";
    cin >> c.mileage;

    return c;
}

void addFront(list<Car>& cars)
{
    Car c = inputCar();
    cars.push_front(c);
}

void addBack(list<Car>& cars)
{
    Car c = inputCar();
    cars.push_back(c);
}

void insertByPosition(list<Car>& cars)
{
    int pos;
    cout << "Enter position: ";
    cin >> pos;

    if (pos < 1 || pos > cars.size() + 1)
    {
        cout << "Wrong position.\n";
        return;
    }

    Car c = inputCar();

    auto it = cars.begin();
    for (int i = 1; i < pos; i++)
        ++it;

    cars.insert(it, c);
}

void insertAfterName(list<Car>& cars)
{
    if (cars.empty())
    {
        cout << "List is empty.\n";
        return;
    }

    cin.ignore();
    string x;
    cout << "Enter existing car name: ";
    getline(cin, x);

    for (auto it = cars.begin(); it != cars.end(); ++it)
    {
        if (it->name == x)
        {
            Car c;
            cout << "Enter new car name: ";
            getline(cin, c.name);
            cout << "Enter year: ";
            cin >> c.year;
            cout << "Enter mileage: ";
            cin >> c.mileage;

            ++it;
            cars.insert(it, c);
            return;
        }
    }

    cout << "Car not found.\n";
}

void insertBeforeName(list<Car>& cars)
{
    if (cars.empty())
    {
        cout << "List is empty.\n";
        return;
    }

    cin.ignore();
    string x;
    cout << "Enter existing car name: ";
    getline(cin, x);

    for (auto it = cars.begin(); it != cars.end(); ++it)
    {
        if (it->name == x)
        {
            Car c;
            cout << "Enter new car name: ";
            getline(cin, c.name);
            cout << "Enter year: ";
            cin >> c.year;
            cout << "Enter mileage: ";
            cin >> c.mileage;

            cars.insert(it, c);
            return;
        }
    }

    cout << "Car not found.\n";
}

void findCar(const list<Car>& cars)
{
    if (cars.empty())
    {
        cout << "List is empty.\n";
        return;
    }

    cin.ignore();
    string x;
    cout << "Enter car name: ";
    getline(cin, x);

    for (const auto & car : cars)
    {
        if (car.name == x)
        {
            cout << "Automobile with name " << x << " is in the list.\n";
            return;
        }
    }

    cout << "Automobile with name " << x << " is not in the list.\n";
}

void deleteByYear(list<Car>& cars)
{
    if (cars.empty())
    {
        cout << "List is empty.\n";
        return;
    }

    int y;
    cout << "Enter year: ";
    cin >> y;

    for (auto it = cars.begin(); it != cars.end(); )
    {
        if (it->year < y)
            it = cars.erase(it);
        else
            ++it;
    }
}

int main()
{
    list<Car> cars;
    int choice;

    do
    {
        cout << "\n1 - Add to front\n";
        cout << "2 - Add to back\n";
        cout << "3 - Insert by position\n";
        cout << "4 - Insert after given element\n";
        cout << "5 - Insert before given element\n";
        cout << "6 - Search by name\n";
        cout << "7 - Delete cars with year less than entered value\n";
        cout << "8 - Show list\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
            addFront(cars);
        else if (choice == 2)
            addBack(cars);
        else if (choice == 3)
            insertByPosition(cars);
        else if (choice == 4)
            insertAfterName(cars);
        else if (choice == 5)
            insertBeforeName(cars);
        else if (choice == 6)
            findCar(cars);
        else if (choice == 7)
            deleteByYear(cars);
        else if (choice == 8)
            showCars(cars);
        else if (choice == 0)
            cout << "Exit.\n";
        else
            cout << "Wrong choice.\n";
    }
    while (choice != 0);

    return 0;
}