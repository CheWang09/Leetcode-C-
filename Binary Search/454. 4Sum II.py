class Solution:
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        E = {}
        
        for a in A:
            for b in B:
                if a+b not in E:
                    E[a+b] = 0
                E[a+b] += 1
                
        res = 0
        
        for c in C:
            for d in D:
                if -(c+d) in E:
                    res += E[-(c+d)]
        
        return res