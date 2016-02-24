#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode * next;
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
    ListNode *temp = newHead;
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
        temp->next = p2;
    else if (p2 == nullptr)
        temp->next = p1;
    return newHead->next;
}

ListNode *mergeKLists(vector<ListNode*> vheads)
{
    ListNode *head = mergeTwoLists(vheads[0],vheads[1]);
    for (int i=2; i<vheads.size();i++)
    {
        head = mergeTwoLists(head,vheads[i]);
    }
    return head;
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
    ListNode *n7 = new ListNode(13);
    ListNode *n6 = new ListNode(11,n7);
    ListNode *n5 = new ListNode(10,n6);
    ListNode *n4 = new ListNode(9,n5);
    ListNode *n3 = new ListNode(6,n4);
    ListNode *n2 = new ListNode(4,n3);
    ListNode *n1 = new ListNode(2,n2);
    display(n1);
    vector<ListNode*> vheads;
    vheads.push_back(l1);
    vheads.push_back(m1);
    vheads.push_back(n1);
    ListNode *merge = mergeKLists(vheads);
    display(merge);
    return 0;
}
