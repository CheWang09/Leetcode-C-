class Solution:
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        A = a.split('+')
        a1 = int(A[0])
        a2 = int(A[1].split('i')[0])
        B = b.split('+')
        b1 = int(B[0])
        b2 = int(B[1].split('i')[0])
        return '%d+%di' % (a1 * b1 - a2 * b2, a1 * b2 + a2 * b1)
        