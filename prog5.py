def findPalindrome(s,left,right):
    n=len(s)
    l=left
    r=right
    while l>=0 and r<=n-1 and s[l]==s[r]:
        l-=1
        r+=1
    return s[l+1:r]

def findLongestPalindrome(s):
    n=len(s)
    if n<=1:
        return s

    longest=""
    for i in range(n-1):
        string=findPalindrome(s,i,i)
        if len(string) > len(longest):
            longest=string
        string=findPalindrome(s,i,i+1)
        if len(string) > len(longest):
            longest=string

    return longest

s="abacdfgdcaba"
print (findLongestPalindrome(s))
s="abcdefgedcba"
print (findLongestPalindrome(s))

