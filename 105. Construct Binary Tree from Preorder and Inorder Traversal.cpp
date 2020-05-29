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
    TreeNode* buildTree(int preStart, int instart,int inend, vector<int>& preorder, vector<int>& inorder){
        if(preStart >= preorder.size() || instart > inend)
            return NULL;
        
        TreeNode *T = new TreeNode;
        int root_val = preorder[preStart];
        T->val = root_val;
        int root_pos = 0;
        
        for(int i = 0; i < inorder.size(); i++)
        {
            if(root_val == inorder[i])
                root_pos = i;
        }
        
        T->left = buildTree(preStart + 1, instart, root_pos - 1, preorder, inorder );
        T->right = buildTree(preStart + 1 + root_pos - instart, root_pos + 1, inend, preorder, inorder);
        return T;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return buildTree(0, 0, inorder.size() - 1, preorder, inorder);
    }
};