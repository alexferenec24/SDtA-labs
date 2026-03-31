#include <iostream>
using namespace std;

struct NodeInt
{
    int data;
    NodeInt* next;
};

void addToBeginningInt(NodeInt*& head, int value)
{
    NodeInt* temp = new NodeInt;
    temp->data = value;
    temp->next = head;
    head = temp;
}

void addToEndInt(NodeInt*& head, int value)
{
    NodeInt* temp = new NodeInt;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    NodeInt* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
}

void addAfterPositionInt(NodeInt*& head, int pos, int value)
{
    NodeInt* p = head;
    int i = 1;

    while (p != NULL && i < pos)
    {
        p = p->next;
        i++;
    }

    if (p == NULL) return;

    NodeInt* temp = new NodeInt;
    temp->data = value;
    temp->next = p->next;
    p->next = temp;
}

void printList(NodeInt* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

double average(NodeInt* head)
{
    int sum = 0, count = 0;
    while (head != NULL)
    {
        sum += head->data;
        count++;
        head = head->next;
    }
    return (double)sum / count;
}

void deleteFirstEven(NodeInt*& head)
{
    if (!head) return;

    if (head->data % 2 == 0)
    {
        NodeInt* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    NodeInt* p = head;
    while (p->next != NULL)
    {
        if (p->next->data % 2 == 0)
        {
            NodeInt* temp = p->next;
            p->next = temp->next;
            delete temp;
            return;
        }
        p = p->next;
    }
}

void clear(NodeInt*& head)
{
    while (head)
    {
        NodeInt* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    NodeInt* head = NULL;
    int a, b, c, d;

    cout << "Enter 4 integers: ";
    cin >> a >> b >> c >> d;

    addToBeginningInt(head, a);
    addToEndInt(head, b);
    addAfterPositionInt(head, 1, c);
    addToEndInt(head, d);

    cout << "List: ";
    printList(head);

    cout << "Average: " << average(head) << endl;

    deleteFirstEven(head);

    cout << "After deleting first even: ";
    printList(head);

    clear(head);
}