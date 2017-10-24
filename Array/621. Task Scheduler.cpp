class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        map<char,int> temp;
        for(int i=0;i<tasks.size();i++)
        {
            temp[tasks[i]]++;
        }
        priority_queue<int> Masterq;
        for(auto ite:temp)
        {
            Masterq.push(ite.second);
        }
        int cycle=n+1; int catimes=0;
        while(!Masterq.empty())
        {
            vector<int> tmp;
            int time=0;
            for(int i=0;i<cycle;i++)
            {
                if(!Masterq.empty())
                {
                    tmp.push_back(Masterq.top());
                    Masterq.pop();
                    time++;
                }
            }
            for(auto iter:tmp)
            {
                int reminder=iter-1;
                if(reminder>0)
                    Masterq.push(reminder);
            }
            if(Masterq.empty()) 
            {
                catimes+=time;
                break;
            }
            else
                catimes+=cycle;   
        }
        return catimes;
    }
};