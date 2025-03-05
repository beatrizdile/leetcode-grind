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
        bool calculateSum(TreeNode* root, int targetSum, int currentSum) {
            if (root == NULL)
                return false;
            
            currentSum += root->val;
            if (currentSum == targetSum && root->left == NULL && root->right == NULL)
                return true;
            
            return calculateSum(root->left, targetSum, currentSum) || calculateSum(root->right, targetSum, currentSum);
        }
    
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (root == NULL)
                return false;
    
            return calculateSum(root, targetSum, 0);
        }
    };
    