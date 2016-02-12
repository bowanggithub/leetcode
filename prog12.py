def intToRoman(num):
    symbol=["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
    value=[1000,900,500,400,100,90,50,40,10,9,5,4,1]
    roman=""

    for i in range(len(value)):
        while num >= value[i]:
            roman += symbol[i]
            num -= value[i]
    return roman

num=int(input("enter a number: "))
print (intToRoman(num))
