#include<iostream>
using namespace std;

class Stack
{
    private:
        string* Array;
        int top;
        int capacity;
    public:
        Stack(int size)
        {
            Array = new string[size];
            top = -1;
            capacity = size;
        }
        ~Stack()
        {
            delete[] Array;
        }

        bool IsEmpty()
        {
            return top == -1;
        }

        bool IsFull()
        {
            return top >= capacity - 1;
        }

        void Push(string value)
        {
            if(IsFull())
            {
                cout << "Cannot push element. The stack is full." << endl;
                return;
            }
            top++;
            Array[top] = value;
        }

        string Pop()
        {
            if(IsEmpty())
            {
                return "Stack is empty. Cannot pop.";
            }
            string valueToRemove = Array[top];
            top--;
            return valueToRemove;
        }

        string Peek()
        {
            if(IsEmpty())
            {
                return "Stack is empty.";
            }
            return Array[top];
        }
};

int main()
{
    Stack s(5);
    s.Push("50");
    s.Push("Clear");
    s.Push("400");
    s.Push("20");
    cout << "After pushing 50, Clear, 400 & 20:" << endl;
    cout << "Peek: " << s.Peek() << endl;
    cout << "Pop: " << s.Pop() << endl;
    cout << "Pop: " << s.Pop() << endl;
    cout << "Peek after popping 2 elements: " << s.Peek() << endl;
}
