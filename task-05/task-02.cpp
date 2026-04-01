#include <iostream>
#include <string>
using namespace std;

struct CityNode
{
    string name;
    int distance;
    CityNode* next;
};

void addCity(CityNode*& head, string name, int distance)
{
    CityNode* temp = new CityNode{ name, distance, nullptr };

    if (!head)
    {
        head = temp;
        return;
    }

    CityNode* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

void print(CityNode* head)
{
    while (head)
    {
        cout << head->name << " - " << head->distance << " km\n";
        head = head->next;
    }
}

void farthest(CityNode* head)
{
    CityNode *m1 = nullptr, *m2 = nullptr;

    while (head)
    {
        if (!m1 || head->distance > m1->distance)
        {
            m2 = m1;
            m1 = head;
        }
        else if (!m2 || head->distance > m2->distance)
            m2 = head;

        head = head->next;
    }

    cout << "Two farthest cities:\n";
    if (m1) cout << m1->name << endl;
    if (m2) cout << m2->name << endl;
}

void clear(CityNode*& head)
{
    while (head)
    {
        CityNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    CityNode* head = nullptr;
    int n;

    cout << "Enter number of cities: ";
    cin >> n;

    string name;
    int d;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> d;
        addCity(head, name, d);
    }

    print(head);
    farthest(head);

    cout << "Add foreign city:\n";
    cin >> name >> d;
    addCity(head, name, d);

    print(head);

    clear(head);
}