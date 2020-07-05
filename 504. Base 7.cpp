class Solution {
public:
    string convertToBase7(int num) {
        bool is_negitive = num<0;
        num = abs(num);
        string ans;

        do{
            int n = num % 7;
            num /= 7;
            ans = to_string(n) + ans;
        }while(num != 0);

        if(is_negitive) ans = "-" + ans;
        return ans;
    }
};