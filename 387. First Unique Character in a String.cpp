class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char, int> hash_tbl;
        int index = 0;
        for(int i = 0; i < s.length(); i++){
            hash_tbl[s[i]]++;
        }
        
        for(int i = 0; i < s.length(); i++){
            if(hash_tbl[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};