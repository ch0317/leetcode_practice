class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if(data.size() == 0) return false;
        int left = 0;
        for(int a : data){
            if(left == 0){
                if(a >> 3 == 0b11110) left = 3;
                else if(a >> 4 == 0b1110) left = 2;
                else if(a >> 5 == 0b110) left = 1;
                else if(a >> 7 == 0) left = 0;
                else return false;
            }else{
                if(a >> 6 != 0b10) {
                    return false;
                }
                left--;
            }
        }
        
        return left == false;
    }
};