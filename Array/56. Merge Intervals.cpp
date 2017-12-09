/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool compareBystart(Interval a1, Interval a2)// This is the new knowkledge I never used.
    {
        return (a1.start<a2.start);
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return intervals;
        sort(intervals.begin(),intervals.end(),compareBystart);
        vector<Interval> res;
        Interval temp=intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start<=temp.end)
            {
                temp.end=max(temp.end,intervals[i].end);
            }
            else
            {
                temp.end=max(temp.end,intervals[i-1].end);
                res.push_back(temp);
                temp=intervals[i];
            }
        }
        temp.end=max(temp.end,intervals[intervals.size()-1].end);
        res.push_back(temp);
        
        return res;
    }
};
