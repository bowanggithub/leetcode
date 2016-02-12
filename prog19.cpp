#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int x, ListNode* n=NULL)
    {
        val=x;
        next=n;
    }
};

void display(ListNode* temp)
{
    while (temp->next != NULL)
    {
        cout << temp->val << "->";
        temp=temp->next;
    }
    cout << temp->val << endl;
}

ListNode* removeNthFromEnd(ListNode *head, int n)
{
    ListNode 
