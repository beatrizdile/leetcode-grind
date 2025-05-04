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
    
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.empty() || inorder.empty())
                return nullptr;
            
            TreeNode* root = new TreeNode(preorder[0]);
            auto it = find(inorder.begin(), inorder.end(), preorder[0]);
            int mid = distance(inorder.begin(), it);
    
            vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + mid + 1);
            vector<int> inorderLeft(inorder.begin(), inorder.begin() + mid);
            root->left = buildTree(preorderLeft, inorderLeft);
    
            vector<int> preorderRight(preorder.begin() + 1 + mid, preorder.end());
            vector<int> inorderRight(inorder.begin() + mid + 1, inorder.end());
            root->right = buildTree(preorderRight, inorderRight);
    
            return root;
        }
    };
    