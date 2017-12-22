//I used backtrack method to solve this problem. And the program has two loops that start from each element of the matrix to check whether
//their neighboring are same with the next element in string word.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(backtrack(board,word,i,j,0))
                    return true;
            }
        }
        return false;
       
    }
    
private:
    bool backtrack(vector<vector<char>>& board,string& word,int i, int j, int pos)
    {
        int height=board.size();
        int width=board[0].size();
        
        if(i<0||j<0||i>=height||j>=width||board[i][j]=='\0'||board[i][j]!=word[pos])
            return false;
        if(pos==word.size()-1)
            return true;
        
        char temp=board[i][j];
        board[i][j]='\0';
        if(backtrack(board,word,i,j+1,pos+1)||backtrack(board,word,i+1,j,pos+1)||backtrack(board,word,i-1,j,pos+1)||backtrack(board,word,i,j-1,pos+1))
            return true;
        board[i][j]=temp;
        return false;
    }
};
