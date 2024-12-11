#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

class Queue
{
private:
    Node *head;

public:
    Queue()
    {
        head = nullptr;
    }

    ~Queue()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // void Enqueue(string x)
    // {
    //     Node* newNode = new Node();
    //     newNode->data = x;
    //     newNode->next = nullptr;

    //     if (head == nullptr)
    //     {
    //         head = newNode;
    //     }
    //     else
    //     {
    //         Node* tail = head;
    //         while (tail->next != nullptr)
    //         {
    //             tail = tail->next;
    //         }
    //         tail->next = newNode;
    //     }
    // }
    void Enqueue(string val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr){
            head = newNode;
        }
        else{
            Node* tail = head;
            while (tail->next!=nullptr){
                tail = tail->next;
            }
            tail->next = newNode;
        }
    }
    // string Dequeue()
    // {
    //     if (IsEmpty())
    //     {
    //         return "Queue is empty. Cannot Dequeue.";
    //     }

    //     Node *temp = head;
    //     string dequeuedData = head->data;
    //     head = head->next;
    //     delete temp;
    //     return dequeuedData;
    // }
    string Dequeue(){
        if (IsEmpty()){
            return " ";
        }
        Node* temp = head;
        string remove = head->data;
        head = head->next;
        delete temp;
        return remove;
    }
    string Peek()
    {
        if (IsEmpty())
        {
            return "Queue is empty. Nothing to peek.";
        }
        return head->data;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
    Queue q;
    q.Enqueue("50");
    q.Enqueue("Clear");
    q.Enqueue("400");
    q.Enqueue("20");

    cout << "After Enqueuing 50, Clear, 400 & 20:" << endl;
    cout << "Peek: " << q.Peek() << endl;

    cout << "Dequeue: " << q.Dequeue() << endl;
    cout << "Dequeue: " << q.Dequeue() << endl;
    cout << "Peek after Dequeueing 2 elements: " << q.Peek() << endl;

    if (q.IsEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is not Empty" << endl;
    }
}
