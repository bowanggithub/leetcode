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
        head = head->next;
    }
    cout << head->val << endl;
}

ListNode* reverseList(ListNode* head)
{
    ListNode* newList = nullptr;
    ListNode* tempNode = nullptr;
    while (head)
    {
        tempNode = head;
        head = head->next;
        tempNode->next = newList;
        newList = tempNode;
    }
    return newList;
}

int main()
{
    ListNode *l6=new ListNode(6);
    ListNode *l5=new ListNode(5,l6);
    ListNode *l4=new ListNode(4,l5);
    ListNode *l3=new ListNode(3,l4);
    ListNode *l2=new ListNode(2,l3);
    ListNode *l1=new ListNode(1,l2);
    display(l1);
    ListNode* reverse = reverseList(l1);
    display(reverse);
    display(l1);
    return 0;
}
