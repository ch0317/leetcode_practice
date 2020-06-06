class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        if(numRows == 0) return ans;
        ans.push_back(vector<int> (1,1));
        if(numRows == 1) return ans;
        vector<int> last_row(2,1);
        ans.push_back(last_row);
        if(numRows == 2) return ans;
        
        for(int i = 3; i <= numRows; i++){
            vector<int> Row(i, 1);
            
            for(int j = 1; j < i - 1; j++)
            {
                Row[j] = last_row[j - 1] + last_row[j];
            }
            
            last_row.clear();
            ans.push_back(Row);
            last_row.assign(Row.begin(),Row.end());
        }
        
        return ans;
    }
};