def twoSum(numbers, target):
    d={}
    for i in range(len(numbers)):
        if numbers[i] not in d:
            d[target-numbers[i]] = i
            print i
            print d
        else:
            break
    
    return d[numbers[i]]+1, i+1
    #return i

numbers=[2,7,11,15]
target=18
print twoSum(numbers,target)

