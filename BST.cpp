#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *leftptr;
    Node *rightptr;

public:
    Node(int val)
    {
        data = val;
        leftptr = nullptr;
        rightptr = nullptr;
    }
};
class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }
};
Node *insertNode(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->leftptr = insertNode(root->leftptr, val);
    }
    else if (val > root->data)
    {
        root->rightptr = insertNode(root->rightptr, val);
    }
    return root;
}
Node *SearchBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if(root->data < key){
        return SearchBST(root->rightptr,key);
    }
    else if(root->data > key){
        return SearchBST(root->leftptr,key);
    }
}
void inOrderTrav(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTrav(root->leftptr);
    cout << root->data << " ";
    inOrderTrav(root->rightptr);
}
void PreOrderTrav(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrderTrav(root->leftptr);
    PreOrderTrav(root->rightptr);
}
void PostOrderTrav(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrderTrav(root->leftptr);
    PostOrderTrav(root->rightptr);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    root = insertNode(root, 5);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 3);

    inOrderTrav(root);
    cout << "\n";
    PreOrderTrav(root);
    cout << "\n";
    PostOrderTrav(root);
    cout << "\n";
    return 0;
}
