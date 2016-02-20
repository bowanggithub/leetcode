def twoSumClosest(nums,target):
    if len(nums) <2:
        return 1000;
    distance=nums[0]+nums[1]-target
    for i in range(len(nums)-1):
        for j in range(i+1,len(nums)):
            if abs(nums[i]+nums[j]-target) < abs(distance):
                distance = nums[i]+nums[j]-target
    return distance

def threeSumClosest(nums, target):
    distance3=nums[0]+nums[1]+nums[2]-target
    for i in range(len(nums)):
        subnums=nums[i+1:]
        distance = twoSumClosest(subnums,target-nums[i])
        if abs(distance) < abs(distance3):
            distance3=distance
    return target+distance3

S=[-4,-1,1,2]
print (S)
print (threeSumClosest(S,-1))

