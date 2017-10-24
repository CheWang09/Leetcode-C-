class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        int i=1;
        while(i<nums.size())
        {
            if(nums[i]==nums[i-1])
            {
                res.push_back(nums[i]);
            }
            i++;
        }
        return res;
    }
};