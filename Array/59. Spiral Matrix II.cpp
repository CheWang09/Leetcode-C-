class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       // if(n==0) return NULL;
        vector<vector<int>> matrix(n,vector<int>(n));
        int num=1;int i=0;int Cur=0;
        while(num<=n*n)
        {
            i=Cur;
            int j=i;
            while(j<n-Cur)
                matrix[i][j++]=num++;
            i++;
            j--;
            while(i<n-Cur)
                matrix[i++][j]=num++;
            i--;
            j--;
            while (j >= Cur)
		    {
                matrix[i][j] = num;
                //cout << num << endl;
                num++;
                //cout << i << "\t" << j << endl;
                //cout << matrix[i][j] << endl;
                j--;
		    }
            j++;
            i--;
            while(i>Cur)
                matrix[i--][j]=num++;
            i++;
            Cur++;
        }
        return matrix;
    }
};
