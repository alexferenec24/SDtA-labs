#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    int code;
    string name;
    double price;
    Node* left;
    Node* right;
};

Node* createNode(int c, string n, double p)
{
    Node* node = new Node;
    node->code = c;
    node->name = n;
    node->price = p;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insertNode(Node* root, int c, string n, double p)
{
    if (root == nullptr)
        return createNode(c, n, p);

    if (c < root->code)
        root->left = insertNode(root->left, c, n, p);
    else if (c > root->code)
        root->right = insertNode(root->right, c, n, p);

    return root;
}

Node* createTree()
{
    ifstream fileoutput("C:/Users/Саша/CLionProjects/SDtA labs/task-09/tech.txt");

    if (!fileoutput.is_open())
    {
        cout << "Unable to open file";
        return nullptr;
    }

    Node* root = nullptr;
    int code;
    string name;
    double price;

    while (fileoutput >> code >> name >> price)
    {
        root = insertNode(root, code, name, price);
    }

    fileoutput.close();
    return root;
}


Node* searchNode(Node* root, int code)
{
    if (root == nullptr) return nullptr;

    if (root->code == code) return root;

    if (code < root->code)
        return searchNode(root->left, code);
    else
        return searchNode(root->right, code);
}

void inorder(Node* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->code << " " << root->name << " " << root->price << endl;
        inorder(root->right);
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

void calc(Node* root, double& sum, int& count)
{
    if (root != nullptr)
    {
        calc(root->left, sum, count);
        sum += root->price;
        count++;
        calc(root->right, sum, count);
    }
}

int depth(Node* root)
{
    if (root == nullptr) return 0;

    int l = depth(root->left);
    int r = depth(root->right);

    return (l > r ? l : r) + 1;
}

int nodesOnLevel(Node* root, int level)
{
    if (root == nullptr) return 0;

    if (level == 1) return 1;

    return nodesOnLevel(root->left, level - 1) +
           nodesOnLevel(root->right, level - 1);
}

void deleteChildren(Node* node)
{
    if (node == nullptr) return;

    deleteTree(node->left);
    deleteTree(node->right);

    node->left = nullptr;
    node->right = nullptr;
}

int main()
{
    Node* root = nullptr;

    root = createTree();

    cout << "\nTree:\n";
    inorder(root);

    double sum = 0;
    int count = 0;

    calc(root, sum, count);

    cout << "\nAverage price: " << sum / count << endl;

    int d = depth(root);

    cout << "\nNodes on each level:\n";
    for (int i = 1; i <= d; i++)
    {
        cout << "Level " << i << ": "
             << nodesOnLevel(root, i) << endl;
    }

    int x;
    cout << "\nEnter code: ";
    cin >> x;

    Node* found = searchNode(root, x);

    if (found)
    {
        deleteChildren(found);
        cout << "Children deleted\n";
    }
    else
        cout << "Not found\n";

    cout << "\nTree after deletion:\n";
    inorder(root);

    deleteTree(root);

    return 0;
}