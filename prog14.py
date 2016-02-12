def longestCommonPrefix(strs):
    prefix=""
    if len(strs)==0:
        return prefix

    lengths=[]
    for x in strs:
        lengths.append(len(x))
    n=min(lengths)
    match=True
    for i in range(n):
        c=strs[0][i]
        for j in range(len(strs)):
            if c != strs[j][i]:
                match=False

        if match:
            prefix += c
    return prefix

s=["abab","aba","abc"]
print (longestCommonPrefix(s))
