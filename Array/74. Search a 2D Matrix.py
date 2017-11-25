class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        rows = len(matrix)
        if rows == 0:
            return False
        columns = len(matrix[0])
        if columns == 0:
            return False
        In_row = 0
        for i in range(0, rows):
            if target <= matrix[i][columns-1]:
                In_row = i
                break
        if target in matrix[In_row]:
            return True
        else:
            return False
