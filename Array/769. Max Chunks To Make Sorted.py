class Solution:
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        res = 0
        max_value = 0 
        for i, value in enumerate(arr):
            max_value = max(value, max_value)
            if max_value == i:
                res += 1
        return res
