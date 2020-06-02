class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;   
        int count = 0;
        int ans = 0;
        unordered_map<int,int> tbl;
        
        while(i < s.length()){
            if(tbl.count(s[i]) == 0){
                tbl[s[i]]++;
                i++;
                ans = ans < tbl.size() ? tbl.size() : ans;
            }
            else
            {
                tbl.erase(tbl.find(s[j]));
                j++;
            }
        }
        
        return ans;
    }
};
