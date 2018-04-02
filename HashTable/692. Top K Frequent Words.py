from collections import Counter
from operator import itemgetter
class Solution:
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        res = Counter(words)
        res2 = list(res.keys())
        res2.sort(key=lambda x:(-res[x], x))
        return res2[:k]
