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
        TreeNode* getMinNode(TreeNode* root) {
            while (root->left != nullptr)
                root = root->left;
            
            return root;
        }
    
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == nullptr)
                return nullptr;
    
            if (root->val > key)
                root->left = deleteNode(root->left, key);
            else if (root->val < key)
                root->right = deleteNode(root->right, key);
            else {
                if (root->left == nullptr)
                    return root->right;
                if (root->right == nullptr)
                    return root->left;
                else {
                    TreeNode* minNode = getMinNode(root->right);
                    root->val = minNode->val;
                    root->right = deleteNode(root->right, minNode->val);
                }
            }
    
            return root;
        }
    };
    