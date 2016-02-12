def helper(c):
    val=0
    if c=='I':
        val=1
    elif c=='V':
        val=5
    elif c=='X':
        val=10
    elif c=='L':
        val=50
    elif c=='C':
        val=100
    elif c=='D':
        val=500
    elif c=='M':
        val=1000
    return val

def romanToInt(s):
    if len(s)==0:
        return 0
    elif len(s)==1:
        return helper(s)

    result=0
    if helper(s[0]) < helper(s[1]):
        result = result - helper(s[0]) + helper(s[1]) + romanToInt(s[2:])
    else:
        result = result + helper(s[0]) + romanToInt(s[1:])
    return result

s=input("enter roman: ")
print (romanToInt(s))
