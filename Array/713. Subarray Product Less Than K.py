// It is a window concept and use pyhton to implement this algorithm

class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k <= 1: return 0
        ans = 0
        left = 0
        ##product = 1
        pro = 1
        for right,val in enumerate(nums):
            pro *= val
            # right = left
            # for right, vals in enumerate(nums):
            #     pro *= vals
            #     if pro >= k:
            #         break
            while pro >= k:
                pro /= nums[left]
                left += 1
            ans += right - left + 1
        return ans
                    
                
