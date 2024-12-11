#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* previous;
    Node* next;
};

class DoubleLinkList
{
private:
    Node* head;
public:
    DoubleLinkList()
    {
        head = nullptr;
    }

    ~DoubleLinkList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    Node* GetHead()
    {
        return head;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }

    Node* insertNode(int index, int x)
    {
        if (index < 0)
        {
            return nullptr;
        }
        Node* newNode = new Node();
        newNode->data = x;
        if (index == 0)
        {
            newNode->previous = nullptr;
            newNode->next = head;
            if (head != nullptr) head->previous = newNode;
            head = newNode;
        }
        else
        {
            Node* currentNode = head;
            for (int i = 0; i < index - 1 && currentNode != nullptr; i++)
            {
                currentNode = currentNode->next;
            }
            if (currentNode == nullptr)
                return nullptr;
            newNode->previous = currentNode;
            newNode->next = currentNode->next;
            if (currentNode->next != nullptr) {
                currentNode->next->previous = newNode;
            }
            currentNode->next = newNode;
        }
        return head;
    }

    Node* insertAtHead(int x)
    {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->previous = nullptr;
        newNode->next = head;
        if (head != nullptr) head->previous = newNode;
        head = newNode;
        return head;
    }

    Node* insertAtEnd(int x)
    {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            newNode->previous = nullptr;
            head = newNode;
        }
        else
        {
            Node* last = head;
            while (last->next != nullptr)
            {
                last = last->next;
            }
            last->next = newNode;
            newNode->previous = last;
        }
        return head;
    }

    bool findNode(int x)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == x)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool deleteNode(int x)
    {
        while (head != nullptr && head->data == x)
        {
            Node* next = head->next;
            delete head;
            if (next != nullptr) {
                next->previous = nullptr;
            }
            head = next;
        }

        if (head == nullptr) {
            return true;
        }

        Node* current = head;
        while (current != nullptr && current->next != nullptr)
        {
            if (current->next->data == x)
            {
                Node* nodeToRemove = current->next;
                current->next = nodeToRemove->next;
                if (nodeToRemove->next != nullptr) {
                    nodeToRemove->next->previous = current;
                }
                delete nodeToRemove;
            }
            else {
                current = current->next;
            }
        }

        return true;
    }

    bool deleteFromStart()
    {
        if (head == nullptr) return false;

        Node* next = head->next;
        if (next != nullptr) next->previous = nullptr;
        delete head;
        head = next;
        return true;
    }

    bool deleteFromEnd()
    {
        if (head == nullptr) return false;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return true;
        }

        Node* last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->previous->next = nullptr;
        delete last;
        return true;
    }

    void displayList()
    {
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
            return;
        }

        Node* currentNode = head;
        cout << "Linked List: ";
        while (currentNode != nullptr)
        {
            cout << currentNode->data << " ---> ";
            currentNode = currentNode->next;
        }
        cout << "Null" << endl;
    }

    Node* reverseList()
    {
        if (IsEmpty()) return nullptr;

        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr)
        {
            Node* next = current->next;
            current->next = prev;
            current->previous = next;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    Node* sortList(Node* list)
    {
        for (Node* i = list; i->next != nullptr; i = i->next)
        {
            Node* minNode = i;
            for (Node* j = i->next; j != nullptr; j = j->next)
            {
                if (j->data < minNode->data)
                {
                    minNode = j;
                }
            }
            swap(i->data, minNode->data);
        }
        return list;
    }

    Node* removeDuplicates(Node* list)
    {
        Node* current = list;
        while (current != nullptr && current->next != nullptr)
        {
            Node* remaining = current;
            while (remaining->next != nullptr)
            {
                if (current->data == remaining->next->data)
                {
                    Node* nodeToRemove = remaining->next;
                    remaining->next = nodeToRemove->next;
                    if (nodeToRemove->next != nullptr) {
                        nodeToRemove->next->previous = remaining;
                    }
                    delete nodeToRemove;
                }
                else
                {
                    remaining = remaining->next;
                }
            }
            current = current->next;
        }
        return list;
    }

    Node* mergeLists(Node* list1, Node* list2)
    {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->data < list2->data)
        {
            list1->next = mergeLists(list1->next, list2);
            if (list1->next != nullptr)
            {
                list1->next->previous = list1;
            }
            return list1;
        }
        else
        {
            list2->next = mergeLists(list1, list2->next);
            if (list2->next != nullptr)
            {
                list2->next->previous = list2;
            }
            return list2;
        }
    }

    Node* interestLists(Node* list1, Node* list2)
    {
        DoubleLinkList intersection;
        Node* first = list1;
        Node* second;
        while (first != nullptr)
        {
            second = list2;
            while (second != nullptr)
            {
                if (first->data == second->data)
                {
                    if (!intersection.findNode(first->data))
                    {
                        intersection.insertAtEnd(first->data);
                    }
                }
                second = second->next;
            }
            first = first->next;
        }
        intersection.displayList();
        return intersection.GetHead();
    }
};

int main()
{
    DoubleLinkList list;
    DoubleLinkList list2;

    list.insertAtEnd(10);
    list.insertAtEnd(30);
    list.insertAtEnd(20);
    list.insertAtHead(30);
    list.insertAtHead(5);
    list.insertAtEnd(30);
    list.insertAtEnd(30);
    list.insertNode(3, 3);
    list.displayList();

    list.deleteFromStart();
    list.displayList();

    list.deleteFromEnd();
    list.displayList();

    list.deleteNode(30);
    list.displayList();

    cout << "Find 20: " << list.findNode(20) << endl;
    cout << "Find 2: " << list.findNode(2) << endl;

    list2.insertAtEnd(3);
    list2.insertAtEnd(5);
    list2.insertAtEnd(7);
    list2.insertAtEnd(3);
    list2.insertAtEnd(7);
    list2.insertAtEnd(7);
    list2.displayList();

    Node* first = list2.GetHead();
    list2.sortList(first);
    list2.displayList();

    list2.removeDuplicates(first);
    list2.displayList();

    list2.reverseList();
    list2.displayList();

    Node* mergedList = list.mergeLists(list.GetHead(), list2.GetHead());
    cout << "Merged List: ";
    while (mergedList != nullptr)
    {
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }
    cout << endl;
}
