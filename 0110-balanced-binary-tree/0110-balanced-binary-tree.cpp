/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return 1;
        int lh=findHeight(root->left);
        int rh=findHeight(root->right);
        if(abs(lh-rh)<=1){
            if(isBalanced(root->left) && isBalanced(root->right)){
                return true;
            }
        }
        return 0;
    }
};