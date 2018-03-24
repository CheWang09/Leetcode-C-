class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        dicts = sorted(dict, key=len, reverse=True)
        lists = sentence.split(' ')
        for root in dicts:
            for i in range(len(lists)):
                if root in lists[i]:
                    lists[i]=root
        return ' '.join(lists)


class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        words = set(dict)
        
        def replace(word):
            for i in range(len(word)):
                if word[:i] in words:
                    return word[:i]
            return word
        
        return ' '.join(map(replace, sentence.split()))
