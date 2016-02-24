#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x, ListNode *n=nullptr)
    {
        val=x;
        next=n;
    }
};

void display(ListNode* head)
{
    while (head->next != nullptr)
    {
        cout << head->val << "->";
        head=head->next;
    }
    cout << head->val << endl;
}

ListNode *mergeTwoLists(ListNode* head1, ListNode* head2)
{
    ListNode *p1=head1, *p2=head2;
    ListNode *newHead = new ListNode(0);
    ListNode *temp=newHead;
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->val < p2->val)
        {
            temp->next = p1;
            p1 = p1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = p2;
            p2 = p2->next;
            temp = temp->next;
        }
    }
    if (p1 == nullptr)
    {
        temp->next = p2;
    }
    else if (p2 == nullptr)
    {
        temp->next = p1;
    }
    return newHead->next;
}

int main()
{
    ListNode *l5 = new ListNode(15);
    ListNode *l4 = new ListNode(9,l5);
    ListNode *l3 = new ListNode(5,l4);
    ListNode *l2 = new ListNode(3,l3);
    ListNode *l1 = new ListNode(1,l2);
    display(l1);
    ListNode *m7 = new ListNode(14);
    ListNode *m6 = new ListNode(12,m7);
    ListNode *m5 = new ListNode(10,m6);
    ListNode *m4 = new ListNode(8,m5);
    ListNode *m3 = new ListNode(6,m4);
    ListNode *m2 = new ListNode(4,m3);
    ListNode *m1 = new ListNode(2,m2);
    display(m1);
    ListNode * merge=mergeTwoLists(l1,m1);
    display(merge);
    return 0;
}


