def threeSum(nums,tar):
    answers=[]
    for i in range(len(nums)-2):
        target=tar-nums[i]
        d={}
        for j in range(i+1,len(nums)):
            if nums[j] not in d:
                d[target-nums[j]] = nums[j]
            else:
                ans=[];
                ans.append(nums[i])
                ans.append(d[nums[j]])
                ans.append(nums[j])
                answers.append(ans)
    return answers

def fourSum(nums):
    answers4=[]
    for i in range(len(nums)-3):
        subnums=nums[i+1:]
        answers3=threeSum(subnums,-nums[i])
        for j in range(len(answers3)):
            ans3=answers3[j]
            ans4=[nums[i]] + ans3
            answers4.append(ans4)
    return answers4

a=[1,0,-1,0,-2,2]
print (a)
a.sort()
print (a)
answers4=fourSum(a)
print (answers4)

