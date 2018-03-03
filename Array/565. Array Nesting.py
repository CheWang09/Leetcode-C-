class Solution:
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        length = len(nums)
        visit = [True] * length
        res = 0
        for i in range(length):
            tmp = 0
            tmpi = i
            while visit[tmpi]:
                visit[i] = False
                tmp += 1
                tmpi = nums[tmpi]
            res = max(res, tmp)
        return res
