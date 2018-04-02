class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dicts = {}
        res = []
        for s in strs:
            tmp = ''.join(sorted(s))
            if tmp in dicts.keys():
                dicts[tmp].append(s)
            else:
                dicts[tmp] = []
                dicts[tmp].append(s)
        res = [value for index, value in dicts.items()]
        return res
