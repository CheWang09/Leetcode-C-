//This is a Dynamic Programming Problem combined with Array.


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        vector<vector<int>> MinP=triangle;
        MinP[triangle.size()-1]=triangle[triangle.size()-1];
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                MinP[i][j]=min(MinP[i+1][j],MinP[i+1][j+1])+MinP[i][j];
            }
        }
        return MinP[0][0];
    }
};
