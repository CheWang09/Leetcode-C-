//better brute force solution with time complexity O(n square)
if(nums.empty()) return 0;                
        int res=nums.size()+1;
        int len=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            len=1;
            sum=nums[i];
            if(sum>=s) return 1;
            for(int j=i+1;j<nums.size();j++)
            {
                sum+=nums[j];
                len+=1;
                if(sum>=s)
                {
                    res=min(res,len);
                    break;
                }
            }
        }
        if(nums[nums.size()-1]>=s) return 1;
        if(res==nums.size()+1) return 0;
        return res;


///much more smart solution with time complexity O(n)
if(nums.empty()) return 0;
        
        int res=nums.size()+1;
        
        int start=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>=s)
            {
                res=min(res,i+1-start);
                
                sum-=nums[start++];
            }
        }
        
        return (res!=nums.size()+1)?res:0;
