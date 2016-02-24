#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
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
        head = head->next;
    }
    cout << head->val << endl;
}

ListNode* swapPairs(ListNode* head)
{
    ListNode* n = new ListNode(0);
    ListNode* temp = n;
    ListNode* temp1 = head;
    ListNode* temp2 = head->next;
    n->next = temp2;
    display(n);
    while (temp2->next != nullptr)
    {
        temp1->next = temp2->next;
        temp2->next = temp1;
        temp->next = temp2;
        temp = temp1;
        temp1 = temp1->next;
        temp2 = temp1->next;
        display(n);
        cout << "temp: " << temp->val << endl;
        cout << "temp1: " << temp1->val << endl;
        cout << "temp2: " << temp2->val << endl;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    temp->next = temp2;
    display(n);
    return n->next;
}

int main()
{
    ListNode* l6 = new ListNode(6);
    ListNode* l5 = new ListNode(5,l6);
    ListNode* l4 = new ListNode(4,l5);
    ListNode* l3 = new ListNode(3,l4);
    ListNode* l2 = new ListNode(2,l3);
    ListNode* l1 = new ListNode(1,l2);
    display(l1);
    ListNode* swap = swapPairs(l1);
    display(swap);
    return 0;
}

    
