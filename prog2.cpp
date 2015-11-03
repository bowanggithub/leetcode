//add two numbers
#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode * next; 
    ListNode(int x, ListNode* n =NULL)
    {
        val=x;
        next=n;
    }
};

void display(ListNode * temp)
{
    while (temp->next != NULL)
    {
        cout << temp->val << "->";
        temp=temp->next;
    }
    cout << temp->val << endl;
}

ListNode *addTwoNumbers(ListNode *n1, ListNode *n2)
{
    int x,y,sum,carry=0;
    x=n1->val;y=n2->val;
    sum=(x+y)%10;carry=(x+y)/10;
    ListNode *answer=new ListNode(sum);
    ListNode *temp=answer;

    while (n1->next != NULL && n2->next != NULL)
    {
        n1=n1->next;
        n2=n2->next;
        x=n1->val;y=n2->val;
        sum=(x+y+carry)%10;carry=(x+y+carry)/10;
        temp->next=new ListNode(sum);
        temp=temp->next;
    }
    while (n1->next != NULL)
    {
        n1=n1->next;
        x=n1->val;
        sum=(x+carry)%10;carry=(x+carry)/10;
        temp->next=new ListNode(sum);
        temp=temp->next;
    }
    while (n2->next != NULL)
    {
        n2=n2->next;
        y=n2->val;
        sum=(y+carry)%10;carry=(y+carry)/10;
        temp->next=new ListNode(sum);
        temp=temp->next;
    }
    if (carry != 0)
    {
        temp->next=new ListNode(carry);
    }
    return answer;
}


int main()
{
    ListNode *l4=new ListNode(9);
    ListNode *l3=new ListNode(6,l4);
    ListNode *l2=new ListNode(7,l3);
    ListNode *l1=new ListNode(8,l2);
    display(l1);
    ListNode *m3=new ListNode(5);
    ListNode *m2=new ListNode(2,m3);
    ListNode *m1=new ListNode(2,m2);
    display(m1);
    ListNode *answer = addTwoNumbers(l1,m1);
    display(answer);
    return 0;
}
