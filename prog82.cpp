#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x, ListNode* n=nullptr) : val(x), next(n) {}
};
void show(ListNode* head);

ListNode* deleteDuplicates(ListNode* head)
{
    if (head->next==nullptr)
        return head;
    bool dup=false;
    ListNode fakehead(999,head);
    ListNode* p=&(fakehead);
    auto i=head->next;
    while (i!=nullptr)
    {
        if (i->val==p->next->val)
        {
            dup=true;
            i=i->next;
        }
        else if (i->val != p->next->val && dup && p->next!=head)
        {
            p->next=i;
            i=i->next;
            dup=false;
        }
        else if (i->val != p->next->val && dup && p->next==head)
        {
            head=i;
            p->next=i;
            i=i->next;
            dup=false;
        }
        else if (i->val != p->next->val && !dup)
        {
            p=p->next;
            i=i->next;
            dup=false;
        }
    }
    if (dup && p->next != head)
        p->next=nullptr;
    else if (dup && p->next == head)
        head=nullptr;

    return head;
}

void show(ListNode* head)
{
    auto iter=head;
    for (; iter!=nullptr; iter=iter->next)
        cout << iter->val << "->";
    cout << "nullptr" << endl;
}

int main()
{
    ListNode* i5=new ListNode(3);
    ListNode* i4=new ListNode(3,i5);
    ListNode* i3=new ListNode(2,i4);
    ListNode* i2=new ListNode(2,i3);
    ListNode* i1=new ListNode(1,i2);
    show(i1);

    show(deleteDuplicates(i1));
}
