class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        //vector<vector<int>> res;
        result.push_back({});
        sort(nums.begin(),nums.end());
        vector<int> OneAns;
        int count=0;
        int cur=0;
        for(int i=1;i<=nums.size();i++)
        {
            subsetCombo(nums,i,cur,OneAns,result);
        }
        /*for(int j=0;j<result.size();j++)
        {
            if(result[j][0]==0)
                continue;
            /*if(*result[j].end()==0)
                continue;
            res.push_back(result[j]);
        }*/
        return result;
    }
    void subsetCombo(vector<int>& nums,int count,int cur,vector<int> &OneAns,vector<vector<int>> &res)
    {
        if(count==0)
        {
            res.push_back(OneAns);
            return;
        }
        for(int i=cur;i<nums.size();i++)
        {
            OneAns.push_back(nums[i]);
            subsetCombo(nums,count-1,i+1,OneAns,res);
            OneAns.pop_back();
        }     
    }
    
};
