class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        make_heap(nums.begin(),nums.end());
        for(int i = 0; i < k; i++){
            pop_heap(nums.begin(),nums.end());
            res = nums.back();
            nums.pop_back();
        }

        return res;
    }
};