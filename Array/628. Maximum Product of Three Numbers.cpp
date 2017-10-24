class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //int result=0;
        int tail=nums.size();
        int result1=nums[0]*nums[1]*nums[tail-1];     
        int result2=nums[tail-1]*nums[tail-2]*nums[tail-3];       
        return result1>result2?result1:result2;
    }
};