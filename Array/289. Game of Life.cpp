class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int height=board.size();
        int width=board[0].size();
        
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                int status=getStatus(board,i,j);
                if(board[i][j]==1)
                {
                    if(status==2||status==3)
                        board[i][j]=1;
                    else
                        board[i][j]=3;
                }
                else
                {
                    if(status==3)
                        board[i][j]=2; 
                } 
            }
        }
        
        for(int i = 0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                board[i][j] >>=1;
            }
        }
    }
    int getStatus(vector<vector<int>>& board,int m,int n)
    {
        int live=0;
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(i==0&&j==0)
                    continue;
                int x=m+i;
                int y=n+j;
                if(x<0||y<0||x>=board.size()||y>=board[0].size())
                    continue;
                if(board[x][y]&1)
                    ++live;
                if(board[x][y]==2)
                    --live;
            }
        }
        return live;
    }
};
