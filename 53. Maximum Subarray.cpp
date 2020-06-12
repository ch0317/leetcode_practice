class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> MaxarrayEnd(nums.size());
        int sum = nums[0];
        MaxarrayEnd[0] = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i != 0) MaxarrayEnd[i] = max(nums[i], MaxarrayEnd[i - 1] + nums[i]);
            //cout << MaxarrayEnd[i] << endl;
            if(sum < MaxarrayEnd[i]) sum = MaxarrayEnd[i];
        }
        
        return sum;
    }
};