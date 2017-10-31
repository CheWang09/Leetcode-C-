class Solution {
public:
    int uniquePaths(int m, int n) {
       /*if(m==0||n==0) return 0;
       int k=m+n-2;
       int res1=1;
       int res2=1;
       for(int i=1;i<=m-1;i++)
       {
           res1*=k;
           res2*=i;
           k--;
       }
      int res=res1/res2;
      return res;*/
        int N = n + m - 2;// how much steps we need to do
            int k = m - 1; // number of steps that need to go down
            double res = 1;
            // here we calculate the total possible path number 
            // Combination(N, k) = n! / (k!(n - k)!)
            // reduce the numerator and denominator and get
            // C = ( (n - k + 1) * (n - k + 2) * ... * n ) / k!
            for (int i = 1; i <= k; i++)
                res = res * (N - k + i) / i;
            return (int)res;
    }
};
