#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};
Node* head = NULL;

void PrintList()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void AddAtN()
{
    int n, p;
    printf("enter data and pos: ");
    cin >> n >> p;
    Node* temp = new Node();
    Node* it = head;//iterator
    temp->data = n;
    temp->next = NULL;
    if (p == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        for (int i = 0; i < p - 2; i++) // Index starts from 1,we are going for p-1 th node,as this happens p-2 times
        //IF IT happens once we will be at 2nd node
        //(if it happens p-2 times we will be at p-1, thats where we want to be)
        {
            it = it->next;

        }
        temp->next = it->next;
        it->next = temp;
    }

}
void ite(int n)
{
    Node* it = head;
    for (int i = 1; i < n - 1; i++)
    {
        it = it->next;
        printf("%d-", it->data);
        //it=it->next;
    }
    printf("/n%d---", it->data);
}
void Del_atN(int n)
{
    Node* temp = head;
    Node* t2 = NULL;
    for (int i = 0; i < n - 2; i++)
    {
        temp = temp->next;//pointing at n-1 node after loop
    }
    t2 = temp->next;//t2 pointing at nth
    temp->next = t2->next;//break link
    delete t2;//delete as we used new keyword to allocate
}
void Rev()
{
    Node* curr = head;
    Node* prev = NULL;
    Node* Next=NULL;
    while (curr != NULL)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }

    head = prev;
}
//Using Recursion
void RecRev(Node* curr,Node* prev)
{
    if (curr->next == NULL)//base case
    {
        curr->next = prev;
        head = curr;
        return;
    }
    Node* Next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = Next;
    RecRev(curr, prev);

}
int main()
{
    for (int i = 0; i < 6; i++)
    {
        AddAtN();
    }
    PrintList();
    Node* pr = NULL;
    RecRev(head,pr);
    printf("After \n");
    PrintList();
    return 0;
}