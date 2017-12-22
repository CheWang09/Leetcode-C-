//My first soulution is to sort the array first, and then calculate the number of the same elements in the array. If the number is larger
//than times. I will put it into the result array.
//And time complexity is O(nlogn) which is the time complexity of sort function.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty()) return {};
        
        int times=nums.size()/3;
        if(nums.size()==1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> result;
        int mark=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                ++mark;
                if(i==nums.size()-1)
                {
                    if(mark>times)
                         result.push_back(nums[i]);
                }
            }
            else
            {
                if(mark>times)
                   result.push_back(nums[i-1]);
                mark=1;
                if(i==nums.size()-1)
                {
                    if(mark>times)
                        result.push_back(nums[i]);
                }
                    
            }
        }
        return result;
        
    }
};
