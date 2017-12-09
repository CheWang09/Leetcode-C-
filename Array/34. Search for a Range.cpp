class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(nums[mid]>target) right=mid-1;
            if(nums[mid]<target) left=mid+1;
            if(nums[mid]==target) break;
        }
        if(nums[mid]!=target) return {-1,-1};
        int start=mid,end=mid;
        while(nums[start]==target&&start>=0)
        {
            if(nums[start]==target) start--;
        }
        while(nums[end]==target&&end<nums.size())
        {
            if(nums[end]==target) end++;
        }
        return {start+1,end-1};
    }
};
