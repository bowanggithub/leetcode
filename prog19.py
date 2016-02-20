class ListNode:
    def __init__(self,x):
        self.val=x
        self.next = None
    def display(self):
        if self.next == None:
            print (self.val)
        else:
            print (self.val,"->",end="")
            self.next.display()

def removeNthFromEnd(head,n):
    p1=head
    p2=p1
    for i in range(n):
        p2=p2.next
    while p2.next != None:
        p1=p1.next
        p2=p2.next
    p1.next=p1.next.next
    return head

n1=ListNode(1)
n2=ListNode(2)
n3=ListNode(3)
n4=ListNode(4)
n5=ListNode(5)
n1.next=n2
n2.next=n3
n3.next=n4
n4.next=n5
n1.display()
removeNthFromEnd(n1,2).display()


