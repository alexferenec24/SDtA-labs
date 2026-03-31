#include <iostream>
using namespace std;

struct StackNode
{
  int mark;
  StackNode* next;
};
void push(StackNode*& top, int value)
{
  StackNode* temp = new StackNode;
  temp->mark = value;
  temp->next = top;
  top = temp;
}

void printStack(StackNode* top)
{
  StackNode* p = top;
  while (p != nullptr)
  {
    cout << p->mark << " ";
    p = p->next;
  }
  cout << endl;
}
double averageStack(StackNode* top)
{
  if (top == nullptr)
    return 0;
  int sum = 0;
  int count = 0;
  StackNode* p =top;
  while (p != nullptr)
  {
    sum += p->mark;
    count++;
    p = p->next;
  }
  return (double)sum / count;
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
int main()
{
  StackNode* top = nullptr;
  int n, value;
  cout << "Enter number of marks";
  cin>>n;
  for (int i = 0; i < n; i++)
  {
    cout << "Enter mark: ";
    cin>>value;
    push(top, value);
  }

  cout << "Stack elements: "<< endl;
  printStack(top);
  cout << "Average mark: " << averageStack(top) << endl;
  cout << "All elements were deleted: " << endl;
  return 0;

}