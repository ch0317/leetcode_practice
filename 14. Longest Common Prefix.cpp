class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prex;
        if (strs.size() == 0)
            return prex;
        for(int j = 0; j < strs[0].size(); j++){
            char c = strs[0][j];
            for(int i = 0; i < strs.size(); i++){
                if(strs[i].size() < j + 1 || strs[i][j] != c)
                    return prex;
            }
            
            prex.append(1, c);
        }
        
        return prex;
    }
};