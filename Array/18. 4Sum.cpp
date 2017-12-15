//Similar with 3sum problem, we can divide the 4sum to 3 sum problem and divide 3sum to 2 sum problem. 
// and the time complexity of 4Sum problem is O(n^3)
// Actually, in general ,for kSum problem , the time complexity is O(n^k-1)


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        vector<int> ans;
        sort(nums.begin(),nums.end());       
        for(int i=0;i<nums.size()-3;++i)
        {
            if(i!=0&&nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
            threeSumhelper(nums,i+1,target,res,ans);
            ans.pop_back();
        }
        return res;
    }
    
    void threeSumhelper(vector<int>&nums,int cur,int target,vector<vector<int>>& res,vector<int>& ans)
    {
        for(int i=cur;i<nums.size()-2;++i)
        {
            if(i!=cur&&nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
            twoSumhelper(nums,i+1,target,res,ans);
            ans.pop_back();
        }
    }
    void twoSumhelper(vector<int>&nums,int cur,int target,vector<vector<int>>& res,vector<int>& ans)
    {
        int left=cur;
        int right=nums.size()-1;
        
        while(left<right)
        {
            int sum=ans[0]+ans[1]+nums[left]+nums[right];
            if(sum==target)
            {
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                res.push_back(ans);
                ans.pop_back();
                ans.pop_back();
                while(left<right&&nums[left]==nums[left+1])
                    ++left;
                while(left<right&&nums[right]==nums[right-1])
                    --right;
                ++left;
                --right;
            }
            else if(sum<target)
                ++left;
            else
                --right;
        }
    }
};
