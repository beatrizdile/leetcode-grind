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
        int getMaxDepth(TreeNode* root) {
            if (root == NULL)
                return 0;
    
            int leftSum = 0;
            if (root->left != NULL)
                leftSum = getMaxDepth(root->left);
    
            int rightSum = 0;
            if (root->right != NULL)
                rightSum = getMaxDepth(root->right);
    
            return 1 + max(leftSum, rightSum);
        }
    
        int maxDepth(TreeNode* root) {
            if (root == NULL)
                return 0;
    
            return getMaxDepth(root);
        }
    };
