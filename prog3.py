def lengthOfLongestSubstring(s):
    d={}
    pos=0
    templongest=0
    longest=0
    for i in range(len(s)):
        if s[i] not in d:
            d[s[i]]=i
            templongest+=1
        elif i-d[s[i]] <= templongest:
            templongest=i-d[s[i]]
            d[s[i]]=i
        else:
            templongest+=1
            d[s[i]]=i

        if longest < templongest:
            longest = templongest
            pos=i

    return pos,longest

s="bbabcdb"
endpoint,length = lengthOfLongestSubstring(s)
print (endpoint,length)
