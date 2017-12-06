//DP problem

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
        int rows=obstacleGrid.size();
        int cols=obstacleGrid[0].size();
        vector<vector<int>> DP(rows,vector<int>(cols));
        if(obstacleGrid[0][0]==1) return 0;
        else DP[0][0]=1;
        for(int i=1;i<cols;i++)
        {
            if(obstacleGrid[0][i]==1) DP[0][i]=0;
            else DP[0][i]=DP[0][i-1];   
        }
        for(int i=1;i<rows;i++)
        {
            if(obstacleGrid[i][0]==1) DP[i][0]=0;
            else DP[i][0]=DP[i-1][0];   
        }
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    DP[i][j]=0;
                    continue;
                }
                else
                    DP[i][j]=DP[i-1][j]+DP[i][j-1];
            }
       }
       return DP[rows-1][cols-1];
    }
};
