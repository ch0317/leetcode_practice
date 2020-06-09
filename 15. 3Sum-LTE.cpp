class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur_vec;
        int index;
        vector<set<int>> st_vec;
        sort(nums.begin(), nums.end());
        map<int,int> count_tbl;
        for(int i = 0; i <= nums.size(); i++){
            if(count_tbl[nums[i]] >= 2){
                cout << "erase " << nums[i] <<endl;
                nums.erase(nums.begin() + i);
            }
            else 
                count_tbl[nums[i]]++;      
        }

        //backtrack(nums, ans, cur_vec, st_vec, 0);
        
        return ans;
    }
    
    void backtrack(vector<int> &nums, vector<vector<int>> &ans, vector<int> cur_vec, vector<set<int>> &st_vec, int index){
        //cout << index;
        if(cur_vec.size() == 3){
            if(cur_vec[0] + cur_vec[1] + cur_vec[2] == 0){
                set<int> temp_st;
                temp_st.insert(cur_vec[0]);
                temp_st.insert(cur_vec[1]);
                temp_st.insert(cur_vec[2]);
                for(int i = 0; i < st_vec.size(); i++)
                {
                    if(st_vec[i] == temp_st)
                        return;
                }
                st_vec.push_back(temp_st);
                ans.push_back(cur_vec);
                return;
            }
            else{
                return;
            }
        }
        
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i-1] == nums[i]) continue;
            cur_vec.push_back(nums[i]);
            //cout << index;
            backtrack(nums, ans, cur_vec, st_vec, i + 1);
            cur_vec.pop_back();
        }
    }
};