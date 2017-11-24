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



//Algorithm optimization 

//In the above algorithm, the space complexity is O(n^2), I think we are necessary to change our method by reducing the space complexity.
// We can use a single vector to store the min value of each rows . 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        //vector<vector<int>> MinP=triangle;
        vector<int>sum=triangle[triangle.size()-1];
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                sum[j]=min(triangle[i][j]+sum[j],triangle[i][j]+sum[j+1]);
            }
        }
        return sum[0];
    }
};
