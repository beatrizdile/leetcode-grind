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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> result;
            queue<TreeNode*> treeQueue;
    
            if (root != nullptr)
                treeQueue.push(root);
    
            while (!treeQueue.empty()) {
                vector<int> level;
                int length = treeQueue.size();
                for (int i = 0; i < length; i++) {
                    TreeNode* cur = treeQueue.front();
                    level.push_back(cur->val);
                    treeQueue.pop();
                    cout << cur->val << endl;
                    if (cur->left != nullptr)
                        treeQueue.push(cur->left);
                    if (cur->right != nullptr)
                        treeQueue.push(cur->right);
                }
    
                result.push_back(level);
            }
    
            return result;
        }
    };
