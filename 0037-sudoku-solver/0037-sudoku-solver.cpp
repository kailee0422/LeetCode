class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y, char num) {
        //row check
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == num) {
                return false;
            }
        }
        //column check
        for (int j = 0; j < 9; j++) {
            if (board[j][y] == num) {
                return false;
            }
        }
        //grid check
        int startX = (x / 3) * 3;
        int startY = (y / 3) * 3;

        for (int i = startX; i < startX + 3; i++) {
            for (int j = startY; j < startY + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;  
    }
	bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (isValid(board, i, j, k)) {
                            board[i][j] = k;
                            if (solve(board))
                            {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
	}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};