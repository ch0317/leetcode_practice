/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode * convertToBST(vector<int> &nums, int start_index, int end_index){
        TreeNode *root = NULL;
        if(start_index > end_index){
            return NULL;
        }
        
        root = new TreeNode;
        int mid = start_index + (end_index - start_index)/2;
        root->val = nums[mid];
        root->right = convertToBST(nums, mid + 1, end_index);
        root->left = convertToBST(nums, start_index, mid - 1);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convertToBST(nums, 0, nums.size() - 1);
    }
    
};