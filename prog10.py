def isMatch(s,p):
    if len(p)==0:
        return (len(s)==0)
    elif len(s)==0 and len(p)==2 and p[1]=='*':
        return True
    elif len(s)==0:
        return False
    elif len(p)==1 and p != ".":
        return (s==p)
    elif len(p)==1 and p == ".":
        return (len(s)==1)
    elif p[1] != '*':
        return ((s[0]==p[0]) or (p[0]=='.')) and isMatch(s[1:],p[1:])
    elif p[1] == '*' and p[0] != s[0] and p[0] != '.':
        return isMatch(s,p[2:])
    else:
        return isMatch(s[1:],p)

s=input("enter s: ")
p=input("enter p: ")
print (isMatch(s,p))
