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
    CourseNode* temp = new CourseNode;
    temp->name = name;
    temp->hours = hours;
    temp->students = students;
    temp->prev = tail;
    tail->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
double averageStudents(CourseNode* head)
{
    if (head == nullptr)
        return 0;

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
void splitCourses(CourseNode* head, CourseNode*& head1, CourseNode*& head2, CourseNode*& tail1, CourseNode*& tail2, double average)
{
    CourseNode* p = head;
    while (p != nullptr)
    {
        if (p->students > average)
            addToEnd(head1, tail1, p->name, p->hours, p->students);
        else
            addToEnd(head2, tail2, p->name, p->hours, p->students);
        p =p->next;
    }

}
void printForward(CourseNode* head)
{
    CourseNode* p = head;
    while (p != nullptr)
    {
        cout << "Course: " << p->name << ", Hours: " << p->hours << ", Students: " << p->students << endl;
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

void clearList(CourseNode*& head, CourseNode*& tail)
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

    CourseNode* headAbove = nullptr;
    CourseNode* tailAbove = nullptr;

    CourseNode* headBelow = nullptr;
    CourseNode* tailBelow = nullptr;

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

    double avg = averageStudents(head);
    cout << "Average number of students: " << avg << endl;

    splitCourses(head, headAbove, tailAbove, headBelow, tailBelow, avg);

    cout << endl;
    cout << "Courses with students above average (forward):" << endl;
    printForward(headAbove);

    cout << endl;
    cout << "Courses with students above average (backward):" << endl;
    printBackward(tailAbove);

    cout << endl;
    cout << "Courses with students below or equal average (forward):" << endl;
    printForward(headBelow);

    cout << endl;
    cout << "Courses with students below or equal average (backward):" << endl;
    printBackward(tailBelow);

    clearList(head, tail);
    clearList(headAbove, tailAbove);
    clearList(headBelow, tailBelow);

    cout << endl;
    cout << "Memory freed." << endl;

    return 0;
}