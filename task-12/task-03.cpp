#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Order
{
    int number{};
    string surname;
    string address;
    double cost{};
    int priority{};
    string time;
    string status;
};

Order inputOrder()
{
    Order o;
    cout << "Enter order number: ";
    cin >> o.number;

    cin.ignore();
    cout << "Enter client surname: ";
    getline(cin, o.surname);

    cout << "Enter delivery address: ";
    getline(cin, o.address);

    cout << "Enter cost: ";
    cin >> o.cost;

    cout << "Enter priority: ";
    cin >> o.priority;

    cin.ignore();
    cout << "Enter order time: ";
    getline(cin, o.time);

    cout << "Enter status: ";
    getline(cin, o.status);

    return o;
}

void showOrders(const deque<Order>& orders)
{
    if (orders.empty())
    {
        cout << "No orders.\n";
        return;
    }

    for (int i = 0; i < orders.size(); i++)
    {
        cout << "\nOrder " << i + 1 << ":\n";
        cout << "Number: " << orders[i].number << endl;
        cout << "Surname: " << orders[i].surname << endl;
        cout << "Address: " << orders[i].address << endl;
        cout << "Cost: " << fixed << setprecision(2) << orders[i].cost << endl;
        cout << "Priority: " << orders[i].priority << endl;
        cout << "Time: " << orders[i].time << endl;
        cout << "Status: " << orders[i].status << endl;
    }
}

void addUrgentOrder(deque<Order>& orders)
{
    Order o = inputOrder();
    orders.push_front(o);
}

void addRegularOrder(deque<Order>& orders)
{
    Order o = inputOrder();
    orders.push_back(o);
}

void deleteDoneOrCanceled(deque<Order>& orders)
{
    for (auto it = orders.begin(); it != orders.end(); )
    {
        if (it->status == "completed" || it->status == "canceled" || it->status == "виконано" || it->status == "скасовано")
            it = orders.erase(it);
        else
            ++it;
    }
}

void searchByNumber(const deque<Order>& orders)
{
    int num;
    cout << "Enter order number: ";
    cin >> num;

    bool found = false;

    for (const auto & order : orders)
    {
        if (order.number == num)
        {
            cout << order.number << " | " << order.surname << " | " << order.status << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void searchByClient(const deque<Order>& orders)
{
    cin.ignore();
    string s;
    cout << "Enter surname: ";
    getline(cin, s);

    bool found = false;

    for (const auto & order : orders)
    {
        if (order.surname == s)
        {
            cout << order.number << " | " << order.surname << " | " << order.status << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void searchByStatus(const deque<Order>& orders)
{
    cin.ignore();
    string s;
    cout << "Enter status: ";
    getline(cin, s);

    bool found = false;

    for (const auto & order : orders)
    {
        if (order.status == s)
        {
            cout << order.number << " | " << order.surname << " | " << order.status << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void searchOrders(const deque<Order>& orders)
{
    int choice;
    cout << "1 - by number\n";
    cout << "2 - by client\n";
    cout << "3 - by status\n";
    cout << "Choose search: ";
    cin >> choice;

    if (choice == 1)
        searchByNumber(orders);
    else if (choice == 2)
        searchByClient(orders);
    else if (choice == 3)
        searchByStatus(orders);
    else
        cout << "Wrong choice.\n";
}

void editOrder(deque<Order>& orders)
{
    int num;
    cout << "Enter order number to edit: ";
    cin >> num;

    for (auto & order : orders)
    {
        if (order.number == num)
        {
            cin.ignore();

            cout << "Enter new surname: ";
            getline(cin, order.surname);

            cout << "Enter new address: ";
            getline(cin, order.address);

            cout << "Enter new cost: ";
            cin >> order.cost;

            cout << "Enter new priority: ";
            cin >> order.priority;

            cin.ignore();
            cout << "Enter new time: ";
            getline(cin, order.time);

            cout << "Enter new status: ";
            getline(cin, order.status);

            cout << "Order updated.\n";
            return;
        }
    }

    cout << "Order not found.\n";
}

void sortByCost(deque<Order>& orders)
{
    ranges::sort(orders, [](const Order& a, const Order& b)
    {
        return a.cost < b.cost;
    });

    cout << "Sorted by cost.\n";
}

void filterByCost(const deque<Order>& orders)
{
    double minCost, maxCost;
    cout << "Enter min cost: ";
    cin >> minCost;
    cout << "Enter max cost: ";
    cin >> maxCost;

    bool found = false;

    for (const auto & order : orders)
    {
        if (order.cost >= minCost && order.cost <= maxCost)
        {
            cout << order.number << " | " << order.surname << " | " << order.cost << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void filterByStatus(const deque<Order>& orders)
{
    cin.ignore();
    string s;
    cout << "Enter status: ";
    getline(cin, s);

    bool found = false;

    for (const auto & order : orders)
    {
        if (order.status == s)
        {
            cout << order.number << " | " << order.surname << " | " << order.status << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void filterByTime(const deque<Order>& orders)
{
    cin.ignore();
    string t;
    cout << "Enter time: ";
    getline(cin, t);

    bool found = false;

    for (const auto & order : orders)
    {
        if (order.time == t)
        {
            cout << order.number << " | " << order.surname << " | " << order.time << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void filterByPriority(const deque<Order>& orders)
{
    int p;
    cout << "Enter priority: ";
    cin >> p;

    bool found = false;

    for (const auto & order : orders)
    {
        if (order.priority == p)
        {
            cout << order.number << " | " << order.surname << " | " << order.priority << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void filterOrders(const deque<Order>& orders)
{
    int choice;
    cout << "1 - by cost range\n";
    cout << "2 - by status\n";
    cout << "3 - by time\n";
    cout << "4 - by priority\n";
    cout << "Choose filter: ";
    cin >> choice;

    if (choice == 1)
        filterByCost(orders);
    else if (choice == 2)
        filterByStatus(orders);
    else if (choice == 3)
        filterByTime(orders);
    else if (choice == 4)
        filterByPriority(orders);
    else
        cout << "Wrong choice.\n";
}

int main()
{
    deque<Order> orders;
    int choice;

    do
    {
        cout << "\n1 - Add urgent order to front\n";
        cout << "2 - Add regular order to back\n";
        cout << "3 - Delete completed or canceled orders\n";
        cout << "4 - Search order\n";
        cout << "5 - Edit order\n";
        cout << "6 - Sort by cost\n";
        cout << "7 - Filter orders\n";
        cout << "8 - Show all orders\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
            addUrgentOrder(orders);
        else if (choice == 2)
            addRegularOrder(orders);
        else if (choice == 3)
            deleteDoneOrCanceled(orders);
        else if (choice == 4)
            searchOrders(orders);
        else if (choice == 5)
            editOrder(orders);
        else if (choice == 6)
            sortByCost(orders);
        else if (choice == 7)
            filterOrders(orders);
        else if (choice == 8)
            showOrders(orders);
        else if (choice == 0)
            cout << "Exit.\n";
        else
            cout << "Wrong choice.\n";
    }
    while (choice != 0);

    return 0;
}