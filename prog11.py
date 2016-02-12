def maxArea(height):
    n=len(height)
    maxArea=0
    left=0
    right=n-1

    while left<right:
        maxArea = max(maxArea, (right-left)*min(height[left],height[right]))
        if height[left] < height[right]:
            left+=1
        else:
            right-=1
    return maxArea


height=[1,2,3,4,5,6]
print (maxArea(height))
