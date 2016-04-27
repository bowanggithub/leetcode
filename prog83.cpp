#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x, ListNode* n=nullptr) : val(x), next(n) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    if (head->next==nullptr)
        return head;

    ListNode* p=head;
    for (auto i=head; i->next!=nullptr; i=i->next)
    {
        if (i->val != p->val)
        {
            p=p->next;
            p->val = i->val;
        }
    }
    p->next=nullptr;
    return head;
}

void show(ListNode* head)
{
    auto iter=head;
    for (; iter->next!=nullptr; iter=iter->next)
        cout << iter->val << "->";
    cout << iter->val << endl;
}

int main()
{
    ListNode* i5=new ListNode(3);
    ListNode* i4=new ListNode(3,i5);
    ListNode* i3=new ListNode(2,i4);
    ListNode* i2=new ListNode(1,i3);
    ListNode* i1=new ListNode(1,i2);
    show(i1);

    show(deleteDuplicates(i1));
}
