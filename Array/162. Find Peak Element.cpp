class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> mysort(nums.size());
        mysort=nums;
        sort(mysort.begin(),mysort.end());
        int peak=mysort[nums.size()-1];
        for(int i=0;i<nums.size();i++)
        {
            if(peak==nums[i])
            {
                return i;
            }
        }
    }
};