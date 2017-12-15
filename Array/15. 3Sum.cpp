class Solution {
public: 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        for(int i=0;i<nums.size()-2;++i)
        {
            if(i!=0&&nums[i]==nums[i-1])
                continue;
            ans.push_back(nums[i]);
            helper(nums,i+1,nums[i],res,ans);
            ans.pop_back();
        }
        return res;
    }  
    void helper(vector<int>& nums,int cur,int target,vector<vector<int>>& res,vector<int>& ans)
    {
        int left=cur;
        int right=nums.size()-1;
        
        while(left<right)
        {
            int sum=nums[left]+nums[right];
            
            if(sum+target==0)
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
            else if(sum+target<0)
                ++left;
            else
                --right;
        }
        
    }
};



/*
###
### some problem in this solution with the input[-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6] 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //if(nums.empty()) return NULL;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<vector<int>> result;
        int cur=0;
        vector<int> ans;
        combination(nums,ans,3,cur,0,res);
        for(int i=0;i<res.size();i++)
        {
            if(res[i]!=res[i+1])
                result.push_back(res[i]);
        }
        return result;
    }
    void  combination(vector<int> &nums,vector<int> &ans,int count,int cur,int sum,vector<vector<int>> &res)
    {
        if(count==0&&sum==0)
        {
            res.push_back(ans);
            return;
        }
        for(int i=cur;i<nums.size();i++)
        {
            ans.push_back(nums[i]);
            combination(nums,ans,count-1,i+1,sum-nums[i],res);
            ans.pop_back();
        }
        return;
    }
};

//recuresive solution that exceed time complexity/
class Solution {
public: 
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty()) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        helper(nums,0,3,0,res,ans);
        return res;
    }  
    void helper(vector<int>& nums,int cur,int count,int target,vector<vector<int>>& res,vector<int>& ans)
    {
        if(count==0&&target==0)
        {
            res.push_back(ans);
            return;
        }
        for(int i=cur;i<nums.size();i++)
        {
            if(i!=cur&&nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
            helper(nums,i+1,count-1,target-nums[i],res,ans);
            ans.pop_back();
        }
    }
};
*/
