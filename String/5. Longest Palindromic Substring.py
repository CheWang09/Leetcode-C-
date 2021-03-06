class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ''
        
        for i in range(len(s)):
            res = max(self.helper(i, i ,s), self.helper(i, i+1, s), res, key=len)
        
        return res
    
    def helper(self, l, r, s):
        while l >= 0 and r < len(s) and s[l]==s[r]:
            l -= 1
            r += 1
        return s[l+1:r]
            
