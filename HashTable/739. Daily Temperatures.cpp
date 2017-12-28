//This solution is time exceeded . And I have to optimize it .
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.empty()) return {};
        
        vector<int> res(temperatures.size(),0);
        
        vector<int> temp;
        vector<int> index;
        temp.push_back(temperatures[temperatures.size()-1]);
        index.push_back(temperatures.size()-1);
        
        res[temperatures.size()-1]=0;
        
        for(int i=temperatures.size()-2;i>=0;i--)
        {
            int j = temp.size()-1;
            while(j>=0)
            {
                if(temperatures[i]>=temp[j])
                {
                    temp.pop_back();
                    index.pop_back();
                    temp.push_back(temperatures[i]);
                    index.push_back(i);
                }
                if(temperatures[i]<temp[j])
                {
                    res[i]=index[j]-i;
                    temp.push_back(temperatures[i]);
                    index.push_back(i);
                    break;
                }
                --j;
            }
        }
        return res;
        
    }
};
