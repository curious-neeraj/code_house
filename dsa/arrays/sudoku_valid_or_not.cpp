// Time Complexity - O(n^2)
// Space Complexity - O(1)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool row[10][10] = {false}, col[10][10] = {false}, grid[10][10] = {false};

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    int val = board[i][j] - '0';

                    // Good way to calculate the box number
                    int box = i/3 * 3 + j/3;
                    
                    if(row[i][val] || col[j][val] || grid[box][val])
                        return false;
                    
                    row[i][val] = col[j][val] = grid[box][val] = true;
                }
            }
        }

        return true;
    }
};
