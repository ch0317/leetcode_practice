class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        if (!s.length())
            return 0;
        
        for(int i = s.length() - 1,j = 0; i >= 0; i--,j++){
            ans += (s[i] - 'A' + 1) * pow(26,j);
        }
        
        return ans;
    }
};