#include <iostream>
using namespace std;
struct Node
{
    Node *next;
    string data;
};
// class Stack{
// private:
//     Node* head;
// public:
//     Stack(){
//         head = nullptr;
//     }
//     bool isEmpty(){
//         return head==nullptr;
//     }
//     string Peek(){
//         if (isEmpty()){
//             return;
//         }
//         return head->data;
//     }
//     void push(string str){
//         Node* n = new Node();
//         n->data = str;
//         n->next = head;
//         head = n;
//     }
//     string pop(){
//         if (isEmpty())
//         {
//             return;
//         }
//         Node* temp = head;
//         string value = temp->data;
//         head = temp->next;
//         delete temp;
//         return value;
//     }
// };

// class Stack
// {
//     private:
//         Node* head;
//     public:
//         Stack()
//         {
//             head = nullptr;
//         }
//         ~Stack()
//         {
//             Node* current = head;
//             while (current != nullptr)
//             {
//                 Node* next = current->next;
//                 delete current;
//                 current = next;
//             }
//             head = nullptr;
//         }

//         void Push(string x)
//         {
//             Node* newNode = new Node();
//             newNode->data = x;
//             newNode->next = head;
//             head = newNode;
//         }

//         string Pop()
//         {
//             if (IsEmpty())
//             {
//                 return "Stack is empty. Cannot pop.";
//             }

//             Node* temp = head;
//             string poppedData = head->data;
//             head = head->next;
//             delete temp;
//             return poppedData;
//         }

//         string Peek()
//         {
//             if (IsEmpty())
//             {
//                 return "Stack is empty. Nothing to peek.";
//             }
//             return head->data;
//         }

//         bool IsEmpty()
//         {
//             return head == nullptr;
//         }
// };

// int main()
// {
//     Stack s;
//     s.Push("50");
//     s.Push("Clear");
//     s.Push("400");
//     s.Push("20");

//     cout << "After pushing 50, Clear, 400 & 20:" << endl;
//     cout << "Peek: " << s.Peek() << endl;

//     cout << "Pop: " << s.Pop() << endl;
//     cout << "Pop: " << s.Pop() << endl;
//     cout << "Peek after popping 2 elements: " << s.Peek() << endl;

//     if (s.IsEmpty()) {
//         cout << "The stack is now empty." << endl;
//     }
// }

class node
{
public:
    node *next;
    int data;
    node(int value)
    {
        data = value;
        next = nullptr;
    }
};
void insertattail(node *&head, int value)
{
    node *n = new node(value);

    if (head == nullptr)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertathead(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    head = n;
}
void display(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}
bool searching(node *&head, int value)
{
    node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main()
{
    node *head = nullptr;
    insertathead(head, 2);
    insertattail(head, 5);
    insertathead(head, 8);
    insertathead(head, 9);
    display(head);
}
