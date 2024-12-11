#include<iostream>
using namespace std;
class Queue
{
    private:
        string* Array;
        int front;
        int rear;
        int capacity;
    public:
        Queue(int size)
        {
            Array = new string[size];
            front = -1;
            rear = -1;
            capacity = size;
        }
        ~Queue()
        {
            delete[] Array;
        }
        bool IsEmpty()
        {
            return front == -1;
        }
        bool IsFull()
        {
            return rear >= capacity - 1;
        }
        void Enqueue(string value)
        {
            if(IsFull())
            {
                cout << "Unable to add item. Queue has reached maximum capacity." << endl;
                return;
            }
            if(IsEmpty())
            {
                front = 0;
            }
            rear++; // after rear++ == 0    
            Array[rear] = value;
        }

        string Dequeue()
        {
            if(IsEmpty()) 
            {
                return "Queue is currently empty, unable to remove any item.";
            }

            string valueToRemove = Array[front];
            
            if(front == rear) 
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }

            return valueToRemove;
        }

        string Peek()
        {
            if(IsEmpty())
            {
                return "No elements to display. Queue is empty.";
            }
            return Array[front];
        }
};
int main()
{
    Queue q(5);
    q.Enqueue("100");
    q.Enqueue("Ghaffar");
    q.Enqueue("400");
    q.Enqueue("20");

    cout << "After adding 100, Ghaffar, 400 & 20 to the queue:" << endl;
    cout << "First element: " << q.Peek() << endl;
    cout << "Removed from queue: " << q.Dequeue() << endl;
    cout << "Removed from queue: " << q.Dequeue() << endl; 
    cout << "First element after removing 2 items: " << q.Peek() << endl;

    if(q.IsEmpty())
    {
        cout << "The queue is currently empty." << endl;
    } 
    else
    {
        cout << "The queue still has elements." << endl;
    }

    if(q.IsFull())
    {
        cout << "The queue is fully occupied." << endl;
    } 
    else
    {
        cout << "The queue has space for more items." << endl;
    }
}
