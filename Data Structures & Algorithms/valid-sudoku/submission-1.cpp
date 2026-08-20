class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    
        vector<set<char>> row(9);
        vector<set<char>> col(9);
        vector<set<char>> grid(9);

        for(int i=0;i<9;i++) {
            for (int j=0; j<9; j++) {
                char ch = board[i][j];
                if(ch == '.') {
                    continue;
                }
                int gridIndex = ((i/3) *3) + (j/3);
                if(row[i].find(ch) != row[i].end() || col[j].find(ch) !=col[j].end() || grid[gridIndex].find(ch) != grid[gridIndex].end()) {
                    return false;
                }
                row[i].insert(ch);
                col[j].insert(ch);
                grid[gridIndex].insert(ch);
            }
        }
        return true;
    }
};
