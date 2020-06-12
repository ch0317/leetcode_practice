class Solution {
public:
    int mySqrt(int x) {
        double delta = 0.001;
        double ans = x;
        while(fabs(pow(ans, 2)) - x > delta){
            ans = (ans + x / ans) / 2;
        }
        
        return ans;
    }

};