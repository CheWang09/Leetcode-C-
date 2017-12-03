class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<string> res;
        vector<int> start;
        start.push_back(nums[0]);
        vector<int> end;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]!=1)
            {
                end.push_back(nums[i-1]);
                start.push_back(nums[i]);
            }
        }
        end.push_back(nums[nums.size()-1]);
        
        for(int i=0;i<start.size();i++)
        {
            if(start[i]==end[i])
            {
                res.push_back(to_string(start[i]));
            }
            else
            {
                string temp=to_string(start[i])+"->"+to_string(end[i]);
                res.push_back(temp);
            }
        }
        
        return res;
    }
};
