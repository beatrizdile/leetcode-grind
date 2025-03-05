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
        vector<string> getPaths(TreeNode* root, string currentStr, vector<string>& result) {
            currentStr += to_string(root->val) + "->";
            if (root->left == NULL && root->right == NULL)
                result.push_back(currentStr.substr(0, currentStr.size() -2));
            if (root->left != NULL)
                getPaths(root->left, currentStr, result);
            if (root->right != NULL)
                getPaths(root->right, currentStr, result);
            
            return result;
        }
    
        vector<string> binaryTreePaths(TreeNode* root) {
            if (root == NULL)
                return {};
    
            vector<string> result;
            string currentStr;
            return getPaths(root, currentStr, result);
        }
    };
    