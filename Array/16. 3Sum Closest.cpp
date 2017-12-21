//solution using two pointer , and we need to sort the array first. 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        
        sort(nums.begin(),nums.end());
        int Min=2147483647;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int begin=i+1;
            int end=nums.size()-1;
            
            while(begin<end)
            {
                int sum=nums[i]+nums[begin]+nums[end];
                if(abs(sum-target)<=abs(Min)) Min=sum-target;
                if(sum==target) return sum;
                else if(sum>target) --end;
                else ++begin;
            }
        }
        return Min+target;
        
    }
};



//Using recursive solution, but it has a high time compleixty.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        
        int sum=nums[0]+nums[1]+nums[2];
        vector<int> res;
        vector<int> ans;
        res.push_back(sum);
        helper(nums,target,3,0,ans,res);
        return res[0];
        
    }
    
    void helper(vector<int>& nums,int target,int count,int cur,vector<int>& ans,vector<int>& res)
    {
        if(count==0)
        {
            if(abs(target-res[0])<=abs(target-ans[0]-ans[1]-ans[2]))
                res[0]=res[0];
            else
                res[0]=ans[0]+ans[1]+ans[2];
            return;
        }
        
        for(int i=cur;i<nums.size();i++)
        {
            //if(cur>0&&nums[cur]==nums[cur-1]) continue;
            ans.push_back(nums[i]);
            helper(nums,target,count-1,i+1,ans,res);
            ans.pop_back();
        }
    }
};
