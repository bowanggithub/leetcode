#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int x, ListNode* n=nullptr) : val(x), next(n) {}
};

void show(ListNode* head)
{
    ListNode* p=head;
    while (p!= nullptr)
    {
        cout << p->val << "->";
        p=p->next;
    }
    cout << "NULL" << endl;
}

ListNode* rotateRight(ListNode* head, int k)
{
    ListNode* nextk=head;
    ListNode* rotatepos=head;
    for (int i=0; i<k;++i)
        nextk=nextk->next;

    while (nextk->next)
    {
        nextk=nextk->next;
        rotatepos=rotatepos->next;
    }

    ListNode* p=rotatepos->next;
    rotatepos->next=nullptr;
    nextk->next=head;
    return p;
}

int main()
{
    ListNode* l5 = new ListNode(5);
    ListNode* l4 = new ListNode(4,l5);
    ListNode* l3 = new ListNode(3,l4);
    ListNode* l2 = new ListNode(2,l3);
    ListNode* l1 = new ListNode(1,l2);
    show(l1);
    show(rotateRight(l1,3));
    return 0;
}
