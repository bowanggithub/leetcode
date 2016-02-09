def findKSortedArrays(nums1,nums2,k):
    l1=len(nums1)
    l2=len(nums2)
    if l1 > l2:
        nums1,nums2 = nums2,nums1
    l1=len(nums1)
    l2=len(nums2)

    k1=(min(l1,k)-1)//2
    k2=k-k1-2

    if l1 == 0:
        return nums2[k-1]
    elif l2 == 0:
        return nums1[k-1]
    elif k == 1:
        return min(nums1[0],nums2[0])
    elif nums1[k1] == nums2[k2]:
        return nums1[k1]
    elif nums1[k1] > nums2[k2]:
        print(nums1[:k1+1])
        print(nums2[k2+1:])
        print("find: ",k-k2-1)
        return findKSortedArrays(nums1[:k1+1],nums2[k2+1:],k-k2-1)
    else:
        print(nums1[k1+1:])
        print(nums2[:k2+1])
        print("find: ",k-k1-1)
        return findKSortedArrays(nums1[k1+1:],nums2[:k2+1],k-k1-1)

nums1=[1,12,15,26,38,50]
nums2=[2,13,17,30,45]
for k in [1,2,3,4,5,6,7,8,9]:
    print("k=",k)
    print (findKSortedArrays(nums1,nums2,k))
