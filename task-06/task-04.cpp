#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct Team
{
    string name;
    string city;
    int points{};
};

struct QueueNode
{
    Team data;
    QueueNode* next{};
};

void pushQueue(QueueNode*& front, QueueNode*& rear, Team value)
{
    auto* temp = new QueueNode;
    temp->data = std::move(value);
    temp->next = nullptr;

    if (rear == nullptr)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

bool isEmpty(QueueNode* front)
{
    return front == nullptr;
}

Team popQueue(QueueNode*& front, QueueNode*& rear)
{
    Team empty;
    empty.name = "";
    empty.city = "";
    empty.points = 0;

    if (isEmpty(front))
        return empty;

    QueueNode* temp = front;
    Team value = front->data;
    front = front->next;

    if (front == nullptr)
        rear = nullptr;


    delete temp;
    return value;
}

void printTeam(const Team& t)
{
    cout << "Team: " << t.name << endl;
    cout << "City: " << t.city << endl;
    cout << "Points: " << t.points << endl;
    cout << endl;
}

void printQueue(QueueNode* front)
{
    QueueNode* p = front;
    while (p != nullptr)
    {
        printTeam(p->data);
        p = p->next;
    }
}

void clearQueue(QueueNode*& front, QueueNode*& rear)
{
    while (front != nullptr)
    {
        QueueNode* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

bool cityExists(QueueNode* front, const string& city)
{
    QueueNode* p = front;
    while (p != nullptr)
    {
        if (p->data.city == city)
            return true;
        p = p->next;
    }
    return false;
}

void findLeaderAndOutsider(QueueNode* front)
{
    if (front == nullptr)
        return;

    QueueNode* maxTeam = front;
    QueueNode* minTeam = front;
    QueueNode* p = front->next;

    while (p != nullptr)
    {
        if (p->data.points > maxTeam->data.points)
            maxTeam = p;

        if (p->data.points < minTeam->data.points)
            minTeam = p;

        p = p->next;
    }

    cout << "Leader team:" << endl;
    printTeam(maxTeam->data);

    cout << "Outsider team:" << endl;
    printTeam(minTeam->data);
}

void makeUniqueCityQueue(QueueNode* front, QueueNode*& newFront, QueueNode*& newRear)
{
    QueueNode* p = front;

    while (p != nullptr)
    {
        if (!cityExists(newFront, p->data.city))
            pushQueue(newFront, newRear, p->data);

        p = p->next;
    }
}

void makePointsQueue(QueueNode* front, QueueNode*& newFront, QueueNode*& newRear, int limit)
{
    QueueNode* p = front;

    while (p != nullptr)
    {
        if (p->data.points > limit)
            pushQueue(newFront, newRear, p->data);

        p = p->next;
    }
}

void inputTeam(Team& t)
{
    cout << "Enter team name: ";
    cin >> t.name;

    cout << "Enter city: ";
    cin >> t.city;

    cout << "Enter points: ";
    cin >> t.points;
}

void task4()
{
    QueueNode* front = nullptr;
    QueueNode* rear = nullptr;

    QueueNode* cityFront = nullptr;
    QueueNode* cityRear = nullptr;

    QueueNode* pointsFront = nullptr;
    QueueNode* pointsRear = nullptr;

    int n;
    int limit;

    cout << "Enter number of teams: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Team t;
        inputTeam(t);
        pushQueue(front, rear, t);
    }

    cout << "Initial queue:" << endl;
    printQueue(front);

    findLeaderAndOutsider(front);

    makeUniqueCityQueue(front, cityFront, cityRear);

    cout << "Queue with one team from each city:" << endl;
    printQueue(cityFront);

    cout << "Enter points limit: ";
    cin >> limit;

    makePointsQueue(front, pointsFront, pointsRear, limit);

    cout << "Queue with teams having more than given points:" << endl;
    printQueue(pointsFront);

    cout << "Initial queue after processing:" << endl;
    printQueue(front);

    clearQueue(front, rear);
    clearQueue(cityFront, cityRear);
    clearQueue(pointsFront, pointsRear);

    cout << "Memory freed." << endl;
}