#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct WorkerNode
{
    string surname;
    string department;
    double salary{};
    WorkerNode* prev{};
    WorkerNode* next{};
};

void addWorkerToEnd(WorkerNode*& head, WorkerNode*& tail, string surname, string department, double salary)
{
    auto* newNode = new WorkerNode;
    newNode->surname = std::move(surname);
    newNode->department = std::move(department);
    newNode->salary = salary;
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

double averageSalary(const WorkerNode* head)
{
    double sum = 0;
    int count = 0;

    while (head != nullptr)
    {
        sum += head->salary;
        count++;
        head = head->next;
    }

    return sum / count;
}

void splitWorkers(const WorkerNode* head,
                  WorkerNode*& highHead, WorkerNode*& highTail,
                  WorkerNode*& lowHead, WorkerNode*& lowTail,
                  double avg)
{
    while (head != nullptr)
    {
        if (head->salary > avg)
            addWorkerToEnd(highHead, highTail, head->surname, head->department, head->salary);
        else
            addWorkerToEnd(lowHead, lowTail, head->surname, head->department, head->salary);

        head = head->next;
    }
}

void printForward(const WorkerNode* head)
{
    while (head != nullptr)
    {
        cout << head->surname << " " << head->department << " " << head->salary << endl;
        head = head->next;
    }
}

void printBackward(const WorkerNode* tail)
{
    while (tail != nullptr)
    {
        cout << tail->surname << " " << tail->department << " " << tail->salary << endl;
        tail = tail->prev;
    }
}

void clearList(WorkerNode*& head, WorkerNode*& tail)
{
    while (head != nullptr)
    {
        WorkerNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

int main()
{
    WorkerNode* head = nullptr;
    WorkerNode* tail = nullptr;

    WorkerNode* highHead = nullptr;
    WorkerNode* highTail = nullptr;

    WorkerNode* lowHead = nullptr;
    WorkerNode* lowTail = nullptr;

    int n;
    string surname, department;
    double salary;

    cout << "Enter number of workers: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> surname >> department >> salary;
        addWorkerToEnd(head, tail, surname, department, salary);
    }

    double avg = averageSalary(head);
    cout << "Average salary: " << avg << endl;

    splitWorkers(head, highHead, highTail, lowHead, lowTail, avg);

    cout << "Above average (forward):" << endl;
    printForward(highHead);

    cout << "Above average (backward):" << endl;
    printBackward(highTail);

    cout << "Below or equal (forward):" << endl;
    printForward(lowHead);

    cout << "Below or equal (backward):" << endl;
    printBackward(lowTail);

    cout << "Add new worker:" << endl;
    cin >> surname >> department >> salary;
    addWorkerToEnd(highHead, highTail, surname, department, salary);

    cout << "Updated first list:" << endl;
    printForward(highHead);

    clearList(head, tail);
    clearList(highHead, highTail);
    clearList(lowHead, lowTail);
}