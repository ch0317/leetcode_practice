class Solution {
private:
    void subset_generate(vector<int>&nums, vector<vector<int>> &ans, vector<int> &current, int index){
        ans.push_back(current);
        for(int i = index; i < nums.size(); i++){
            current.push_back(nums[i]);
            subset_generate(nums, ans, current, i+1);
            current.pop_back();
        }
    }
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        subset_generate(nums, ans, cur, 0);
        
        return ans;
    }
};