class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

    def display(self):
        if self.next == None:
            print (self.val)
        else:
            print (self.val,"-> ",end="")
            self.next.display()



def addTwoNumbers(l1,l2,carry):
    if l1 != None and l2 != None:
        value=l1.val + l2.val+carry
        tempNode=ListNode(value%10)
        tempNode.next = addTwoNumbers(l1.next,l2.next,value//10)
        return tempNode
    elif l1 != None:
        value=l1.val + carry
        tempNode=ListNode(value%10)
        tempNode.next = addTwoNumbers(l1.next,None,value//10)
        return tempNode
    elif l2 != None:
        value=l2.val+carry
        tempNode=ListNode(value%10)
        tempNode.next = addTwoNumbers(None,l2.next,value//10)
        return tempNode
    elif carry != 0:
        return ListNode(carry)
    else:
        return None


l4=ListNode(4)
l3=ListNode(8)
l3.next=l4
l2=ListNode(2)
l2.next=l3
l1=ListNode(1)
l1.next=l2
l1.display()

m3=ListNode(3)
m2=ListNode(2)
m2.next=m3
m1=ListNode(9)
m1.next=m2
m1.display()

sum=addTwoNumbers(l1,m1,0)
sum.display()

