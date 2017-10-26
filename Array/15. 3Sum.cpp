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
};*/
