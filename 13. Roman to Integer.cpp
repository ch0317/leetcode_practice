class Solution {
public:
    int romanToInt(string s) {
        map<char,int> val_dic = {{'I', 1},{'V', 5},{'X',10},{'L',50},
                         {'C', 100},{'D',500},{'M',1000}};
        
        int ans = 0;
        int p = 0;
        
        for(char a : s){
            ans += val_dic[a];
            if(p && val_dic[a] > val_dic[p]){
                ans -= 2 * val_dic[p];
            }
            p = a;
        }
        return ans;
    }
    
};