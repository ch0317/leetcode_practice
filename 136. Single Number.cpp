class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i+=2)
        {
            if(nums[i] != nums[i+1])
            {
                if(i == 0)
                    return nums[0];
                else
                    return nums[i];
            }
        }
        
        return nums[nums.size() - 1];
    }
};