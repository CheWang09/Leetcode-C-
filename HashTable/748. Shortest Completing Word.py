class Solution:
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        regex = re.compile('[^a-zA-Z]')
        licensePlate = regex.sub('', licensePlate)
        # licensePlate = licensePlate.lower()
        # licensePlate = licensePlate.split(' ')
        # licensePlate1 = re.findall(r'[^0-9]',licensePlate[0])
        # licensePlate2 = re.findall(r'[^0-9]',licensePlate[1])
        # licensePlate1.extend(licensePlate2)
        # it doesn't work
        res = ''
        
        count = collections.Counter(licensePlate.lower())
        
        for word in words:
            countword = collections.Counter(word.lower())
            countword.subtract(count)
            if all(map(lambda x: x >= 0, countword.values())):
                 if res == '' or len(word) < len(res):
                    res = word
        return res
