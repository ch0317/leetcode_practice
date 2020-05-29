class Solution {
public:
    bool judgeCircle(string moves) {
        int cx{0};
        int cy{0};
        
        map<char, int> mx{{'U', 1},{'D', -1}};
        map<char, int> my{{'R', 1},{'L', -1}};
        
        for(const char a : moves){
            cx += mx[a];
            cy += my[a];
        }
        
        if(cx == 0 && cy == 0)
            return true;
        else
            return false;
    }
};