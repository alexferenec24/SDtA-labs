#include <iostream>
#include <map>
#include <string>

using namespace std;

void showMenu()
{
    cout << "\n1 - Add record\n";
    cout << "2 - Show all numbers by name\n";
    cout << "3 - Delete one number\n";
    cout << "4 - Delete all numbers by name\n";
    cout << "5 - Show all phone book\n";
    cout << "0 - Exit\n";
    cout << "Choose: ";
}

int main()
{
    multimap<string, string> phoneBook;
    int choice;

    do
    {
        showMenu();
        cin >> choice;

        if (choice == 1)
        {
            string name, number;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter number: ";
            cin >> number;
            phoneBook.insert(make_pair(name, number));
        }
        else if (choice == 2)
        {
            string name;
            cout << "Enter name: ";
            cin >> name;

            multimap<string, string>::iterator it = phoneBook.find(name);

            if (it == phoneBook.end())
            {
                cout << "No records found\n";
            }
            else
            {
                cout << "Numbers:\n";
                while (it != phoneBook.end() && it->first == name)
                {
                    cout << it->second << endl;
                    it++;
                }
            }
        }
        else if (choice == 3)
        {
            string name, number;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter number to delete: ";
            cin >> number;

            bool found = false;
            multimap<string, string>::iterator it = phoneBook.find(name);

            while (it != phoneBook.end() && it->first == name)
            {
                if (it->second == number)
                {
                    phoneBook.erase(it);
                    found = true;
                    break;
                }
                it++;
            }

            if (found)
                cout << "Number deleted\n";
            else
                cout << "Record not found\n";
        }
        else if (choice == 4)
        {
            string name;
            cout << "Enter name: ";
            cin >> name;

            int deleted = phoneBook.erase(name);

            if (deleted > 0)
                cout << "All numbers deleted\n";
            else
                cout << "No records found\n";
        }
        else if (choice == 5)
        {
            if (phoneBook.empty())
            {
                cout << "Phone book is empty\n";
            }
            else
            {
                multimap<string, string>::iterator it;
                for (it = phoneBook.begin(); it != phoneBook.end(); it++)
                {
                    cout << it->first << " - " << it->second << endl;
                }
            }
        }

    } while (choice != 0);

    return 0;
}