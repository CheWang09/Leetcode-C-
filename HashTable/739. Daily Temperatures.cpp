//Use array 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.empty()) return {};
        vector<int> res(temperatures.size(),0); 
        vector<pair<int,int>> VI;//value, index 
        for(int i = 0; i < temperatures.size(); ++i){
            while(!VI.empty()){
                auto temp = VI[VI.size()-1];
                if(temp.first < temperatures[i]){
                    res[temp.second] = i - temp.second;
                    VI.pop_back();
                }else{
                    break;
                }
            }
            VI.push_back({temperatures[i], i});
        }
        return res;
    }
};


//This solution is from first to last, and use stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.empty()) return {};
        vector<int> res(temperatures.size(),0); 
        stack<pair<int,int>> sk;//value, index 
        for(int i = 0; i < temperatures.size(); ++i){
            while(!sk.empty()){
                auto temp = sk.top();
                if(temp.first < temperatures[i]){
                    res[temp.second] = i - temp.second;
                    sk.pop();
                }else{
                    break;
                }
            }
            sk.push({temperatures[i], i});
        }
        return res;
    }
};


//This solution is time exceeded ,not efficient. This solution is from last to first
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.empty()) return {};
        
        vector<int> res(temperatures.size(),0);
        vector<int> index;
        index.push_back(temperatures.size()-1);
        res[temperatures.size()-1]=0;     
        for(int i=temperatures.size()-2;i>=0;i--)
        {
            int j = index.size()-1;
            while(j>=0)
            {
                if(temperatures[i]>=temperatures[index[j]])
                {
                    index.pop_back();
                    index.push_back(i);
                }
                if(temperatures[i]<temperatures[index[j]])
                {
                    res[i]=index[j]-i;
                    index.push_back(i);
                    break;
                }
                --j;
            }
        }
        return res;  
    }
};
