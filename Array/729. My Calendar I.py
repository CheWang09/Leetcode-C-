class MyCalendar:
    
    def __init__(self):
        self.__dict = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        for [s,e] in self.__dict:
            if end > s and start < e:
                return False
        self.__dict.append([start, end])
        return True
        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
