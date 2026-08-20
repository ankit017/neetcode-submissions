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
                set<char> rowSet = row[i];
                set<char> colSet = col[j];
                set<char> gridSet = grid[gridIndex];

                if(rowSet.find(ch) != rowSet.end() || colSet.find(ch) !=colSet.end() || gridSet.find(ch) != gridSet.end()) {
                    return false;
                }
                rowSet.insert(ch);
                colSet.insert(ch);
                gridSet.insert(ch);

                row[i] = rowSet;
                col[j] = colSet;
                grid[gridIndex] = gridSet;
            }
        }
        return true;
    }
};
