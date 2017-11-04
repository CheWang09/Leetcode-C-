class Solution {
public:
    int maximumSwap(int num) {
        if(num==0) return 0;
        
        //store every digit into a int type vector numebr
        vector<int> number;
        int nums=num;
        while(nums>=10)
        {
            int temp=nums%10;
            number.push_back(temp);
            //sortnum.push_back(temp);
            nums=nums/10;
        }
        number.push_back(nums);
    
        //swap numbers in vector
        
        vector<int> sortnum;
        sortnum=number;
        sort(sortnum.begin(),sortnum.end());
        reverse(sortnum.begin(),sortnum.end());
        reverse(number.begin(),number.end());
        if(sortnum==number)
        {
            int res=0;
            for(int i=0;i<number.size()-1;i++)
            {
                res=(res+number[i])*10;
            }
            res+=number[number.size()-1];
            return res;
        }
        int index1,ErNum;
        vector<int> index;
        for(int i=0;i<number.size();i++)
        {
            if(number[i]!=sortnum[i])
            {
                index1=i;
                ErNum=sortnum[i];
                break;
            }
        }
        for(int j=index1;j<number.size();j++)
        {
            if(number[j]==ErNum)
            {
                index.push_back(j);
            }
        }
        swap(number[index1],number[index[index.size()-1]]);
        
        
        //return back to int type
        int res=0;
        for(int i=0;i<number.size()-1;i++)
        {
            res=(res+number[i])*10;
        }
        res+=number[number.size()-1];
        return res;
    }
};
