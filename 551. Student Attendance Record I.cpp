class Solution {
public:
    bool checkRecord(string s) {
        int l{0};
        int a{0};

        for(char c : s){
            if(c == 'A') a++;
            if(c == 'L') l++;
            else l = 0;
            if(a > 1 || l > 2)
                return false;
        }

        return true;
    }
};