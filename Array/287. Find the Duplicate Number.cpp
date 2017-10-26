class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=nums[i+1])
                continue;
            result=nums[i];
        }
        return result;
    }
};
