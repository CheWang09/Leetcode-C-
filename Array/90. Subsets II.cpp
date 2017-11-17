class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<vector<int>> res;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int pos=0;
        subsetsII(nums,res,ans,pos);
        return res;
    }
    
private:
    void subsetsII(vector<int> &nums,vector<vector<int>> &res, vector<int> &ans,int pos)
    {
        res.push_back(ans);
        for(int i=pos;i<nums.size();i++)
        {
            ans.push_back(nums[i]);
            subsetsII(nums,res,ans,i+1);
            ans.pop_back();
            while(i+1<nums.size()&&nums[i]==nums[i+1]) i++;
        }
    }
};
