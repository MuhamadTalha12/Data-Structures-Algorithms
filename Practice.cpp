// #include <iostream>
// using namespace std;

// class CircularQueue
// {
// private:
//     int *queue;
//     int front, rear, size;

// public:
//     CircularQueue(int s)
//     {
//         size = s;
//         queue = new int[size];
//         front = rear = -1;
//     }
//     void enqueue(int x)
//     {
//         if ((rear + 1) % size == front)
//         {
//             cout << "Full";
//             return;
//         }
//         else if (front == -1)
//         {
//             front = rear = 0;
//             queue[rear] = x;
//         }
//         else
//         {
//             rear = (rear + 1) % size;
//             queue[rear] = x;
//         }
//     }
//     int dequeue()
//     {
//         if (front == -1)
//         {
//             cout << "Empty";
//             return -1;
//         }
//         int get = queue[front];
//         queue[front] = -1;
//         if (front == rear)
//         {
//             front = rear = -1;
//         }
//         else
//         {
//             front = (front + 1) % size;
//         }
//         return get;
//     }
//     int peek()
//     {
//         if (front == -1)
//         {
//             cout << "Empty";
//             return -1;
//         }
//         return queue[front];
//     }
//     void DisplayQueue()
//     {
//         if (front == -1)
//         {
//             cout << "Empty";
//         }
//         if (front >= rear)
//         {
//             for (int i = front; i <= rear; i++)
//             {
//                 cout << queue[i] << " ";
//             }
//         }
//         else
//         {
//             for (int i = front; i < size; i++)
//             {
//                 cout << queue[i] << " ";
//             }
//             for (int i = 0; i <= rear; i++)
//             {
//                 cout << queue[i] << " ";
//             }
//         }
//     }
// };
//     int main()
//     {
//         CircularQueue q(5); // Create a queue with size 5

//         q.enqueue(14);
//         q.enqueue(22);
//         q.enqueue(13);
//         q.enqueue(6);

//         q.DisplayQueue();

//         cout << "Dequeued value: " << q.dequeue() << endl;

//         q.DisplayQueue();

//         q.enqueue(9);
//         q.enqueue(20);

//         q.DisplayQueue();

//         return 0;
//     }

#include <iostream>
using namespace std;

class CircularQueue {
    int *queue;
    int front, rear, size;

public:
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    // Function to insert an element in the queue
    void enqueue(int value) {
        // Queue is full when next position of rear (i.e., (rear + 1) % size) is equal to front
        if ((rear + 1) % size == front) {
            cout << "Queue is Full\n";
            return;
        } else if (front == -1) {  // First element insertion
            front = rear = 0;
            queue[rear] = value;
        } else {  // Normal case and wrap around
            rear = (rear + 1) % size;
            queue[rear] = value;
        }
    }

    // Function to delete an element from the queue
    int dequeue() {
        if (front == -1) {  // Check if the queue is empty
            cout << "Queue is Empty\n";
            return -1;
        }

        int data = queue[front];
        queue[front] = -1;  // Optional: Reset the dequeued position

        if (front == rear) {  // Queue has only one element, reset the queue after dequeuing
            front = rear = -1;
        } else {  // Normal case and wrap around
            front = (front + 1) % size;
        }

        return data;
    }

    // Function to display the queue elements
    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Elements in the circular queue are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
        } else {  // If rear has wrapped around
            for (int i = front; i < size; i++)
                cout << queue[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);  // Create a queue with size 5

    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(6);

    q.display();

    cout << "Dequeued value: " << q.dequeue() << endl;

    q.display();

    q.enqueue(9);
    q.enqueue(20);

    q.display();

    return 0;
}
