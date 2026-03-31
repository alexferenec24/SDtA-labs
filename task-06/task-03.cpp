#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

struct QueueNode
{
    int data;
    QueueNode* next;
};

void pushQueue(QueueNode*& front, QueueNode*& rear, int value)
{
    auto* temp = new QueueNode;
    temp->data = value;
    temp->next = nullptr;

    if (rear == NULL)
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

int popQueue(QueueNode*& front, QueueNode*& rear)
{
    if (isEmpty(front))
        return 0;

    QueueNode* temp = front;
    int value = front->data;
    front = front->next;

    if (front == nullptr)

        rear = nullptr;

    delete temp;
    return value;
}

void printQueue(QueueNode* front)
{
    QueueNode* p = front;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
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

void generateQueue(QueueNode*& front, QueueNode*& rear, int n)
{
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 50;
        pushQueue(front, rear, value);
    }
}

void makeNewQueue(QueueNode*& front, QueueNode*& rear, QueueNode*& newFront, QueueNode*& newRear)
{
    while (front != nullptr)
    {
        int x = popQueue(front, rear);

        if (x % 2 == 0)
        {
            pushQueue(newFront, newRear, x);
            pushQueue(newFront, newRear, 100);
        }
    }
}

double geometricMean(QueueNode* front)
{
    if (front == nullptr)
        return 0;

    double product = 1;
    int count = 0;
    QueueNode* p = front;

    while (p != nullptr)
    {
        product *= p->data;
        count++;
        p = p->next;
    }

    return pow(product, 1.0 / count);
}

void task3()
{
    srand(time(nullptr));

    QueueNode* front = nullptr;
    QueueNode* rear = nullptr;

    QueueNode* newFront = nullptr;
    QueueNode* newRear = nullptr;

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    generateQueue(front, rear, n);

    cout << "Initial queue:" << endl;
    printQueue(front);

    makeNewQueue(front, rear, newFront, newRear);

    cout << "New queue:" << endl;
    printQueue(newFront);

    cout << "Geometric mean: " << geometricMean(newFront) << endl;

    clearQueue(front, rear);
    clearQueue(newFront, newRear);

    cout << "Memory freed." << endl;
}