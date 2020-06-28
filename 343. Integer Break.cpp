class Solution {
public:
    int integerBreak(int n) {
        if(n <= 2) return 1;
        vector<int> maxarray(n+1,0);
        maxarray[1] = 0;
        maxarray[2] = 1;
        int res = 0;
        
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i; j++){
                maxarray[i] = max(maxarray[i], max(j * (i - j), j * maxarray[i - j]));
                res = max(res, maxarray[i]);
            }
        }
        
        return res;
    }
};