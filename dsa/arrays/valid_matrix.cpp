// Time Complexity - O(n^2)
// Space Complexity - O(1)

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        int len = matrix.size();
        bool row[101][101] = {false}, col[101][101] = {false};

        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                int val = matrix[i][j] - 1;
                if(row[i][val] || col[j][val])
                    return false;
                
                row[i][val] = col [j][val] = true;
            }
        }

        return true;
    }
};
