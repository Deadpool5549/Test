#include<iostream>
using namespace std;
namespace doubly
{
    class Node
    {
    public:
        int data;
        Node* next;
        Node* prev;
    };
    Node* head = NULL;
    void InsertAtBegin()
    {
        int data;
        printf("Enter data front: ");
        cin >> data;
        Node* temp = new Node();
        temp->data = data;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
    }
    void InsertEnd()
    {
        int data;
        printf("Enter data end: ");
        cin >> data;
        Node* temp = new Node();
        Node* it = head;
        temp->data = data;
        while (it->next != NULL)
        {
            it = it->next;
        }
        it->next = temp;
        temp->prev = it;
        temp->next = NULL;
    }
    void Print()
    {
        Node* it = head;
        while (it != NULL)
        {
            cout << it->data << endl;
            it = it->next;
        }
    }
}