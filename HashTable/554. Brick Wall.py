import operator
class Solution:
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        res = {}
        for sublist in wall:
            length = len(sublist)
            gap_index = 0
            for i in range(length-1):
                gap_index += sublist[i]
                if gap_index in res:
                    res[gap_index] += 1
                else:
                    res[gap_index] = 1
        if res == {}:
            return len(wall)
        max_gap = max(res.items(), key = operator.itemgetter(1))[1]
        return (len(wall)-max_gap)
