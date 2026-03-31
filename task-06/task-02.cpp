#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct Music
{
    string carrier;
    string title;
    string singer;
    double duration{};
    int count{};
    double price{};
};

struct StackNode
{
    Music data;
    StackNode* next{};
};

void push(StackNode*& top, Music value)
{
    auto* temp = new StackNode;
    temp->data = std::move(value);
    temp->next = top;
    top = temp;
}

bool isEmpty(const StackNode* top)
{
    return top ==
        nullptr;
}

Music pop(StackNode*& top)
{
    Music empty;
    empty.carrier = "";
    empty.title = "";
    empty.singer = "";
    empty.duration = 0;
    empty.count = 0;
    empty.price = 0;

    if (isEmpty(top))
        return empty;

    StackNode* temp = top;
    Music value = top->data;
    top = top->next;
    delete temp;
    return value;
}

void printOne(const Music& m)
{
    cout << "Carrier: " << m.carrier << endl;
    cout << "Title: " << m.title << endl;
    cout << "Singer: " << m.singer << endl;
    cout << "Duration: " << m.duration << endl;
    cout << "Count: " << m.count << endl;
    cout << "Price: " << m.price << endl;
    cout << endl;
}

void printStack(StackNode* top)
{
    StackNode* p = top;
    while (p != nullptr)
    {
        printOne(p->data);
        p = p->next;
    }
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

double totalDurationBySinger(StackNode* top, const string& singerName)
{
    double sum = 0;
    StackNode* p = top;

    while (p != nullptr)
    {
        if (p->data.singer == singerName)
            sum += p->data.duration;
        p = p->next;
    }

    return sum;
}

void makeCassetteStack(const StackNode* top, StackNode*& newTop)
{
    StackNode* tempStack = nullptr;

    while (top != nullptr)
    {
        if (top->data.carrier == "audiocassette")
            push(tempStack, top->data);
        top = top->next;
    }

    while (tempStack != nullptr)
    {
        push(newTop, pop(tempStack));
    }
}

double averagePrice(StackNode* top)
{
    if (top == nullptr)
        return 0;

    double sum = 0;
    int count = 0;
    StackNode* p = top;

    while (p != nullptr)
    {
        sum += p->data.price;
        count++;
        p = p->next;
    }

    return sum / count;
}

void inputMusic(Music& m)
{
    cout << "Enter carrier: ";
    cin >> m.carrier;

    cout << "Enter title: ";
    cin >> m.title;

    cout << "Enter singer: ";
    cin >> m.singer;

    cout << "Enter duration: ";
    cin >> m.duration;

    cout << "Enter number of tracks: ";
    cin >> m.count;

    cout << "Enter price: ";
    cin >> m.price;
}

void task2()
{
    StackNode* top = nullptr;
    StackNode* cassetteTop = nullptr;
    int n;
    string singerName;

    cout << "Enter number of music records: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Music m;
        inputMusic(m);
        push(top, m);
    }

    cout << "Initial stack:" << endl;
    printStack(top);

    cout << "Enter singer name: ";
    cin >> singerName;

    cout << "Total duration of this singer: " << totalDurationBySinger(top, singerName) << endl;

    makeCassetteStack(top, cassetteTop);

    cout << "New stack with audiocassettes only:" << endl;
    printStack(cassetteTop);

    cout << "Average price in new stack: " << averagePrice(cassetteTop) << endl;

    clearStack(top);
    clearStack(cassetteTop);

    cout << "Memory freed." << endl;
}