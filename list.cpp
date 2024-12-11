#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int x){
        val = x;
        next=nullptr;
    }
};

class List{
    private:
    Node* head;
    public:
    List(){
        head=nullptr;
        head->prev = nullptr;
    }
    void InsertatHead(int x){
        Node* n = new Node(x);
        if(head == nullptr){
            head = n;
            return;
        }
        head = n;
        n->next = head;
    }
    void Display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
    }
    bool isEmpty(){
        return head==nullptr;
    }
    void insertattail(int x){
        Node* n = new Node(x);
        if (head==nullptr){
            head = n;
        }
        Node* temp = head;
        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
};

main(){
    List l;
    l.InsertatHead(5);
    l.Display();

}
