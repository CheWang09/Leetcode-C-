class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows=matrix.size();
        if(rows==0)
            return result;
        int cols=matrix[0].size();
        int r=0;int c=0;int bounds=0;
        int i=0;
        while(i<rows*cols)
        {
            if(bounds%4==0)
            {
                while(c<(cols-(bounds/4)))
                {
                    result.push_back(matrix[r][c]);
                    c++;
                    i++;
                }
                c--;
                r++;
            }
            else if(bounds%4==1)
            {
                while(r<(rows-(bounds/4)))
                {
                    result.push_back(matrix[r][c]);
                    i++;
                    r++;
                }
                r--;
                c--;
            }
            else if(bounds%4==2)
            {
                while(c>=(bounds/4))
                {
                    result.push_back(matrix[r][c]);
                    i++;
                    c--;
                }
                c++;
                r--;
            }
            else
            {
                while(r>=((bounds/4)+1))
                {
                    result.push_back(matrix[r][c]);
                    i++;
                    r--;
                }
                r++;
                c++;
            }
            bounds++;    
      }
     return result;
    }
};