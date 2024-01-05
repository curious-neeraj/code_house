class Solution {
private:
    bool row[9][9] = {false}, col[9][9] = {false}, grid[9][9] = {false};

    // Check if current state is valid
    bool isValid(vector<vector<char>>& board, int x, int y, char c)
    {
        int val = c - '0' - 1;
        int box = x/3 * 3 + y/3;

        if(row[x][val] || col[y][val] || grid[box][val])
            return false;
        
        return true;
    }

    // Fill, check and backtrack
    bool solve(vector<vector<char>>& board, int x, int y)
    {
        if(x == 9) 
            return true;
        
        if(y == 9) 
            return solve(board, x+1, 0);
        
        if(board[x][y] != '.') 
            return solve(board, x, y+1);

        for(char c = '1'; c <= '9'; c++)
        {
            if(isValid(board, x, y, c))
            {
                int val = c - '0' - 1

                // Set Value
                row[x][val] = col[y][val] = grid[x/3 * 3 + y/3][val] = true;
                board[x][y] = c;
                
                if(solve(board, x, y+1)) 
                    return true;

                // Backtrack Value
                board[x][y] = '.';
                row[x][val] = col[y][val] = grid[x/3 * 3 + y/3][val] = false;
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        // Set starting state
        int len = board.size();
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<len; j++)
            {
                if(board[i][j] != '.')
                {
                    int val = board[i][j] - '0' - 1;
                    row[i][val] = col[j][val] = grid[i/3 * 3 + j/3][val] = true;
                }
            }
        }
        
        solve(board, 0, 0);
    }
};
