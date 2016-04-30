#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x, ListNode* n=nullptr) : val(x), next(n) {}
};

void show(ListNode* head)
{
    auto iter=head;
    for (; iter->next!=nullptr; iter=iter->next)
        cout << iter->val << "->";
    cout << iter->val << endl;
}

ListNode* partition(ListNode* head, int x)
{
    ListNode fake(999,head);
    ListNode* fakehead=&fake;
    ListNode* pos=nullptr;

    for (ListNode* p=fakehead; p->next!=nullptr;)
    {
        if (pos==nullptr && p->next->val>= x)
        {
            pos=p;
        }
        else if (pos!=nullptr && p->next->val <x)
        {
            ListNode* temp=p->next;
            p->next=p->next->next;
            temp->next=pos->next;
            pos->next=temp;
            continue;
        }
        p=p->next;
    }

    return fakehead->next;
}

ListNode* create(vector<int> nums)
{
    ListNode* head=nullptr;
    for (int i=nums.size()-1; i>=0; i--)
    {
        ListNode* temp= new ListNode(nums[i],head);
        head=temp;
    }
    return head;
}

int main()
{
    vector<int> num{1,4,3,2,5,2};
    ListNode* head=create(num);
    show(head);
    ListNode* newhead=partition(head, 3);
    show(newhead);
}

