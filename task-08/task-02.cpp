#include <iostream>
#include <string>
using namespace std;

struct CourseNode
{
    string name;
    int hours;
    int students;
    CourseNode* prev;
    CourseNode* next;
};

void addToEnd(CourseNode*& head, CourseNode*& tail, string name, int hours, int students)
{
    CourseNode* newNode = new CourseNode;
    newNode->name = name;
    newNode->hours = hours;
    newNode->students = students;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

double findAverageStudents(CourseNode* head)
{
    if (head == nullptr)
    {
        return 0;
    }

    int sum = 0;
    int count = 0;

    CourseNode* p = head;
    while (p != nullptr)
    {
        sum += p->students;
        count++;
        p = p->next;
    }

    return (double)sum / count;
}

void printForward(CourseNode* head)
{
    CourseNode* p = head;
    while (p != nullptr)
    {
        cout << "Course: " << p->name
             << ", Hours: " << p->hours
             << ", Students: " << p->students << endl;
        p = p->next;
    }
}

void printBackward(CourseNode* tail)
{
    CourseNode* p = tail;
    while (p != nullptr)
    {
        cout << "Course: " << p->name
             << ", Hours: " << p->hours
             << ", Students: " << p->students << endl;
        p = p->prev;
    }
}

void divideList(CourseNode* head,
                CourseNode*& head1, CourseNode*& tail1,
                CourseNode*& head2, CourseNode*& tail2,
                double average)
{
    CourseNode* p = head;

    while (p != nullptr)
    {
        if (p->students > average)
        {
            addToEnd(head1, tail1, p->name, p->hours, p->students);
        }
        else
        {
            addToEnd(head2, tail2, p->name, p->hours, p->students);
        }

        p = p->next;
    }
}

void deleteList(CourseNode*& head, CourseNode*& tail)
{
    while (head != nullptr)
    {
        CourseNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

int main()
{
    CourseNode* head = nullptr;
    CourseNode* tail = nullptr;

    CourseNode* headMore = nullptr;
    CourseNode* tailMore = nullptr;

    CourseNode* headLess = nullptr;
    CourseNode* tailLess = nullptr;

    int n;
    string name;
    int hours;
    int students;

    cout << "Enter number of courses: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter course name: ";
        cin >> name;

        cout << "Enter number of hours: ";
        cin >> hours;

        cout << "Enter number of students: ";
        cin >> students;

        addToEnd(head, tail, name, hours, students);
    }

    cout << endl;
    cout << "All courses:" << endl;
    printForward(head);

    double average = findAverageStudents(head);

    cout << endl;
    cout << "Average number of students: " << average << endl;

    divideList(head, headMore, tailMore, headLess, tailLess, average);

    cout << endl;
    cout << "Courses with students above average (forward):" << endl;
    printForward(headMore);

    cout << endl;
    cout << "Courses with students above average (backward):" << endl;
    printBackward(tailMore);

    cout << endl;
    cout << "Courses with students below or equal average (forward):" << endl;
    printForward(headLess);

    cout << endl;
    cout << "Courses with students below or equal average (backward):" << endl;
    printBackward(tailLess);

    deleteList(head, tail);
    deleteList(headMore, tailMore);
    deleteList(headLess, tailLess);

    cout << endl;
    cout << "Memory freed." << endl;

    return 0;
}