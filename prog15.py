def threeSum(nums):
    answers=[]
    for i in range(len(nums)-2):
        target=-nums[i]
        d={}
        for j in range(i+1,len(nums)):
            if nums[j] not in d:
                d[target-nums[j]] = nums[j]
            else:
                ans=[]
                #print (-target, d[nums[j]], nums[j])
                ans.append(-target)
                ans.append(d[nums[j]])
                ans.append(nums[j])
                answers.append(ans)
    return answers

S=[-1,0,1,2,-1,-4]
print (S)
S.sort()
print (S)
print (threeSum(S))

