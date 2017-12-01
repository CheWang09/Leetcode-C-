class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return {candidates};
        sort(candidates.begin(),candidates.end());
        vector<int> ans;
        vector<vector<int>> res;
        helper(candidates, res,ans,target,0);
        //if(res.empty()) return {};
        return res;
        
    }
    void helper(vector<int>& candidates,vector<vector<int>> &res,vector<int> &ans, int target, int cur)
    {
        if(target==0) res.push_back(ans);
        
        for(int i=cur;i<candidates.size()&&candidates[i]<=target;i++)
        {
            ans.push_back(candidates[i]);
            helper(candidates,res,ans,target-candidates[i],i);
            ans.pop_back();
        }
    }
};
