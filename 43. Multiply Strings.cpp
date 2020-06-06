class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        
        vector<int> vec(len1 + len2, 0);
        
        for(int i = len1 - 1; i >= 0; --i)
            for(int j = len2 - 1; j >= 0; --j){
                int multi = (num1[i] - '0') * (num2[j] - '0');
                int sum = vec[i + j + 1] + multi;
                vec[i + j + 1] = sum % 10;
                vec[i + j] += sum / 10;
            }
        
        string res = "";
        for(int i = 0; i < vec.size(); i++){
            if(!res.empty() || vec[i] != 0){
                res.append(1,'0' + vec[i]);
            }
        }
        
        return res.empty() ? "0": res;
    }
};