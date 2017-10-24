class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int i=0;int j=0;int sum=0;
        int result=0;
        for(i;i<nums.size();i++)
        {
            sum=nums[i];
            if(sum==k){
                result++;
            }
            for(j=i+1;j<nums.size();j++)
            {
                sum+=nums[j];
                if(sum==k)
                {
                    result++;
                }
            }
        }
        return result;      
    }
};