class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++){
                if(i == 0) dp[i][j] = triangle[i][j];
                else{
                    if(j == 0){
                        dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    }
                    else if(j == i){
                        dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                    }else{
                        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                    }
                }
                
                cout << i << " " << j << " " << dp[i][j] <<endl;
            }
        
        return *min_element(dp[n - 1].cbegin(), dp[n - 1].cend());
    }
};