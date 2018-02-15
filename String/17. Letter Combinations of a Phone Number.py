class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if '' == digits : return []
        ret = ['']
        maps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        for c in digits:
            tmp = []
            for x in ret:
                for y in maps[c]:
                    tmp.append(x+y)
            ret = tmp
        
        return ret
                
