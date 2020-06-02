class Solution {
public:
    bool isAnagram(string s, string t) {
        int tableS[26] = {};
        int tableT[26] = {};
        for(char a :s){
            tableS[a - 'a'] ++;
        }
        
        for(char a : t){
            tableT[a - 'a']++;
        }
        
        
        for(int i = 0; i < 26; i++)
        {
            if(tableS[i] != tableT[i])
                return false;
        }
        
        return true;
    }
};