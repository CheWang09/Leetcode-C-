class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        dicts = {}
        for i in range(len(s)):
            if s[i:i+10] in dicts.keys():
                dicts[s[i:i+10]] += 1
                res.append(s[i:i+10])
            else:
                dicts[s[i:i+10]] = 1
        res = set(res)
        return list(res)
