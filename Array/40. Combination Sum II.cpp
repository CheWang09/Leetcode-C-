class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty()) return {{}};
        sort(candidates.begin(),candidates.end());
        vector<int> ans;
        vector<vector<int>> res;
        helper(candidates,ans,res,target,0);
        return res;
    }
    
    void helper(vector<int>& candidates,vector<int> &ans, vector<vector<int>>& res, int target,int curpos)
    {
        if(target==0)
        {
             res.push_back(ans);
             return;
        }
        
        for(int i=curpos;i<candidates.size() && candidates[i]<=target; i++)
        {
            //This sentence of the most important part to achieve this algorithm.
            // Which is different from the Combination Sum I
            if(i != curpos && candidates[i] == candidates[i-1]) continue;
            ans.push_back(candidates[i]);
            helper(candidates,ans,res,target-candidates[i],i+1);
            ans.pop_back();
        }
    }
};























//This solution is time limit exceeded
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty()) return {{}};
        sort(candidates.begin(),candidates.end());
        vector<int> ans;
        vector<vector<int>> res;
        helper(candidates,ans,res,target,0);
        sort(res.begin(),res.end());
        for(int i=1;i<res.size();i++)
        {
            if(res[i-1]==res[i])
            {
                res.erase(res.begin()+i);
                i--;
            }
        }
            
        return res;
    }
    

private:
    void helper(vector<int>& candidates,vector<int> &ans, vector<vector<int>>& res, int target,int curpos)
    {
        if(target==0)
        {
             res.push_back(ans);
             return;
        }
        
        for(int i=curpos;i<candidates.size();i++)
        {
            ans.push_back(candidates[i]);
            helper(candidates,ans,res,target-candidates[i],++curpos);
            ans.pop_back();
        }
    }
};
