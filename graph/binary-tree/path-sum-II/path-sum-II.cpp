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
        vector<vector<int>> calculateSum(TreeNode* root, int targetSum, int currentSum, vector<int> currentPath, vector<vector<int>>& validPaths) {
            currentSum += root->val;
            currentPath.push_back(root->val);
            if (root->left == NULL && root->right == NULL && currentSum == targetSum) {
                validPaths.push_back(currentPath);
                return validPaths;
            }
            if (root->left != NULL)
                calculateSum(root->left, targetSum, currentSum, currentPath, validPaths);
            if (root->right != NULL)
                calculateSum(root->right, targetSum, currentSum, currentPath, validPaths);
    
            return validPaths;
        }
    
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            if (root == NULL)
                return {};
            
            vector<vector<int>> result;
            return calculateSum(root, targetSum, 0, {}, result);
        }
    };
