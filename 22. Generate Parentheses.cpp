class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;    
        backtrack(ans, temp, n, n);
        return ans;
    }
    
    void backtrack(vector<string> &ans, string temp, int left, int right)
    {
        if(left == 0 && right == 0)
            ans.push_back(temp);
        if(left > right)
            return;
        
        if(left > 0) backtrack(ans, temp + '(', left - 1 , right);
        if(right > 0) backtrack(ans, temp + ')', left, right - 1);
    }
};