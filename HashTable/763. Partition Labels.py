class Solution:
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        if S == '':
            return []
        checkdict = {}
        res = []
        for i,char in enumerate(S):
            if char in S[i+1:]:
                checkdict[char] = 1
            else:
                checkdict[char] = 0
            if sum(list(checkdict.values())) == 0:
                checkdict.clear()
                if res == []:
                    res.append(i+1)
                else:
                    res.append(i-sum(res[:])+1)
        return res
