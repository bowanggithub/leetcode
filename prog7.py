def reverse(x):
    if x>0:
        y=0
        n=x%10
        while x != 0:
            y=10*y+n
            x = x//10
            n=x%10
        return y
    else:
        return -reverse(-x)

x=int(input("enter a number: "))
print (x,reverse(x))
