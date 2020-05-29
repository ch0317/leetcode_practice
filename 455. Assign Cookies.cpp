class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int ans = 0;
        int j = 0;
        for(int a : g){
            for(int i = j; i < s.size(); i++)
            {
                if (s[i] >= a)
                {
                    ans++;
                    j = i + 1; 
                    break;
                }
            }
        }
        
        return ans;
    }
};