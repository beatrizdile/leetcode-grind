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
        void inorder(TreeNode* root, int count, int& minPath) {
            if (root == nullptr)
                return ;
            
            if (root->left != nullptr)
                inorder(root->left, count + 1, minPath);
            
            if (root->right != nullptr)
                inorder(root->right, count + 1, minPath);
            
            if (root->left == nullptr && root->right == nullptr) {
                if (minPath == 0)
                    minPath = count;
                else
                    minPath = min(minPath, count);
            }
    
        }
    
        int minDepth(TreeNode* root) {
            int minPath = 0;
            inorder(root, 1, minPath);
            return minPath;
        }
    };
    