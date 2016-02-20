def letterCombinations(digits):
    phone=[];
    phone.append("")
    phone.append("")
    phone.append("abc")
    phone.append("def")
    phone.append("ghi")
    phone.append("jkl")
    phone.append("mno")
    phone.append("pqrs")
    phone.append("tuv")
    phone.append("wxyz")

    n= len(digits)
    if n==0:
        comb=[""]
        return comb

    subdigits=digits[1:]
    subcomb=letterCombinations(subdigits)
    m=int(digits[0])
    comb=[]
    for i in range(len(phone[m])):
        for j in range(len(subcomb)):
            newcomb=phone[m][i] + subcomb[j]
            comb.append(newcomb)
    return comb

digits="23"
combinations=letterCombinations(digits)
print (combinations)
