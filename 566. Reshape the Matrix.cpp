class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() == 0) return nums;
        int m = nums.size();
        int n = nums[0].size();
        list <int> q;
        if(m*n != r*c)
            return nums;
        
        vector<vector<int>> ans(r, vector<int>(c));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                q.push_back(nums[i][j]);
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                ans[i][j] = q.front();
                q.pop_front();
            }
        
        return ans;
    }
};