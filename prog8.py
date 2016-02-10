def myatoi(s):
    if len(s)==0:
        return 0
    i=0
    while i<len(s) and s[i].isspace():
        i+=1

    result=0
    if s[i]=='-':
        sign=-1
        i+=1
    elif s[i]=='+':
        sign=1
        i+=1
    else:
        sign=1

    while i<len(s) and s[i].isdigit():
        digit=ord(s[i])-ord('0')
        result=10*result+digit
        i+=1
    return result*sign

x="   -123"
print (x,myatoi(x))
print (myatoi(x)*5)
