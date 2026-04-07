#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* node = new Node();
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
Node* insertNode(Node* root, int value)
{
    if (root == nullptr)
        return createNode(value);
    if (value < root->data)
       root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}

bool searchNode(Node* root, int value)
{
    if (root == nullptr)
        return false;

    if (value < root->data)
        return searchNode(root->left, value);
    else
        return searchNode(root->right, value);
}

void inorder(Node* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int getDepth(Node* root)
{
    if (root == nullptr)
        return 0;
    int left = getDepth(root->left);
    int right = getDepth(root->right);

    return (left > right ? left : right) +1;
}
void splitTree(Node* root, Node*& evenTree, Node*& oddTree)
{
    if (root!= nullptr)
    {
        splitTree(root->left, evenTree, oddTree);
        if (root->data % 2 == 0)
            evenTree = insertNode(evenTree, root->data);
        else
            oddTree = insertNode(oddTree, root->data);
        splitTree(root->right, evenTree, oddTree);
    }
}
void deleteTree(Node* root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
int main()
{
    Node* root = nullptr;
    Node* evenTree = nullptr;
    Node* oddTree = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int choice;
    cout << "1 - manual, 2 - random: ";
    cin >> choice;
    if (choice == 1)
    {
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (!searchNode(root, x))
                root = insertNode(root, x);
            else
                i--;
        }
    }
    else
    {
        int a, b;
        cout << " a = "; cin >>a;
        cout << " b = "; cin >> b;

        if (n>(b-a +1))
        {
            cout << "Too many nodes\n";
            return 0;
        }
        srand(time(nullptr));
        int count = 0;
        while (count < n)
        {
            int x = a + rand() % (b - a +1);
            if (!searchNode(root, x))
            {
                root = insertNode(root, x);
                count++;
            }
        }
    }
    cout << "Tree: ";
    inorder(root);
    cout << endl;

    int value;
    cout << "Check value: ";
    cin >> value;

    if (searchNode(root, value))
        cout << "Exists\n";
    else
        cout << "Not exists\n";

    splitTree(root, evenTree, oddTree);
    cout << "Even: ";
    inorder(evenTree);
    cout<<endl;

    cout << "Odd: ";
    inorder(oddTree);
    cout<<endl;

    cout << "Depth main: " << getDepth(root) << endl;
    cout << "Depth even: " << getDepth(evenTree) << endl;
    cout << "Depth odd: " << getDepth(oddTree) << endl;

    deleteTree(root);
    deleteTree(evenTree);
    deleteTree(oddTree);
    return 0;
}