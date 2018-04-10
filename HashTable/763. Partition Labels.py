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
  

###second method:::
class Solution:
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        dicts = {j:i for i,j in enumerate(S)}
        start = j = 0
        res = []
        for i, char in enumerate(S):
            j = max(j, dicts[char])
            if i == j:
                res.append(j-start+1)
                start = i + 1
        return res
