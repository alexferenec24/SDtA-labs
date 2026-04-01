#include <iostream>
using namespace std;

struct StackNode
{
    int value;
    StackNode* next;
};

void push(StackNode*& top, int x)
{
    StackNode* newNode = new StackNode;
    newNode->value = x;
    newNode->next = top;
    top = newNode;
}

void printStack(StackNode* top)
{
    StackNode* p = top;
    while (p != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

double findAverage(StackNode* top)
{
    if (top == nullptr)
    {
        return 0;
    }

    int sum = 0;
    int count = 0;

    StackNode* p = top;
    while (p != nullptr)
    {
        sum += p->value;
        count++;
        p = p->next;
    }

    return (double)sum / count;
}

void deleteAll(StackNode*& top)
{
    while (top != nullptr)
    {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

int main()
{
    StackNode* top = nullptr;
    int n;
    int x;

    cout << "Enter number of marks: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter mark " << i + 1 << ": ";
        cin >> x;
        push(top, x);
    }

    cout << "Stack elements:" << endl;
    printStack(top);

    cout << "Average mark: " << findAverage(top) << endl;

    deleteAll(top);

    cout << "All stack elements were deleted." << endl;

    return 0;
}