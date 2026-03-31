#include <iostream>
#include <ctime>

using namespace std;

struct StackNode
{
    double data;
    StackNode* next;
};

void push(StackNode*& top, double value)
{
    auto* temp = new StackNode;
    temp->data = value;
    temp->next = top;
    top = temp;
}

bool isEmpty(const StackNode* top)
{
    return top == nullptr;
}

double pop(StackNode*& top)
{
    if (isEmpty(top))
        return 0;

    StackNode* temp = top;
    double value = top->data;
    top = top->next;
    delete temp;
    return value;
}

void printStack(StackNode* top)
{
    StackNode* p = top;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

double averageStack(StackNode* top)
{
    if (top == nullptr)
        return 0;

    double sum = 0;
    int count = 0;
    StackNode* p = top;

    while (p != nullptr)
    {
        sum += p->data;
        count++;
        p = p->next;
    }

    return sum / count;
}

void clearStack(StackNode*& top)
{
    while (top != nullptr)
    {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

void generateStack(StackNode*& top, int n)
{
    for (int i = 0; i < n; i++)
    {
        double value = -6 + rand() % 18;
        push(top, value);
    }
}

void removeLessThan(StackNode*& top, double limit)
{
    StackNode* tempStack = nullptr;

    while (top != nullptr)
    {
        double x = pop(top);
        if (x >= limit)
            push(tempStack, x);
    }

    while (tempStack != nullptr)
    {
        push(top, pop(tempStack));
    }
}

void task1()
{
    srand(time(nullptr));

    StackNode* top = nullptr;
    int n;
    double limit;

    cout << "Enter number of elements: ";
    cin >> n;

    generateStack(top, n);

    cout << "Initial stack:" << endl;
    printStack(top);

    cout << "Enter value: ";
    cin >> limit;

    removeLessThan(top, limit);

    cout << "New stack:" << endl;
    printStack(top);

    cout << "Average ариthmetic value: " << averageStack(top) << endl;

    clearStack(top);
    cout << "Memory freed." << endl;
}