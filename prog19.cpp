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
    ListNode *p1,*p2;
    p1=head;p2=p1;
    for (int i=0;i<n;i++)
    {
        p2=p2->next;
    }
    while (p2->next != NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=p1->next->next;
    return head;
}

int main()
{
    ListNode * n1 = new ListNode(1);
    ListNode * n2 = new ListNode(2);
    ListNode * n3 = new ListNode(3);
    ListNode * n4 = new ListNode(4);
    ListNode * n5 = new ListNode(5);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    display(n1);
    display(removeNthFromEnd(n1,2));
    return 0;
}



