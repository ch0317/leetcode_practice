/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *ans;
    bool recurseTree(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return false;
        int mid = (root->val == p->val || root->val == q->val) ? 1 : 0;
        int left = recurseTree(root->left, p, q) ? 1 : 0;
        int right = recurseTree(root->right, p, q) ? 1 : 0;
        
        if(mid + left + right >= 2){
            ans = root;
        }
        
        return (mid + left + right > 0);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        recurseTree(root,p,q);
        return ans;
    }
};