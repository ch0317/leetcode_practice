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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        deque<TreeNode*> q;
        int zigzag_flag = 0;
        q.push_back(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            cout << "size: " <<size<<endl;
            for(int i = 0; i < size; i++){
                TreeNode *r; 
                r = q.front();
                q.pop_front();
                
                if(r == NULL) continue;
                
                int index = zigzag_flag ? size - 1 - i : i;
                cout << index <<endl;
                temp[index] = r->val;
                if(r->left != NULL) q.push_back(r->left);
                if(r->right != NULL) q.push_back(r->right);
            }
            
            ans.push_back(temp);
            zigzag_flag = !zigzag_flag;
        }
        
        return ans;
    }
};