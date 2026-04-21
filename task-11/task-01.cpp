#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Node
{
    int height;
    string name;
    Node* left;
    Node* right;
};
Node* createNode(int height, string name)
{
    Node* newNode = new Node();
    newNode->height = height;
    newNode->name = name;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertTree(Node* root, int height, string name)
{
    if (root == nullptr)
        return createNode(height, name);

    if (height < root->height)
        root->left = insertTree(root->left, height, name);
    else
        root->right = insertTree(root->right, height, name);
    return root;
}

Node* insertHeightTree(Node* root, int height)
{
    if (root == nullptr)
        return createNode(height, "");

    if (height < root->height)
        root->left = insertHeightTree(root->left,height);
    else
        root->right = insertHeightTree(root->right,height);

    return root;
}
void printTree(Node* root)
{
    if (root != nullptr)
    {
        printTree(root->left);
        if (root->name != "")
            cout << "Height: " << root->height << "Name: " << root->name << endl;
        else
            cout << "Height: " << root->height << endl;
        printTree(root->right);
    }
}

int countNodes(Node* root)
{
    if (root == nullptr)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int treeDepth(Node* root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);

    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}
int countName(Node* root, string keyName)
{
    if (root == nullptr)
        return 0;

    int count = 0;
    if (root->name == keyName)
        count = 1;

    return count + countName(root->left, keyName) + countName(root->right, keyName);
}

void buildFromLeftSubTree(Node* root, Node*& newTree)
{
    if (root != nullptr)
    {
        newTree = insertHeightTree(newTree, root->height);
        buildFromLeftSubTree(root->left, newTree);
        buildFromLeftSubTree(root->right, newTree);
    }
}

void deleteTree(Node*& root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
    void generateTree(Node*& root, int n, string names[], int size)
    {
        if (n == 0)
            return;

        int height = 150 + rand() % 51;
        string name = names[rand() % size];

        root = insertTree(root, height, name);

        generateTree(root, n - 1, names, size);
    }

}
int main()
{
    srand(time(0));

    string names[] = {
        "Ivan", "Petro", "Olga", "Anna", "Oleg"
        "Maria", "Sofia", "Andriy", "Nazar", "Ira"
    };

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;



Node* root = nullptr;
    generateTree(root, n, names, 10);

    cout << endl;
    cout << "Original Tree: " << endl;
    printTree(root);

    string searchName;
    cout << endl;
    cout << "Enter name to search: ";
    cin >> searchName;

    int foundCount = countName(root, searchName);

    if (foundCount > 0)
        cout << "Name: \"" << searchName << "\" found " << foundCount << "time(s)." << endl;
    else
        cout << "Name: \"" << searchName << "\" not found in tree." << endl;
    Node* newTree = nullptr;

    if (root != nullptr && root->left != nullptr)
        buildFromLeftSubTree(root->left, newTree);

    cout << endl;
    cout << "New tree from left subtree (only height): " << endl;
    if (newTree != nullptr)
        printTree(newTree);
    else
        cout << "Left subtree is empty. " << endl;

    cout << endl;
    cout << "Original tree node count: " << countNodes(root) << endl;
    cout << "Original tree depth: " << treeDepth(root) << endl;

    cout << "New tree node count: " << countNodes(newTree) << endl;
    cout << "New tree depth: " << treeDepth(newTree) << endl;

    deleteTree(root);
    deleteTree(newTree);

    return 0;
}