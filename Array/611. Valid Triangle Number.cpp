class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        if(nums.size()==3)
            return (nums[0]+nums[1]>nums[2]);
        int i=2;int result=0;
        for(i;i<nums.size();i++)
        {
            int left=0;int right=i-1;
            while(left<right)
            {
                if((nums[left]+nums[right])>nums[i])
                  {
                    result+=(right-left);
                    right--;
                }
                else
                    left++;    
            }
        }
        
        return result;                                                                     
    }
};