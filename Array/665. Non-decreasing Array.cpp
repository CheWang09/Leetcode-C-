class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i=0,j=1;
        int numbers=0;
        for(j;j<nums.size();j++)
        {
            if(nums[i]>nums[j])
            {
                ++numbers;
                if(j==nums.size()-1)
                    nums[j]=nums[i];
                else if(nums[j+1]<nums[j-1])
                    nums[i]=nums[j];
                else
                    nums[j]=nums[i];
            }
            ++i;
        }
        if(numbers>1) return false;
        int m=0;
        for(int n=1;n<nums.size();n++)
        {
            if(nums[n]<nums[m])
            {
                return false;
            }
            m++;
        }
        return true;
    }
};