//This is a DP problem

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.empty()||B.empty()) return 0;
        int x=A.size();
        int y=B.size();
        vector<vector<int>> ResMatrix(x,vector<int>(y));
        int max=0;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(A[i]==B[j])
                {
                    if(i==0||j==0)
                    {
                        ResMatrix[i][j]=1;
                    }
                    else
                    {
                        ResMatrix[i][j]=ResMatrix[i-1][j-1]+1;
                        if(ResMatrix[i][j]>max)
                        {
                            max=ResMatrix[i][j];
                        }
                    }
                }
                else
                    ResMatrix[i][j]=0;    
            }
        }
        return max;
    }
};
