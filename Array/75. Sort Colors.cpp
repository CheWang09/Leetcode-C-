class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        int left=0;
        int right=nums.size()-1;
        int mid=left;
        //int i=0;
        while(mid<=right)
        {
            if(nums[mid]==2)
            {
                swap(nums[mid],nums[right]);
                right--;
                continue;
            }
            else if(nums[mid]==0)
            {
                swap(nums[left],nums[mid]);
                left++;
                mid++;
            }
            else
            {
                mid++;
            }
        }
        
    }
};
