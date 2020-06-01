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
public:
    int kthSmallest(TreeNode* root, int k) {
        return kths(root, k);
    }
    
    int kths(TreeNode *root, int &k){
        if(root == NULL)
            return -1;
        int val = kths(root->left, k);
        if(k == 0) return val;
        if(--k == 0) 
            return root->val;
        return kths(root->right,k);
    }
};