#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct TempNode
{
    string date;
    double temp{};
    TempNode* prev{};
    TempNode* next{};
};

void addTempToEnd(TempNode*& head, TempNode*& tail, string date, double temp)
{
    auto* newNode = new TempNode;
    newNode->date = std::move(date);

    newNode->temp = temp;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printTempForward(const TempNode* head)
{
    while (head != nullptr)
    {
        cout << "Date: " << head->date << ", Temperature: " << head->temp << endl;
        head = head->next;
    }
}

void uniteTempLists(TempNode*& head1, TempNode*& tail1, TempNode*& head2, TempNode*& tail2)
{
    if (head2 == nullptr) return;

    if (head1 == nullptr)
    {
        head1 = head2;
        tail1 = tail2;
    }
    else
    {
        tail1->next = head2;
        head2->prev = tail1;
        tail1 = tail2;
    }

    head2 = nullptr;
    tail2 = nullptr;
}

void findMinMaxTemp(const TempNode* head, double& minTemp, double& maxTemp)
{
    minTemp = head->temp;
    maxTemp = head->temp;

    head = head->next;

    while (head != nullptr)
    {
        if (head->temp < minTemp) minTemp = head->temp;
        if (head->temp > maxTemp) maxTemp = head->temp;
        head = head->next;
    }
}

void clearTempList(TempNode*& head, TempNode*& tail)
{
    while (head != nullptr)
    {
        TempNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

int main()
{
    TempNode* head1 = nullptr;
    TempNode* tail1 = nullptr;
    TempNode* head2 = nullptr;
    TempNode* tail2 = nullptr;

    int n1, n2;
    string date;
    double temp;

    cout << "Enter number of elements in first list: ";
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        cin >> date >> temp;
        addTempToEnd(head1, tail1, date, temp);
    }

    cout << "Enter number of elements in second list: ";
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        cin >> date >> temp;
        addTempToEnd(head2, tail2, date, temp);
    }

    uniteTempLists(head1, tail1, head2, tail2);

    cout << "Combined list:" << endl;
    printTempForward(head1);

    double minT, maxT;
    findMinMaxTemp(head1, minT, maxT);

    cout << "Min temp: " << minT << endl;
    cout << "Max temp: " << maxT << endl;

    clearTempList(head1, tail1);
}