class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        
        for(int a : nums){
            if(s.count(a) == 0) continue;
            s.erase(a);
            int pre = a - 1, next = a + 1;
            while(s.count(pre)) s.erase(pre--);
            while(s.count(next)) s.erase(next++);
            
            res = max(res, next - pre - 1);
        }
        
        return res;
    }
};