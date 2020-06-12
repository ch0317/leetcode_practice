class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto comp = [](vector<int> a, vector<int> b){return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];};
        sort(envelopes.begin(), envelopes.end(), comp);
        int size = envelopes.size();
        vector<int> dp(size, 1);
        
        int res = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < i; j++){
                if(envelopes[i][1] > envelopes[j][1] && envelopes[i][0] > envelopes[j][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        
        return res;
    }
};