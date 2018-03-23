from collections import Counter
class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0:
            return []
        dicts = Counter(s)
        return ''.join([char*times for char, times in dicts.most_common()])
        
class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0:
            return []
        dicts = {}
        lists = []
        for char in s:
            if char in dicts:
                dicts[char] += 1
            else:
                dicts[char] = 1
        index = sorted(dicts.values())
        res = []
        for i in index:
            for key, value in dicts.items():
                if dicts[key] == i:
                    res = res + ([key]*value)
                    dicts[key] = 0
        resstr = ''.join(char for char in res)
        return resstr[::-1]
