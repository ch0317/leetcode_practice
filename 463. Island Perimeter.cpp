class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row_num = grid.size();
        int col_num = grid[0].size();
        int area = 0;
        int conn = 0;

        for(int i = 0; i < row_num; i++){
            for(int j = 0; j < col_num; j++){
                if(grid[i][j]) {
                    area++;
                    if(i > 0 && grid[i - 1][j]) conn++;
                    if(i < row_num - 1 && grid[i + 1][j]) conn++;
                    if(j > 0 && grid[i][j - 1]) conn++;
                    if(j < col_num - 1 && grid[i][j + 1]) conn++;
                }
            }
        }

        return area * 4 - conn;
    }
};