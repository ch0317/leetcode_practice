class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<int> rec_set;
        DFS(nums, ans, temp, rec_set);
        return ans;
    }
    
    void DFS(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, set<int> &rec_set){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(rec_set.find(nums[i]) == rec_set.end()){
                cout << nums[i];
                temp.push_back(nums[i]);
                rec_set.insert(nums[i]);
            }
            else
            {
                continue;
            }
            
            DFS(nums, ans, temp, rec_set);
            temp.pop_back();
            rec_set.erase(rec_set.find(nums[i]));
            
        }
    }
};