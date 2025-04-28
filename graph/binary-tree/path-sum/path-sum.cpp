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
        bool validPath(TreeNode* root, int curSum, int targetSum) {
            if (root == nullptr)
                return false;
            
            if (root->left == nullptr && root->right == nullptr && curSum + root->val == targetSum)
                return true;
            
            if (validPath(root->left, curSum + root->val, targetSum))
                return true;
    
            if (validPath(root->right, curSum + root->val, targetSum))
                return true;
            
            return false;
        }
    
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (root == nullptr)
                return false;
            
            return validPath(root, 0, targetSum);
        }
    };
    