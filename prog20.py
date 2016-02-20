def isValid(s):
    st=[]
    for x in s:
        if x=='{' or x=='[' or x=='(':
            st.insert(0,x)
        elif x=='}' or x==']' or x==')':
            if len(st)==0:
                return False
            sx=st[0]
            if (sx=='{' and x=='}') or (sx=='[' and x==']') or (sx=='(' and x==')'):
                    st.pop(0)
            else:
                return False
        else:
            return False
    return len(st)==0

s="{{}{[]()}}"
print (s,isValid(s))
s="{{}}"
print (s,isValid(s))
s="{]"
print (s,isValid(s))
