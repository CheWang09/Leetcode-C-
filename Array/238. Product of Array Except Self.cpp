class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return nums;
        int product=1;
        vector<int> mark;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0){
                mark.push_back(i);
                continue;
            }
            product*=nums[i];
        }
        //get the product of all the elements in the array except zero
        if(mark.size()==1)
        {
            nums[mark[0]]=product;
            for(int i=0;i<nums.size();i++)
            {
                if(i==mark[0]) continue;
                nums[i]=0;
            }
            return nums;
        }
        if(mark.size()>=2)
        {
            for(int i=0;i<nums.size();i++)
            {
                nums[i]=0;
            }
            return nums;
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=product/nums[i];
        }
        //the result of the array is the product divided by nums[i]
        return nums;
    }
};
