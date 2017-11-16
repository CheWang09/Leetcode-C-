class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        vector<int> Row;
        vector<int> Column;
        // use two vector to store the zero elements location
        int m,n;
        m=matrix.size();
        n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    Row.push_back(i);
                    Column.push_back(j);
                }
            }
        }
        //unordered_map<int,int>::iterator it;
        for(int it=0;it<Row.size();it++)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][Column[it]]=0;
            }
            for(int j=0;j<n;j++)
            {
                matrix[Row[it]][j]=0;
            }
        }
    }
};
