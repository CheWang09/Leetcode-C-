class Solution:
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxlength = 0
        count = 0
        dicts = {0:-1}
        for i in range(len(nums)):
            if nums[i] == 0:
                count = count - 1
            else:
                count = count + 1
            if count in dicts.keys(): 
                maxlength = max(maxlength, i-dicts[count])
            else:
                dicts[count] = i
        return maxlength
            
