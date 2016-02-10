def convert(s,nRows):
    r=[""]*nRows
    row=0
    step=1
    for i in range(len(s)):
        r[row] += s[i]
        if row==nRows-1:
            step=-1
        elif row==0:
            step=1
        row+=step

    result=""
    for i in range(nRows):
        result += r[i]

    return result

s="PAYPALISHIRING"
print (s,convert(s,3))
