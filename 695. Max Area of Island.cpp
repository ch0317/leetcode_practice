class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int row_num = grid.size();
        int col_num = grid[0].size();
        vector<vector<int>> seen(row_num, vector<int>(col_num, 0));
        for(int i = 0; i < row_num; i++)
            for(int j = 0; j < col_num; j++){
                max_area = max(max_area, area(i, j, row_num, col_num, grid, seen));
            }
        
        return max_area;
    }
    
    int area(int row, int column, int row_num, int col_num, vector<vector<int>> &grid, vector<vector<int>> &seen){
        if(row < 0 || row > row_num - 1 || 
           column < 0 || column > col_num - 1 || 
           grid[row][column] == 0 || seen[row][column] == 1)
            return 0;
        
        seen[row][column] = 1;
        
        return 1 + area(row - 1, column,row_num, col_num, grid, seen) + area(row + 1, column,row_num, col_num, grid, seen) + area(row, column - 1,row_num, col_num, grid, seen) + area(row, column + 1,row_num, col_num, grid, seen);
    }
};