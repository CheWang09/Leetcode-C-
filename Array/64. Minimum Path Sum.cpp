class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int rows=grid.size();int cols=grid[0].size();
        vector<vector<int>> data (rows,vector<int>(cols,grid[0][0]));
        for(int i=1;i<rows;i++)
        {
            data[i][0]=data[i-1][0]+grid[i][0];
        }
        for(int j=1;j<cols;j++)
        {
            data[0][j]=data[0][j-1]+grid[0][j];
        }
        for(int r=1;r<rows;r++)
        {
            for(int c=1;c<cols;c++)
            {
                data[r][c]=min(data[r-1][c],data[r][c-1])+grid[r][c];
            }
        }
        return data[rows-1][cols-1];
    }
};