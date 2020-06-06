class Solution {
public:
    int getSum(int a, int b) {
        if(a == 0) return 0;
        if(b == 0) return 0;
        
        while(b != 0){
            int c = (a & b) << 1;
            a = a ^ b;
            b = c;
        }
        
        return a;
    }
};