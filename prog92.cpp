#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int x, ListNode* n=nullptr)
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
        head= head->next;
    }
    cout << head->val << endl;
}

ListNode * reverseList(ListNode* head, int k)
{
    ListNode *ktermsafter=head;
    int i;
    for (i=0; i<k && ktermsafter != nullptr; i++)
        ktermsafter= ktermsafter->next;
    if (i<k)
        return head;

    ListNode* newListhead = nullptr;
    ListNode* newListend = head;
    ListNode* tempNode = nullptr;
    while (head != ktermsafter)
    {
        tempNode = head;
        head = head->next;
        tempNode->next = newListhead;
        newListhead = tempNode;
    }
    newListend->next = ktermsafter;
    return newListhead;
}

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    ListNode* fakehead = new ListNode(0,head);
    ListNode* mterm=fakehead;
    for (int i=0;i<m-1;i++)
        mterm=mterm->next;
    mterm->next = reverseList(mterm->next,n-m+1);
    return head;
}

int main()
{
    ListNode *l6=new ListNode(6);
    ListNode *l5=new ListNode(5,l6);
    ListNode *l4=new ListNode(4,l5);
    ListNode *l3=new ListNode(3,l4);
    ListNode *l2=new ListNode(2,l3);
    ListNode *l1=new ListNode(1,l2);
    l1 = reverseBetween(l1,4,6);
    display(l1);
    return 0;
}

