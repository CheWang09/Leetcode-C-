//This is a tricky solution
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return 0;
        int n=matrix.size();
        vector<int> rematrix;
        //rematrix.push_back(0);
        
        for(int i=0;i<n;i++)
        {
            rematrix.insert(rematrix.end(),matrix[i].begin(),matrix[i].end());
        }

        sort(rematrix.begin(),rematrix.end());
        
        return rematrix[k-1];
        
    }
};

//This solution is solved by binary search algorithm

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return 0;
        int n=matrix.size();
        

        int left=matrix[0][0], right=matrix[n-1][n-1], mid;
        while(left<right){
            mid=(left+right)/2;
            int count=0, j=n-1;
            for(int i=0;i<n;i++){
                while(j>=0&&matrix[i][j]>mid)
                    j--;
                count+=j+1;
            }
            if(count<k)
                left=mid+1;
            else
                right=mid;
        }
        return left;    
    }
};
