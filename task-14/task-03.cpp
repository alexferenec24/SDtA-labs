#include <iostream>
#include <deque>
#include <string>

using namespace std;

void showMenu()
{
    cout << "\n1 - Add normal request to end\n";
    cout << "2 - Add urgent request to front\n";
    cout << "3 - Process request from front\n";
    cout << "4 - Show queue\n";
    cout << "5 - Show number of requests\n";
    cout << "0 - Exit\n";
    cout << "Choose: ";
}

int main()
{
    deque<string> requests;
    int choice;

    do
    {
        showMenu();
        cin >> choice;

        if (choice == 1)
        {
            string request;
            cout << "Enter request: ";
            cin >> request;
            requests.push_back(request);
        }
        else if (choice == 2)
        {
            string request;
            cout << "Enter urgent request: ";
            cin >> request;
            requests.push_front(request);
        }
        else if (choice == 3)
        {
            if (requests.empty())
            {
                cout << "Queue is empty\n";
            }
            else
            {
                cout << "Processed request: " << requests.front() << endl;
                requests.pop_front();
            }
        }
        else if (choice == 4)
        {
            if (requests.empty())
            {
                cout << "Queue is empty\n";
            }
            else
            {
                cout << "Current queue:\n";
                for (int i = 0; i < (int)requests.size(); i++)
                    cout << requests[i] << " ";
                cout << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "Number of requests: " << requests.size() << endl;
        }

    } while (choice != 0);

    return 0;
}