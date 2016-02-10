def inttolist(x):
    l=[]
    while x != 0:
        n=x%10
        l.insert(0,n)
        x=x//10
    return l

def isPalindrome(x):
    l1=inttolist(x);
    l2=l1[::-1]
    return l1==l2


x=12321
print (isPalindrome(x))
