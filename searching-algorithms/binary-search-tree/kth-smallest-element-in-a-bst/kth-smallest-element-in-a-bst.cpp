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
    private:
        int count = 0;
        int minVal = 0;
    
        void getkthSmallest(TreeNode* root, int k) {
            if (root == nullptr)
                return ;
            
            getkthSmallest(root->left, k);
            
            count++;
            if (count == k) {
                minVal = root->val;
                return ;
            }
    
            getkthSmallest(root->right, k);
        }
    
    public:
        int kthSmallest(TreeNode* root, int k) {
            if (root == nullptr)
                return minVal;
            
            getkthSmallest(root, k);
            return minVal;
        }
    };
    