#include<iostream>
#include<string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Stack {
private:
    Node* head;
public:
    Stack() {
        head = nullptr;
    }
    
    ~Stack() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
    
    void Push(string x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }
    
    string Pop() {
        if (IsEmpty()) {
            return "No elements to pop";
        }
        Node* next = head->next;
        string todelete = head->data;
        delete head;
        head = next;
        return todelete;
    }
    
    string Peek() {
        if (IsEmpty()) {
            return "Stack is empty";
        }
        return head->data;
    }
    
    bool IsEmpty() {
        return head == nullptr;
    }
};

void ReverseWords(string sentence) {
    Stack s;
    string word = "";

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') {
            if (!word.empty()) {
                s.Push(word);
                word = "";  
            }
        } else {
            word += sentence[i];
        }
    }

    if (!word.empty()) {
        s.Push(word);
    }

    cout << "Output: ";
    while (!s.IsEmpty()) {
        cout << s.Pop();
        if (!s.IsEmpty()) {
            cout << " ";  
        }
    }
    cout << endl;
}

int main() {
    string input = "I am from University of Engineering and Technology Lahore";
    ReverseWords(input);
    return 0;
}
