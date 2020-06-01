class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_product(nums.size());
        vector<int> right_product(nums.size());
        int product = 1;
        left_product[0] = 1;
        right_product[nums.size() - 1] = 1;
        vector<int> ans(nums.size());
        
        for(int i = 1; i < nums.size(); i++)
        {
            product *= nums[i - 1];
            left_product[i] = product;
        }
        
        product = 1;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            product *= nums[i + 1];
            right_product[i] = product;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            ans[i] = left_product[i] * right_product[i];
        }
        
        return ans;
    }
};